#include "qsort_cmp.h"

size_t min_len (size_t len1, size_t len2) {
    return (len1 >= len2)? len2:len1;
}

int is_letter(char val) {
    if (val == ' ' || val == ',' || val == '.' || val == '\t') {
        return 0;
    }
    else {
        return 1;
    }
}

int comp_letter(const char* str, int start, int end) {
    for (int shift = 0; shift + start < end; shift++) {
        if (is_letter(str[start + shift])) {
            return shift;
        }
    }
    return EMPTY;
}


int compare(const void* struct1, const void* struct2) {
    char* str1 = ((text *)struct1)->string;
    char* str2 = ((text*)struct2)->string;
    size_t length = min_len(((text*)struct1)->length, ((text*)struct2)->length);

    int result = 0;

    int shift1 = 0;
    int shift2 = 0;

    for (int i = 0; i < length; i++) {
        shift1 = comp_letter(str1, i, ((text*)struct1)->length);
        shift2 = comp_letter(str2, i, ((text*)struct2)->length);

        if (shift1 == EMPTY && shift2 == EMPTY) {
            result = 0;
            break;
        }
        else if (shift1 == EMPTY) {
            result = 1;
            break;
        }
        else if (shift2 == EMPTY) {
            result = -1;
            break;
        }

        if (str1[i + shift1] > str2[i + shift2]) {
            result = 1;
            break;
        }
        else if (str1[i + shift1] < str2[i + shift2]) {
            result = -1;
            break;
        }
    }

    if ((result == 0) && (((text*)struct1)->length != ((text*)struct2)->length)) {
        if (((text*)struct1)->length > ((text*)struct2)->length) {result = 1;}
        else {result = -1;}
    }

    return result;
}
