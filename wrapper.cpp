#include "wrapper.h"

int MainWrapper() {
    const char * write_fname = "C:/Users/gavri/CLionProjects/onegin_indexed/write.txt";
    const char* read_fname = "C:/Users/gavri/CLionProjects/onegin_indexed/get.txt";

    size_t f_size = len_finder((char*)read_fname);
    int f_handle_read = file_open(read_fname, 'r');

    char* buffer = (char* ) mem_aloc(f_size);
    read_data(f_handle_read, buffer, f_size);
    size_t string_num = strings_sep(buffer, f_size);
    file_close(f_handle_read);

    text *strings = struct_initialize(string_num);
    struct_fill(strings, string_num, buffer, f_size);

    qsort(strings, string_num, sizeof(text), compare);

    int file_handle_write = file_open(write_fname, 'w');
    write_data(file_handle_write, strings, string_num);
    file_close(file_handle_write);




    return 0;
}