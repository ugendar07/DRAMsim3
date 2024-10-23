

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[])
{
    FILE *fd; // File pointer
    char filename[] = "ptrace.txt"; // file to read
    char buff[1024];

    if ((fd = fopen(filename, "r")) != NULL) // open file
    {
        fseek(fd, 0, SEEK_SET); // make sure start from 0

        while(!feof(fd))
        {
            memset(buff, 0x00, 1024); // clean buffer
            fscanf(fd, "%[^\n]\n", buff); // read file *prefer using fscanf
        }
        printf("Last Line :: %s\n", buff);
    }
}

