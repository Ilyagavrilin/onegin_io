
#ifndef ONEGIN_IO_FILES_FUNCS_H
#define ONEGIN_IO_FILES_FUNCS_H
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <assert.h>
#include <stdio.h>

#include "globals.h"
#include "qsort_cmp.h"


/*!
 * @brief find length of file in bytes, using stat lib
 * @param filename name of file
 * @return size in bytes
 */
size_t len_finder(char *filename);

/*!
 * @brief allocate memory for buffer
 * @param file_sz size of needed buffer in bytes
 * @return void pointer to allocated place in memory
 */
void* mem_aloc(size_t file_sz);

/*!
 * @brief opens  file with non buffer library(io.h)
 * @param filename name of file
 * @param operation_type operation type like 'r'(read) or 'w'(write)
 * @return pointer to opened file
 */
int file_open(const char* filename, char operation_type);

/*!
 * @brief separate and count strings by '\\n', and change '\\r' to ' '
 * @param buffer pointer to buffer with strings to separate
 * @param buf_sz size of this buffer
 * @return number of strings
 */
size_t strings_sep(char* buffer, size_t buf_sz);

/*!
 * @brief initialize a struct for strings
 * @param string_num number of strings
 * @return pointer to initialized struct for string_num elements
 */
text* struct_initialize(size_t string_num);

/*!
 * @brief fill the struct with pointer to strings starts, and lengths of strings
 * @param strings pointer to struct with needed margins
 * @param string_num number of strings
 * @param buffer pointer to buffer with strings
 * @param buffer_size size of buffer
 * @return 0 if process ended right, ERROR in other cases
 */
ERORS struct_fill(text *strings, size_t string_num, char* buffer, size_t buffer_size);

/*!
 * @brief reads letters from input file
 * @param file_handle handle to input file
 * @param buffer buffer for writing
 * @param f_size size of this buffer
 * @return 0 if is process ended right, ERROR in other cases
 */
ERORS read_data(int file_handle, void* buffer, size_t f_size);
/*!
 * @brief closes previously opened file
 * @param file_handle handle to file
 * @return result of file closing
 */
int file_close(int file_handle);
/*!
 * @brief writes strings to output file
 * @param file_handle handle to output file
 * @param strings struct with pointers to strings
 * @param number_strings number of strings in struct
 * @return one of ERRORS, or OK
 */
ERORS write_data(int file_handle, text *strings, size_t number_strings);
/*!
 * @brief cleans dynamic allocated memory
 * @param buffer pointer for buffer to cleaning
 * @return 0
 */
int Clean(char* buffer);
//function to chose should we print the string with number string_pos
int is_str_empty(text *strings, size_t string_pos);

#endif //ONEGIN_IO_FILES_FUNCS_H
