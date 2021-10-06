#include "qsort_cmp.h"

size_t minim_len (size_t len1, size_t len2) {
    return (len1 >= len2)? len2:len1;
}

int is_letters(char val) {
    if ((val >= 'a' && val <= 'z') || (val >= 'A' && val <= 'Z')) {
        return 1;
    }
    else {
        return 0;
    }
}
char to_lower(char val) {
    if (val >= 'a' && val <= 'z') {
        return val;
    }
    else if (val >= 'A' && val <= 'Z') {
        return (char)(val + ('a' - 'A'));
    }
    else {
        fprintf(stderr, "lower(): You trying to make lower not letter.\n");
        return -1;
    }
}

int comp_letters(const char* str, int start, int end) {
    for (int shift = 0; shift + start < end; shift++) {
        if (is_letters(str[start + shift])) {
            return shift;
        }
    }
    return EMPTY;
}


int compare(const void* struct1, const void* struct2) {
    char* str1 = ((text *)struct1)->string;
    char* str2 = ((text*)struct2)->string;
    size_t length = minim_len(((text*)struct1)->length, ((text*)struct2)->length);

    int result = 0;

    int shift1 = 0;
    int shift2 = 0;

    for (int i = 0; i < length; i++) {
        shift1 = comp_letters(str1, i, ((text*)struct1)->length);
        shift2 = comp_letters(str2, i, ((text*)struct2)->length);

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

        if (to_lower(str1[i + shift1]) > to_lower(str2[i + shift2])) {
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
