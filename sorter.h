#ifndef ONEGIN_SORTER_H
#define ONEGIN_SORTER_H

#include <stdio.h>
#include <string.h>

#include "globals.h"

/*!
 * @brief Biggest len of two strings
 * @param [in] len1 len of first string(accepted by strlen())
 * @param len2 len of second string(accepted by strlen())
 * @return
 */
size_t min_len (size_t len1 = 0, size_t len2 = 0);
/*!
 * @brief compare two strings by comparison letters
 * @param [in] str1 string to compare
 * @param [in] str2 string to compare
 * @return 1 if str1 > str2, 0 if str1 = str2, -1 if str2 > str1
 */
int rev_comparsion (const char* str1, size_t len1, const char* str2, size_t len2);
/*!
 * @brief String sorter, uses Hoar`s sort algorithm (quicksort), sorts by ends of strings
 * @param [in] Pointer massive of pointers to strings
 * @param [in] s_elem_fix position of element from which sort starts
 * @param [in] e_elem_fix position of element which end sort
 * @return 0, or ERROR in cause of error
 */
int RevQSorter(text *strings, int left, int right);
/*!
 * @brief Function checks char val is letter
 * @param [in] val symbol for check
 * @return 1 if val is letter, 0 in other case
 */
int is_letter(char val);
/*!
 * @brief leads letters to lower
 * @warning works correctly only with letters, in cause not letter return -1
 * @param [in] val input letter
 * @return letter in lower case, if try to make lower not letter -1
 */
char lower(char val);
/*!
 * @brief Function seek in str non space symbol from position start and return length to this symbol
 * @warning in some cases function return EMPTY(defined in globals.h), if use without project, please define it.
 * @param [in] str pointer to string
 * @param [in] start start position from where we will see non space symbol
 * @param [in] end end of string (string length) if function can`t find non space symbol
 * @return shift - length from start to first non space symbol, if no letters from start to end return EMPTY
 */
int comp_letter(const char* str, int start, int end);

#endif //ONEGIN_SORTER_H
