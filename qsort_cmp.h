
#ifndef ONEGIN_QSORT_CMP_H
#define ONEGIN_QSORT_CMP_H

#include "globals.h"

/*!
 * @brief function which returns minim of two size_t num
 * @param len1 len of first string
 * @param len2 len of second string
 * @return min of len1, len2
 */
size_t minim_len (size_t len1 = 0, size_t len2 = 0);
/*!
 * @brief checks if val is letter of latinic alphabet
 * @param val symbol to check
 * @return 1 if val is letter, 0 in other cases
 */
int is_letters(char val);
/*!
 * @brief make letter to lower case
 * @param val letter to change
 * @return char made lower
 */
char to_lower(char val);
/*!
 * @brief Function seek in str non space symbol from position start and return length to this symbol
 * @warning in some cases function return EMPTY(defined in globals.h), if use without project, please define it.
 * @param [in] str pointer to string
 * @param [in] start start position from where we will see non space symbol
 * @param [in] end end of string (string length) if function can`t find non space symbol
 * @return shift - length from start to first non space symbol, if no letters from start to end return EMPTY
 */
int comp_letters(const char* str, int start, int end);

/*!
 * @brief comparator function for standard qsort
 * @param [in] struct1
 * @param [in] struct2
 * @return 1 if struct2 < struct1, 0 if struct2 == struct1, -1 if struct2 > struct1 (compare by letters in strings)
 */
int compare(const void* struct1, const void* struct2);


#endif //ONEGIN_QSORT_CMP_H
