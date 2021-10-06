
#include "io_files_funcs.h"

size_t len_finder(char *filename) {
    struct stat info = {0};
    if (stat(filename, &info) != 0) {
        return 0;
    }

    return info.st_size;
}

void* mem_aloc(size_t file_sz) {
    void* location = NULL;
    location = calloc(file_sz + 1, sizeof(char));
    assert(location != NULL);
    return location;
}

int file_open(const char* filename, char operation_type) {
    if (filename == NULL) {
        return NULL_PTR;
    }

    int access = NULL_PTR;
    if (operation_type == 'r') {access = O_RDONLY;}
    else if (operation_type == 'w') {access = O_WRONLY;}
    else {return WRONG_ANS;}

    int file_handle = open(filename, access);

    return file_handle;

}

size_t strings_sep(char* buffer, size_t buf_sz) {

    int i = 0;
    size_t string_num = 0;
    while (i < buf_sz) {
        if (buffer[i] == '\n') {
            string_num++;
        }
        else if (buffer[i] == '\r') {
            buffer[i] = ' ';
        }

        i++;
    }

    return string_num;
}

text* struct_initialize(size_t string_num) {
    text* strings = (text*) calloc(string_num, sizeof(text));
    if (strings == NULL) {
        return NULL;
    }

    return strings;
}

ERORS struct_fill(text *strings, size_t string_num, char* buffer, size_t buffer_size) {
    if (strings == NULL || buffer == NULL) {
        return NULL_PTR;
    }

    size_t string_pos = 0;
    size_t buffer_pos = 0;

    char* pointer = buffer;
    size_t length = 0;

    while ((string_pos <= string_num) && (buffer_pos < buffer_size)) {
        if (buffer[buffer_pos] == '\n') {

            strings[string_pos].string = pointer;
            strings[string_pos].length = length;
            string_pos++;

            pointer = buffer + (buffer_pos + 1);
            buffer_pos++;
            length = 0;
        }

        else {
            buffer_pos++;
            length++;
        }
    }

    return OK;
}

ERORS read_data(int file_handle, void* buffer, size_t f_size) {
    if (file_handle == -1 || buffer == NULL) {
        if (file_handle == -1) {
            fprintf(stderr, "func read_data(): you try read data from empty file handle.\n");
        }
        else {
            fprintf(stderr, "func read_data(): you try put info from file to empty buffer.\n");
        }
        return NULL_PTR;
    }

    assert(read(file_handle, buffer, f_size) != -1);
    if (*((char*)buffer + f_size - 1) != '\n') {
        *((char*)buffer + f_size - 1) = '\n';
    }
    return OK;
}

ERORS write_data(int file_handle, text *strings, size_t number_strings) {
    //I use NULL with f_handle because compiler forbids comparing int and nillptr_t(it`s like vpid*)
    if ((file_handle == NULL) || strings == nullptr) {
        fprintf(stderr, "Func write_data(): you try use null handle");
        return NULL_PTR;
    }
    for (int string_num = 0; string_num < number_strings; string_num++) {
        if (is_str_empty(strings, string_num) == 1) {continue;}
        assert(write(file_handle, strings[string_num].string, strings[string_num].length + 1) != -1);
    }

    return OK;
}

int file_close(int file_handle) {
    if (file_handle == -1) {
        return ERROR;
    }
    return close(file_handle);
}

int Clean(char* buffer) {
    free(buffer);

    return 0;
}

int is_str_empty(text *strings, size_t string_pos) {
    if (comp_letters(strings[string_pos].string, 0, strings[string_pos].length) == EMPTY) {
        return 1;
    }
    else {
        return 0;
    }
}