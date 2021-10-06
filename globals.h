#ifndef ONEGIN_GLOBALS_H
#define ONEGIN_GLOBALS_H
#include <stdio.h>

enum LOGIC {
    TRUE = 1,
    FALSE = 0,
    EMPTY = -8,
};
enum ERORS {
    OK,
    ERROR,
    NULL_PTR,
    WRONG_ANS,


};


typedef struct {
    char* string;
    size_t length;
} text;


#endif //ONEGIN_GLOBALS_H
