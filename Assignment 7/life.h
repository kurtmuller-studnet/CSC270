/*
 * life.h
 *
 *  Created on: Sep 13, 2016
 *      Author: leune
 */

#ifndef LIFE_H_
#define LIFE_H_

#define ALIVE	1
#define	DEAD	0
#define BUFSIZE 512

// initialize the board to all dead cells
void initBoard(int XSIZE, int YSIZE, int a[][YSIZE]);

// play a round; updates the cells on the board
void playRound(int XSIZE, int YSIZE, int a[][YSIZE]);

// print the board
void printBoard(int XSIZE, int YSIZE, int a[][YSIZE]);

// determine the number of neighbors
int neighbors(int XSIZE, int YSIZE, int a[][YSIZE], int x, int y);

/* determine if the given coordinates are within bounds
 * returns 0 if the cell is out of bounds; returns 1 if
 * the cell is in bounds
 */
int onBoard(int x, int y, int XSIZE, int YSIZE);



#endif /* LIFE_H_ */