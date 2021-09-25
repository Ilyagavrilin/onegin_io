#ifndef ONEGIN_GLOBALS_H
#define ONEGIN_GLOBALS_H
#include <stdio.h>

enum LOGIC {
    TRUE = 1,
    FALSE = 0,
    EMPTY = -8,
};
enum ERORS {
    ERROR = -1,


};


typedef struct {
    char* string;
    int length;
} text;


#endif //ONEGIN_GLOBALS_H
