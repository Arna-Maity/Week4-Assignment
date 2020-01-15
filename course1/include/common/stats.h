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
 * @file stats.h
 * @brief This file contains the function declarations
 *        to be implemented in the stats.c file. The 
 *        following statistical functions are implemented
 *        in this project:
 *        1. print_statistics
 *        2. print_array
 *        3. find_mean
 *        4. find_median
 *        5. find_maximum
 *        6. find_minimum
 *        7. sort_array
 *
 * @author Arna Maity
 * @date 03/01/2020
 */

#ifndef __STATS_H__
#define __STATS_H__

void print_statistics(unsigned char* arr,unsigned int len);
/**
 * @brief This function print out the results of
 *        statistical analysis in a well formatted
 *        manner to the standard output console.
 *
 * @param arr pointer to 1st element of the array
 *            to be analysed.
 * @param len length of the specified array.
 *
 * @return The above function doesn't return
 *         anything it just prints the values 
 *         on screen.
 */

void print_array(unsigned char* arr, unsigned int len);
/**
 * @brief This function just prints the input array
 *        in a well formatted manner to the standard
 *        output console.
 *
 * @param arr pointer to 1st element of the array
 *            to be analysed.
 * @param len length of the specified array.
 *
 * @return The above function doesn't return
 *         anything it just prints the values 
 *         on screen.
 */

int find_mean(unsigned char* arr,unsigned int len);
 /**
 * @brief The function finds the mean value of the 
 *        numbers of the input array and returns
 *        the result to the caller function.
 *
 * @param arr pointer to 1st element of the array
 *            to be analysed.
 * @param len length of the specified array.
 *
 * @return This function return the mean value
 *         of the input array.
 */

int find_median(unsigned char* arr,unsigned int len);
 /**
 * @brief The function finds the median value of the 
 *        numbers of the input array and returns
 *        the result to the caller function.
 *
 * @param arr pointer to 1st element of the array
 *            to be analysed.
 * @param len length of the specified array.
 *
 * @return This function return the median value
 *         of the input array.
 */

 int find_maximum(unsigned char* arr,unsigned int len);
 /**
 * @brief The function finds the maximum value of the 
 *        numbers of the input array and returns
 *        the result to the caller function.
 *
 * @param arr pointer to 1st element of the array
 *            to be analysed.
 * @param len length of the specified array.
 *
 * @return This function return the maximum value
 *         of the input array.
 */

 int find_minimum(unsigned char* arr,unsigned int len);
 /**
 * @brief The function finds the minimum value of the 
 *        numbers of the input array and returns
 *        the result to the caller function.
 *
 * @param arr pointer to 1st element of the array
 *            to be analysed.
 * @param len length of the specified array.
 *
 * @return This function return the minimum value
 *         of the input array.
 */

void sort_array(unsigned char* arr, unsigned int len);
 /**
 * @brief This function sorts the input array
 *        in descending order.
 *
 * @param arr pointer to 1st element of the array
 *            to be analysed.
 * @param len length of the specified array.
 *
 * @return The above function doesn't return
 *         anything it just prints the values 
 *         on screen.
 */
 
#endif /* __STATS_H__ */
