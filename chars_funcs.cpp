#include "chars_funcs.h"


int puts(const char *out) {
    if (out == NULL) {
        return NULL;
    }
    int i = 0;
    while (out[i] != '\0') {
        if (putchar(out[i]) == EOF) {
            return EOF;
        }
        i++;
    }
    putchar('\n');
    return i;
}

size_t strlen(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t cont = 0;

    while (str[cont] != '\0') {
        cont++;
    }

    return cont;
}

char strchr(const char *str, int ch) {
    if (str == NULL) {
        return NULL;
    }

    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ch) {
            return str[i];
        }

        i++;
    }

    return NULL;
}

char *strcpy(char *dst, const char *src) {
    if (dst == NULL || src == NULL || dst == src) {
        return NULL;
    }

    int i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }

    return dst;
}

char *strncpy(char *dst, const char *src, size_t len) {
    if (dst == NULL || src == NULL || dst == src) {
        return NULL;
    }

    size_t i = 0;

    while ((src[i] != '\0') && (i <= len)) {
        dst[i] = src[i];
        i++;
    }

    return dst;
}

char *strcat(char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL || str1 == str2) {
        return NULL;
    }

    size_t len1 = strlen(str1);

    for (size_t k = 0; k < strlen(str2); k++) {
        str1[len1 + k] = str2[k];
    }

    if (str1[len1 + strlen(str2)] != '\0') {
        str1[len1 + strlen(str2)] = '\0';
    }
    return str1;
}

size_t LenMin(size_t val1, size_t val2) {
    return (val1 >= val2) ? val2:val1;
}

char * strncat(char *str1, const char *str2, size_t num) {
    if (str1 == NULL || str2 == NULL || str1 == str2) {
        return NULL;
    }

    size_t len1 = strlen(str1);
    size_t min_len = LenMin(strlen(str2), num);

    for (size_t k = 0; k < min_len; k++) {
        str1[len1 + k] = str2[k];
    }

    if (str1[len1 + strlen(str2)] != '\0') {
        str1[len1 + strlen(str2)] = '\0';
    }

    return str1;
}

char *fgets(char *str, int num, FILE *stream) {
    if (str == NULL || stream == NULL) {
        return NULL;
    }

    int buf = 0;
    int i = 0;
    int len = strlen(str);

    while (( buf = getc(stream)) != EOF && i <= num) {
        str[len + i] = buf;
        i++;

        if (buf == '\n') {
            break;
        }
    }
    str[len + i] = '\0';

    return str;
}


char *strdup (const char *src) {
    if (src == NULL) {
        return NULL;
    }
    //buf = (char*)malloc(sizeof(char) + 1);
    char *buf = (char*) calloc (strlen (src) + 1, sizeof (char));//make test about короче я не знаю как написать, проверить выделение памяти

    strcpy (buf, src);

    return buf;
}