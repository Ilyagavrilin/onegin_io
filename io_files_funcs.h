
#ifndef ONEGIN_IO_FILES_FUNCS_H
#define ONEGIN_IO_FILES_FUNCS_H
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <assert.h>

#include "globals.h"

size_t len_finder(char *filename);
void* mem_aloc(size_t file_sz);
int file_open(const char* filename, char operation_type);
size_t strings_sep(char* buffer, size_t buf_sz);
text* text_initialize(size_t string_num);
int read_data(int file_handle, void* buffer, size_t f_size);
int file_close(int file_handle);
#endif //ONEGIN_IO_FILES_FUNCS_H
