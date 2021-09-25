
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
        return ERROR;
    }

    int access = ERROR;
    if (operation_type == 'r') {access = O_RDONLY;}
    else if (operation_type == 'w') {access = O_WRONLY;}
    else {return ERROR;}

    int file_handle = open(filename, access);

    return file_handle;

}

size_t strings_sep(char* buffer, size_t buf_sz) {

    int i = 0;
    size_t string_num = 0;
    while (i < buf_sz) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
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

int struct_fill(text *strings, size_t string_num, char* buffer, size_t buffer_size) {
    if (strings == NULL || buffer == NULL) {
        return ERROR;
    }

    size_t string_pos = 0;
    size_t buffer_pos = 0;

    char* pointer = buffer;
    size_t length = 0;

    while ((string_pos <= string_num) && (buffer_pos < buffer_size)) {
        if (buffer[buffer_pos] == '\0') {

            strings[string_pos].string = pointer;
            strings[string_pos].length = length;
            string_pos++;

            pointer = buffer + (buffer_pos + 1);
            length = 0;
        }

        buffer_pos++;
        length++;

    }

    return 0;
}

int read_data(int file_handle, void* buffer, size_t f_size) {
    if (file_handle == -1 || buffer == NULL) {
        return ERROR;
    }

    printf("%d\n", read(file_handle, buffer, f_size));
    if (*((char*)buffer + f_size - 1) != '\n') {
        *((char*)buffer + f_size - 1) = '\n';
    }
    return 0;
}

int file_close(int file_handle) {
    if (file_handle == -1) {
        return ERROR;
    }

    return close(file_handle);
}

