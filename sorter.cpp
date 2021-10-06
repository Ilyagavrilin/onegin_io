#include "sorter.h"


size_t min_len (size_t len1, size_t len2) {
    return (len1 >= len2)? len2:len1;
}

int is_letter(char val) {
    if ((val >= 'a' && val <= 'z') || (val >= 'A' && val <= 'Z')) {
        return 1;
    }
    else {
        return 0;
    }
}

char lower(char val) {
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

int comp_letter(const char* str, int start, int end) {
    for (int shift = 0; start - shift > end; shift++) {
        if (is_letter(str[start - shift])) {
            return shift;
        }
    }
    return EMPTY;
}


int rev_comparsion (const char* str1, size_t len1, const char* str2, size_t len2) {
    size_t length = min_len(len1, len2);

    int result = 0;

    int shift1 = 0;
    int shift2 = 0;

    for (int i = 0; i < length; i++) {
        shift1 = comp_letter(str1, len1 - i, 0);
        shift2 = comp_letter(str2, len2 - i, 0);

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

        if (lower(str1[len1 - (i + shift1)]) > lower(str2[len2 - (i + shift2)])) {
            result = 1;
            break;
        }
        else if (lower(str1[len1 - (i + shift1)]) < lower(str2[len2 - (i + shift2)])) {
            result = -1;
            break;
        }
    }

    return result;
}

int RevQSorter(text *strings, int left, int right)
{
    const char* pivot = strings[left].string;
    const int piv_length = strings[left].length;
    int left_fix = left;
    int right_fix = right;
    while (left < right)
    {
        while (rev_comparsion(strings[right].string, strings[right].length, pivot, piv_length) >= 0 && (left < right))
            right--;
        if (left != right)
        {
            strings[left] = strings[right];
            left++;
        }
        while (rev_comparsion(strings[left].string, strings[left].length, pivot, piv_length) <= 0 && (left < right))
            left++;
        if (left != right)
        {
            strings[right] = strings[left];
            right--;
        }
    }
    strings[left].string = (char*) pivot;
    strings[left].length = piv_length;
    int pivot_num = left;
    if (left_fix < pivot_num) {
        RevQSorter(strings, left_fix, pivot_num - 1);
    }
    if (right_fix > pivot_num) {
        RevQSorter(strings, pivot_num + 1, right_fix);
    }
    return 0;
}