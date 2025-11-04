/*
 * week4_2_struct_student.c
 * Author: Omer Kagan Turkel
 * Student ID: 231ADB255
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Defines a 'Student' struct with fields: name, id, and grade.
 *   Creates two Student variables and prints their information.
 */

#include <stdio.h>
#include <string.h>

/* Define the Student struct */
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    /* Declare Student variables */
    struct Student s1, s2;

    /* Assign values to the fields */
    strcpy(s1.name, "Alice Johnson");
    s1.id = 1001;
    s1.grade = 9.1f;

    strcpy(s2.name, "Bob Smith");
    s2.id = 1002;
    s2.grade = 8.7f;

    /* Print student information */
    printf("Student 1: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
    printf("Student 2: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

    return 0;
}
