/*
 * week5_task3_student_management_system.c
 * Author: Ömer Kağan Türkel
 * Student ID: 231ADB255
 * Description:
 *   Mini-project – Student management system with file persistence.
 *   Loads students from a text file at startup, allows listing and adding,
 *   and saves back to the file before exit.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

/* Function prototypes */
int  load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    /* Load existing data from file */
    count = load_students(students);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            /* clear invalid input */
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Invalid input. Try again.\n");
            continue;
        }
        /* clear newline if any */
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                save_students(students, count);
                printf("Data saved. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

/* Open DATA_FILE, read records until EOF, return number of records loaded */
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        /* File may not exist yet; start with 0 students */
        return 0;
    }

    int count = 0;
    while (count < MAX_STUDENTS &&
           fscanf(fp, "%49s %d %f", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}

/* Write all students to DATA_FILE (one record per line) */
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        printf("Error: could not open '%s' for writing.\n", DATA_FILE);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }

    fclose(fp);
}

/* Read input from user and append to array */
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: maximum number of students reached (%d).\n", MAX_STUDENTS);
        return;
    }

    Student s;
    printf("Enter name (no spaces): ");
    if (scanf("%49s", s.name) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid name input.\n");
        return;
    }

    printf("Enter ID: ");
    if (scanf("%d", &s.id) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid ID input.\n");
        return;
    }

    printf("Enter GPA: ");
    if (scanf("%f", &s.gpa) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid GPA input.\n");
        return;
    }

    /* clear trailing newline if any */
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    arr[*count] = s;
    (*count)++;
    printf("Student added successfully!\n");
}

/* Print all students in readable format */
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students in the list.\n");
        return;
    }

    printf("\n%-6s %-12s %-6s\n", "ID", "Name", "GPA");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-12s %-6.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }
}
