//
// Created by Cameron Helme on 2/4/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utilities.h"


int read_file(char* filename, char **buffer){
    FILE* f;
    char* mode = "r";  // Used to indicate that the file is being opened to read
    int size;  // Will be used to store the size of the file (in number of chars)

    f = fopen(filename, mode);  // The file is opened and pointed to with f

    if (f == NULL){ // Tells user that the file could not be retrieved and why, exits the method
        printf("This file cannot be retrieved.\n");
        perror(NULL);
        exit(0);
    }

    /* The below code reads the file to find
     * its size, which is then put into the size variable*/
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    *buffer = (char*)malloc(size * sizeof(char));  // Dereferencing buffer and allocating it a memory space

    if (*buffer == NULL){
        perror("Error allocating memory");
        exit(0);
    }

    (*buffer)[size] = '\0';  // appends the null character onto the end of the text file

    fread(*buffer, size, 1, f);

    // Below is a print function used to test this method
    //printf(*buffer);

    fclose(f);

    return size;
};

int write_file(char* filename, char *buffer, int size){
    FILE* f;
    char* mode = "w";  // Used to indicate that the file is being opened to write
    int docSize = (int)strlen(buffer); //Gives the size of buffer in number of char's

    f = fopen(filename, mode);  // Creates the blank file


    fputs(buffer, f);

    return docSize;
};