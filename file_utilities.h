//
// Created by Cameron Helme on 2/4/18.
//

#ifndef INC_343HOMEWORK1_FILE_UTILITIES_H
#define INC_343HOMEWORK1_FILE_UTILITIES_H

#endif //INC_343HOMEWORK1_FILE_UTILITIES_H



/* read_file will accept filename to be the name of the file it
 * opens and **buffer to give a memory address to read the file's
 * data into. This function returns the size of the file read.
 */
int read_file(char* filename, char **buffer);


/* write_file will accept filename to be the name for the
 * file we are creating, buffer will provide the input data
 * via a pointer, and size gives the size of the file. This
 * function returns the size fo the file read.
 */
int write_file(char* filename, char *buffer, int size);