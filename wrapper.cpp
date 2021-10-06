#include "wrapper.h"

int MainWrapper() {
    const char* separator = "/-------------------------------------\n";

    //names for files to work
    const char * write_fname = "C:/Users/gavri/CLionProjects/onegin_indexed/write.txt";
    const char* read_fname = "C:/Users/gavri/CLionProjects/onegin_indexed/get.txt";

    //open file and cout how many symbols in it
    size_t f_size = len_finder((char*)read_fname);
    int f_handle_read = file_open(read_fname, 'r');

    //initialize buffer for strings and fill it from file
    char* buffer = (char* ) mem_aloc(f_size);
    read_data(f_handle_read, buffer, f_size);
    //separate strings in buffer by \n and count they
    size_t string_num = strings_sep(buffer, f_size);
    //close file with source text
    file_close(f_handle_read);

    // initialize struct for strings and write pointers to strings starts
    text *strings = struct_initialize(string_num);
    struct_fill(strings, string_num, buffer, f_size);

    //sort strings using default functions
    qsort(strings, string_num, sizeof(text), compare);

    //write sorted strings to file
    int file_handle_write = file_open(write_fname, 'w');
    write_data(file_handle_write, strings, string_num);
    write(file_handle_write, separator, strlen(separator));

    //sort strings from endings and write sorted text
    RevQSorter(strings, 0, string_num - 1);
    write_data(file_handle_write, strings, string_num);
    write(file_handle_write, separator, strlen(separator));
    //write source text
    write(file_handle_write, buffer, f_size);
    Clean(buffer); //clean dynamic buffer and close file
    file_close(file_handle_write);

    return 0;
}