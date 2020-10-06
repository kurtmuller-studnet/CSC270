/*
 * life.c
 *
 *  Created on: Sep 13, 2016
 *      Author: leune
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "life.h"

int main(int argc, char *argv[]) {
	
	FILE *dataFile;
	int line = 0;
	char input[BUFSIZE];

	dataFile = fopen("lifeinfo.txt", "r");

	int XSIZE, YSIZE, DEFAULTROUNDS;
	
	//If the file has an error when trying to read it, the program prints an error and ends
	if (dataFile == NULL){
		fprintf(stderr, "Unable to open %s.\n", "lifeinfo.txt");
		return 1;
	} // end if
	// Get the information from the file necessary for the program to run
	while(fgets(input, 512, dataFile)){
			line++;
			//Depending on the line of the txt file, it will be assigned accordingly
			switch (line){
				case 1:
					break;
				case 2:
					DEFAULTROUNDS = atoi(input);
					break;
				case 3:
					XSIZE = atoi(input);
					break;
				case 4:
					YSIZE = atoi(input);
					break;
			} // end switch
	} // end while

	fclose(dataFile);

	int board[XSIZE][YSIZE];
	int rounds = DEFAULTROUNDS;

	initBoard(XSIZE, YSIZE, board);
	// Using the locations that you have specified in the info file, it will be made alive
	int count = 0;
	int inputLen = strlen(input);

	while (count < inputLen){
		int tempx, tempy;
		
		//This assigns the coordinates to the proper value
		sscanf(input, "%d %d", &tempx, &tempy);
		board[tempx][tempy] = ALIVE;

		//This will get the length in the string from where the last coordinates were gotten
		char s[32];
		char t[32];
		int lenx = sprintf(s, "%d", tempx);
		int leny = sprintf(t, "%d", tempy);
		int twointlength = lenx + leny + 2;

		//Using the location of the last coordinates, that part is made into 
		//whitespaces to be able to select the next coordinates
		for (int k = 0; k < twointlength; k++){
			input[count + k] = ' ';
		}

		//Clear the chars used to find the length of the coordinate in the string
		memset(s, 0, 32);
		memset(t, 0, 32);		

		count += twointlength;
	} // end while

	printf("Playing %d rounds with a grid size of %d by %d.\n\n", rounds, XSIZE, YSIZE);
	for (int i=0; i<rounds; i++) {
		printf("Round: %d\n", i+1);
		printBoard(XSIZE, YSIZE, board);
		playRound(XSIZE, YSIZE, board);

		sleep(1);
	} // end for

	return 0;
} // end main

void initBoard(int XSIZE, int YSIZE, int a[][YSIZE]) {
    /* write this function */
	for (int i = 0; i < YSIZE; i++){
		for (int j = 0; j < XSIZE; j++){
			a[i][j] = DEAD;
		}
	}
}

void playRound(int XSIZE, int YSIZE, int a[][YSIZE]) {
	int tmpBoard[XSIZE][YSIZE];
	initBoard(XSIZE, YSIZE, tmpBoard);
	int n;
	// perform the algorithm on vBoard, but update tmpBoard
	// with the new state
	
	/* write this fragment */
		for (int i = 0; i < YSIZE; i++){
			for (int j = 0; j < XSIZE; j++){
				n = 0;
				n = neighbors(XSIZE, YSIZE, a, i, j);
				if(a[i][j] == ALIVE){
					if (n < 2){
						tmpBoard[i][j] = DEAD;
					}
					else if(n == 2 || n == 3){
						tmpBoard[i][j] = ALIVE;
					}
					else if(n > 3){
						tmpBoard[i][j] = DEAD;
					}
				}
				else if(a[i][j] == DEAD){
					if(n == 3){
						tmpBoard[i][j] = ALIVE;
					}
				}

		}
	}

    // copy tmpBoard over vBoard
	for (int y=0; y < YSIZE; y++) {
		for (int x=0; x < XSIZE; x++) {
			a[x][y] = tmpBoard[x][y];
		}
	}
}

int onBoard(int x, int y, int XSIZE, int YSIZE) {
	if (x < 0 || x >= XSIZE)
		return 0;
	else
		if (y < 0 || y >= YSIZE) return 0;
	else
		return 1;
}

int neighbors(int XSIZE, int YSIZE, int a[][YSIZE], int x, int y) {
	int n=0;

	int xp1 = x + 1;
	int xm1 = x - 1;
	int yp1 = y + 1;
	int ym1 = y - 1;

	if (onBoard(xm1, y, XSIZE, YSIZE) && a[xm1][y] == ALIVE) n++;
	if (onBoard(xm1, yp1, XSIZE, YSIZE) && a[xm1][yp1] == ALIVE) n++;
	if (onBoard(x, yp1, XSIZE, YSIZE) && a[x][yp1] == ALIVE) n++;
	if (onBoard(xp1, yp1, XSIZE, YSIZE) && a[xp1][yp1] == ALIVE) n++;
	if (onBoard(xp1, y, XSIZE, YSIZE) && a[xp1][y] == ALIVE) n++;
	if (onBoard(xp1, ym1, XSIZE, YSIZE) && a[xp1][ym1] == ALIVE) n++;
	if (onBoard(x, ym1, XSIZE, YSIZE) && a[x][ym1] == ALIVE) n++;
	if (onBoard(xm1, ym1, XSIZE, YSIZE) && a[xm1][ym1] == ALIVE) n++;

	return n;
}

void printBoard(int XSIZE, int YSIZE, int a[][YSIZE]) {
	/* write this fragment */
	for (int i = 0; i < YSIZE; i++){
		for (int j = 0; j < XSIZE; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}	
}
