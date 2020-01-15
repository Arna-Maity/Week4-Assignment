/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief This file implements the statistical functions
 *        and uses them in a simple application to test
 *        their functionality.
 *
 * @author Arna Maity
 * @date 03/01/2020
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  int len = sizeof(test)/sizeof(test[0]);
  print_statistics(test,len);

}

void print_statistics(unsigned char* arr, unsigned int len)
{
  printf("\nInput Array: ");
  print_array(arr,len);
  printf("Median = %d\n",find_median(arr,len));
  printf("Mean = %d\n",find_mean(arr,len));
  printf("Maximum = %d\n",find_maximum(arr,len));
  printf("Minimum = %d\n",find_minimum(arr,len));
}

void print_array(unsigned char* arr, unsigned int len)
{
    for(char i=0;i<len;i++)
      printf(" %d",arr[i]);

    printf("\n");  
}

int find_median(unsigned char* arr, unsigned int len)
{
  if(!(len%2))
    return ((arr[len/2-1]+arr[len/2])/2);

  else
    return(arr[len/2]);
}

int find_mean(unsigned char* arr, unsigned int len)
{
  unsigned int sum = 0;
  for(int i=0;i<len;i++)
    sum = sum+arr[i];

  return (sum/len);
}

int find_maximum(unsigned char* arr, unsigned int len)
{
  sort_array(arr,len);
  return arr[0];
}

int find_minimum(unsigned char* arr, unsigned int len)
{
  sort_array(arr,len);
  return arr[len-1];
}

void sort_array(unsigned char* arr, unsigned int len)
{
  char tmp;
  for(char i=0;i<len;i++)
    for(char j=0;j<(len-i-1);j++)
      if(arr[j]<arr[j+1])
        {
          tmp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = tmp;
        }
}