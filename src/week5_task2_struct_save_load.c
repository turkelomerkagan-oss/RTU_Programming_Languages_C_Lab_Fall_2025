/*
 * week5_task2_struct_save_load.c
 * Author: Ömer Kağan Türkel
 * Student ID: 231ADB255
 * Description:
 *   Demonstrates saving and loading a struct to and from a text file.
 *   Uses fprintf() and fscanf() for structured data storage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

/* Function prototypes */
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    printf("Saving student to file...\n");
    save_student(s1, filename);

    printf("Loading student from file...\n");
    Student loaded = load_student(filename);

    printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age, loaded.gpa);

    return 0;
}

/* Save student data to text file */
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing.\n", filename);
        exit(1);
    }

    fprintf(fp, "%s %d %.2f\n", s.name, s.age, s.gpa);

    fclose(fp);
}

/* Load student data from text file */
Student load_student(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for reading.\n", filename);
        exit(1);
    }

    if (fscanf(fp, "%49s %d %f", s.name, &s.age, &s.gpa) != 3) {
        printf("Error: failed to read student data from file.\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return s;
}
