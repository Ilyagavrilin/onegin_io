#include "files_funcs.h"



int ReWriter () {
    /*FILE *fget = NULL;
    char name_get[] = "C:/Users/gavri/CLionProjects/onegin_indexed/get.txt";
    if ((fget = FileComb (fget, name_get, 'o', 'r')) == NULL) {
        printf("Error in opening file with text. \n");
        return ERROR;
    }

    struct text onegin = {};
    int string_num = 0;

    if ((string_num = read(fget, Pointer)) == ERROR) return ERROR;
    FileComb (fget, name_get, 'c', 'r');

    QSorter(Pointer, 0, string_num - 1);

    FILE *fwrite = NULL;
    char name_write[] = "C:/Users/gavri/CLionProjects/onegin_indexed/write.txt";
    if ((fwrite = FileComb (fwrite, name_write, 'o', 'w')) == NULL) {
        printf("Error in opening file with text. \n");
        return ERROR;
    }

    write(fwrite, Pointer, MAX_LINE);
    FileComb (fwrite, name_get, 'c', 'w');

    clean(Pointer);
    heheheh
    */
    struct text test[] = {"accc", 2, "abbbb", 2, "a aaaa", 2};
    QSorter(test, 0, 2);
    for (int i = 0; i < 3; i++) {
        printf("%s\n", test[i].string);
    }
    return 0;
}


FILE *FileComb (FILE *fname, char *name, char work_type, char op_type) {
    FILE *linker = NULL;

    if (work_type == 'o') {
        if ((linker = FileOpen (fname, name , op_type)) == NULL) {
            return NULL;
        }
        return linker;
    }
    else if (work_type == 'c') {
        if (FileClose (fname) == ERROR) {
            assert(!"File didn't closed.");
            return NULL;
        }
    }
    else {
        assert(NULL);
    }

    return NULL;
}
 FILE *FileOpen (FILE *fname, char *name, char op_type) {
    char operation[2] = "r";

    if (op_type == 'r' || op_type == 'w' || op_type == 'a') {

        operation[0] = op_type;
        fname = fopen (name, operation);

        return fname;
    }
    else {
        return NULL;
    }
}

int FileClose (FILE *fname) {
    if (fclose(fname) == 0) {
        return 0;
    }
    return ERROR;
}

int read(FILE *stream, char* Pointer[]) {
    if (stream == NULL || Pointer == NULL) {
        return ERROR;
    }

    char line[MAX_LEN] = {};
    int i = 0;
    while (fgets(line, MAX_LEN - 1, stream) != NULL) {
        str_formatter(line);

        Pointer[i] = (char *) calloc(strlen(line) + 1, sizeof(char));
        strcpy(Pointer[i], line);

        i++;
    }

    return i;
}


int write(FILE *out, char* Pointer[], size_t MAX) {
    if (out == NULL || Pointer == NULL) {
        return ERROR;
    }
    for (int i = 0; i < MAX; i++) {
        if (Pointer[i] == NULL) {
            return i;
        }

        fprintf(out, "%s", Pointer[i]);
    }

    return 0;
}
int clean(char* Pointer[]) {
    int i = 0;
    while (Pointer[i] != NULL) {
        free(Pointer[i]);
        i++;
    }
    return i;
}

int str_formatter(char *str1) {
    if (str1 == NULL) {
        return ERROR;
    }
    int string_len = strlen(str1);

    if (str1[string_len - 1] != '\n') {
        str1[string_len] = '\n';
        str1[string_len + 1] = '\0';
    }
    return 0;
}