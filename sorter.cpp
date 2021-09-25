#include "sorter.h"


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


int comparsion (const char* str1, size_t len1, const char* str2, size_t len2) {
    size_t length = min_len(len1, len2);

    int result = 0;

    int shift1 = 0;
    int shift2 = 0;

    for (int i = 0; i < length; i++) {
        shift1 = comp_letter(str1, i, length);
        shift2 = comp_letter(str2, i, length);

        if (shift1 == EMPTY && shift2 == EMPTY) {
            result = 0;
            break;
        }
        else if (shift1 == EMPTY) {
            result = -1;
            break;
        }
        else if (shift2 == EMPTY) {
            result = 1;
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

    return result;
}
int cmp(text *strings, int num1,  int num2,  char sort_type) {
    if (sort_type == 's') {return comparsion(strings, num1, num2);}
    else if (return rev_comparsion(strings, num1, num2);)
}

int QSorter(text *strings, int left, int right)
{
    const char* pivot = strings[left].string;
    const int piv_length = strings[left].length;
    int left_fix = left;
    int right_fix = right;
    while (left < right)
    {
        while (comparsion(strings, pivot) >= 0 && (left < right))
            right--;
        if (left != right)
        {
            strings[left].string = strings[right].string;
            left++;
        }
        while (comparsion(strings[left].string, pivot) <= 0 && (left < right))
            left++;
        if (left != right)
        {
            strings[right].string = strings[left].string;
            right--;
        }
    }
    strings[left].string = pivot;
    int pivot_num = left;
    if (left_fix < pivot_num) {
        QSorter(strings, left_fix, pivot_num - 1);
    }
    if (right_fix > pivot_num) {
        QSorter(strings, pivot_num + 1, right_fix);
    }
    return 0;
}