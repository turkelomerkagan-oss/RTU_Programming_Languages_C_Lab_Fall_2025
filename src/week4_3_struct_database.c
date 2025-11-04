/*
 * week4_3_struct_database.c
 * Author: Ömer Kağan Türkel
 * Student ID: 231ADB255
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Dynamically allocates memory for multiple Student records,
 *   reads user input, displays all data in a formatted table,
 *   and frees allocated memory before exiting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the Student struct */
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    /* Allocate memory for n Student structs */
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Read data for each student */
    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d (Name ID Grade): ", i + 1);
        scanf("%49s %d %f", students[i].name, &students[i].id, &students[i].grade);
    }

    /* Display all records in formatted output */
    printf("\n%-6s %-12s %-6s\n", "ID", "Name", "Grade");
    printf("----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-12s %-6.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    /* Optional: Compute average grade */
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += students[i].grade;
    }
    printf("\nAverage grade: %.2f\n", total / n);

    /* Free allocated memory */
    free(students);

    return 0;
}
