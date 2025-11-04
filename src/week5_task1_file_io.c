/*
 * week5_task1_file_io.c
 * Author: Ömer Kağan Türkel
 * Student ID: 231ADB255
 * Description:
 *   Demonstrates basic file I/O in C.
 *   Writes several lines to a text file and then reads them back line by line.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    /* 1. Open file for writing */
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file for writing.\n");
        return 1;
    }

    printf("Writing lines to %s...\n", filename);

    /* 2. Write some lines to the file */
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fprintf(fp, "File handling made easy.\n");

    /* 3. Close the file after writing */
    fclose(fp);

    /* 4. Open the same file for reading */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file for reading.\n");
        return 1;
    }

    printf("Reading contents:\n");

    /* 5. Read and print each line using fgets() */
    int line_count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    printf("\nTotal %d lines read.\n", line_count);

    /* 6. Close the file after reading */
    fclose(fp);

    return 0;
}
