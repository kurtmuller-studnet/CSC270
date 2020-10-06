#include <stdio.h>

static int palindrom_func(int num);

int main(void)
{
  int i, k, max = 0;
  int num1, num2;

  //Goes through the numbers from 100 to 999 to find the maximum value for three digit numbers
  for(i = 100; i <= 999; i++){
    for(k = 100; k <= 999; k++){
      int multiplied_nums = i * k;
      //Pass the multiplied_nums in the palindrom_func
      if(palindrom_func(multiplied_nums) && multiplied_nums > max){
        max = multiplied_nums;
        num1 = i;
        num2 = k;
      }
    }
  }

  //Print the results
  printf("%u, %u, %u\n", num1, num2, max);

  return 0;
}

//Reverses the number passed through and is returned
int palindrom_func(int num){

  int reversed_num = 0;
  int temp = num;

  while(temp > 0){
    reversed_num = 10 * reversed_num + (temp % 10);
    temp = temp / 10;
  }

  return reversed_num == num;
}