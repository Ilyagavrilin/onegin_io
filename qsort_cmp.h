
#ifndef ONEGIN_QSORT_CMP_H
#define ONEGIN_QSORT_CMP_H

#include "globals.h"

size_t minim_len (size_t len1 = 0, size_t len2 = 0);

int is_letters(char val);

int comp_letters(const char* str, int start, int end);
int compare(const void* struct1, const void* struct2);


#endif //ONEGIN_QSORT_CMP_H
