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
int comparsion (text *strings, int position, const char *str2);
/*!
 * @brief String sorter, uses Hoar`s sort algorithm (quicksort)
 * @param [in] Pointer massive of pointers to strings
 * @param [in] s_elem_fix position of element from which sort starts
 * @param [in] e_elem_fix position of element which end sort
 * @return 0, or ERROR in cause of error
 */
int RevQSorter(text *strings, int left, int right);

int is_letter(char val);

int comp_letter(const char* str, int start, int end);

#endif //ONEGIN_SORTER_H
