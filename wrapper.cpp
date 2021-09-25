#include "wrapper.h"

int MainWrapper() {
    const char * write_fname = "C:/Users/gavri/CLionProjects/onegin_indexed/write.txt";
    const char* read_fname = "C:/Users/gavri/CLionProjects/onegin_indexed/get.txt";

    size_t f_size = len_finder((char*)read_fname);
    int f_handle = file_open(read_fname, 'r');

    char* buffer = (char* ) mem_aloc(f_size);
    read_data(f_handle, buffer, f_size);
    size_t string_num = strings_sep(buffer, f_size);

    text *strings = struct_initialize(string_num);
    struct_fill(strings, string_num, buffer, f_size);



    printf("%d\n", f_size);
    for (int i = 0; i < string_num; i++) {
        printf("%s", strings[i].string);
        printf(" %d\n", strings[i].length);
    }
    return 0;
}