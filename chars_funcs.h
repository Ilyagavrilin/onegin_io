#ifndef ONEGIN_CHARS_FUNCS_H
#define ONEGIN_CHARS_FUNCS_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

size_t LenMin(size_t val1, size_t val2);

int puts(const char *out);
size_t strlen(const char *str);
char strchr(const char *str, int ch = 0);
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t len = 0);
char *strcat(char *str1, const char *str2);
char * strncat(char *str1, const char *str2, size_t num = 0);
char *fgets(char *str, int num = 0, FILE *stream = NULL);
char *strdup(const char *src);


#endif //ONEGIN_CHARS_FUNCS_H
