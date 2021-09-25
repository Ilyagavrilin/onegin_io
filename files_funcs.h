
#ifndef ONEGIN_FILES_FUNCS_H
#define ONEGIN_FILES_FUNCS_H

#include <stdio.h>
#include <assert.h>
#include <string.h>


#include "globals.h"
#include "sorter.h"

//---------------------------------------
/*!
 * @brief Function to provide opening, closing files.
 * @param [in] fname accepts pointer type "FILE*"
 * @param [in] name accepts string (char*), which includes full path to needed .txt file
 * @param [in] work_type regulate in which case will work function ('c' - close file, 'o' - open file)
 * @param [in] op_type type of operation on file (
 * 'r' - read executable file,
 * 'w' - write data to file(if _txt_name_.txt doesn`t exist, create new file),
 * 'a' - add data to existing, after last string
 * @return pointer to file (pointer type: FILE*), if error returns NULL
 */
FILE *FileComb (FILE *fname = NULL, char *name = NULL, char work_type = 'c', char op_type = 'r');
/*!
 * @brief function used to open files, exist like part of function FileComb()
 * @param [in] fname accepts pointer type "FILE*"
 * @param [in] name accepts string (char*), which includes full path to needed .txt file
 * @param [in] op_type type of operation on file (
 * 'r' - read executable file,
 * 'w' - write data to file(if _txt_name_.txt doesn`t exist, create new file),
 * 'a' - add data to existing, after last string
 * @return pointer to file (pointer type: FILE*), if error returns NULL
 */
FILE *FileOpen (FILE *fname = NULL, char *name = NULL, char op_type = 'r');
/*!
 * @brief Function to provide closing opened files
 * @param [in] fname accepts pointer type "FILE*"
 * @return 0 if function closed file correctly, else returns ERROR(defined in globals.h)
 */
int FileClose (FILE *fname = NULL);
/*!
 * @brief Function Which opens file read strings from them, sorts, and write to new file
 * @return 0 if process finished correctly, ERROR(defined in globals.h) if something wrong
 */
int ReWriter ();
/*!
 * @brief Reads information from FILE* stream make string massive, put it to dynamic memory
 * and write pointer to string in Pointer[]
 * @param [in] stream pointer type "FILE*" to file with text
 * @param [in,out] Pointer massive of Pointers to strings
 * @return number of read strings, in cause of error returns ERROR(defined in globals.h)
 */
int read(FILE *stream, char* Pointer[]);
/*!
 * @brief Writes sorted strings to FILE* out
 * @param [in] out pointer type "FILE*" to file for writing sorted strings
 * @param [in] Pointer massive with pointers to strings
 * @param [in] MAX maximum length of string
 * @return number of wrote strings, ERROR in cause of error
 */
int write(FILE *out, char* Pointer[], size_t MAX);
/*!
 * @brief Cleans dedicated dynamic memory
 * @param [in] Pointer massive with pointers to strings
 * @return number of cleaned cells(strings)
 */
int clean(char* Pointer[]);
/*!
 * @brief Formate string by adding '/n' and '/0' symbols if they needed
 * @param [in] str1 pointer for string to format
 * @return 0 if process finished correctly, ERROR in cause error
 */
int str_formatter(char *str1);
//---------------------------------------

#endif //ONEGIN_FILES_FUNCS_H
