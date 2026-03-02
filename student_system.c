/*
 * Student Record Management System
 * A console-based application for managing student records
 * Demonstrates: structures, arrays, functions, file I/O, control structures
 */

#include <stdio.h>   // Standard input/output functions
#include <string.h>  // String manipulation functions

// Structure definition - groups related data together
struct Student {
    char regNo[20];   // Registration number (text)
    char name[30];    // Student name (text)
    int age;          // Age (whole number)
    float marks;      // Marks (decimal number)
};

// Function prototypes - tell compiler these functions exist
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void saveToFile(struct Student students[], int count);
void loadFromFile(struct Student students[], int *count);

int main() {
    struct Student students[100];
    int count = 0;
    int choice;
    
    // Infinite loop - runs until user chooses to exit
    while (1) {
        // Display menu
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        
        scanf("%d", &choice);  // Read user input
        
        // Handle user choice with if-else
        if (choice == 1) {
            addStudent(students, &count);
        } else if (choice == 2) {
            displayStudents(students, count);
        } else if (choice == 3) {
            searchStudent(students, count);
        } else if (choice == 4) {
            saveToFile(students, count);
        } else if (choice == 5) {
            loadFromFile(students, &count);
        } else if (choice == 6) {
            printf("Exiting program. Goodbye!\n");
            break;  // Exit the loop
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}

// Function implementations will go below
void addStudent(struct Student students[], int *count) {
    // Check if array has reached maximum capacity
    if (*count >= 100) {
        printf("Cannot add more students. Array is full!\n");
        return;
    }
    
    printf("\n--- Add Student ---\n");
    printf("Enter Registration No: ");
    scanf("%s", students[*count].regNo);
    
    printf("Enter Name: ");
    scanf("%s", students[*count].name);
    
    printf("Enter Age: ");
    scanf("%d", &students[*count].age);
    
    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);
    
    (*count)++;  // Increment count using pointer
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    // Check if there are any students to display
    if (count == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    // Print table header with formatting
    printf("\n%-20s %-30s %-10s %-10s\n", "Reg No", "Name", "Age", "Marks");
    printf("-----------------------------------------------------------------------\n");
    
    // Loop through all students and display their information
    for (int i = 0; i < count; i++) {
        printf("%-20s %-30s %-10d %-10.2f\n", 
               students[i].regNo, 
               students[i].name, 
               students[i].age, 
               students[i].marks);
    }
}

void searchStudent(struct Student students[], int count) {
    char searchReg[20];
    
    printf("\n--- Search Student ---\n");
    printf("Enter Registration No to search: ");
    scanf("%s", searchReg);
    
    // Linear search through the array
    for (int i = 0; i < count; i++) {
        // Use strcmp() to compare strings (can't use == for strings in C)
        if (strcmp(students[i].regNo, searchReg) == 0) {
            printf("\nStudent Found!\n");
            printf("Reg No: %s\n", students[i].regNo);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            return;  // Exit function once student is found
        }
    }
    
    printf("Student not found!\n");
}

void saveToFile(struct Student students[], int count) {
    // Open file in write mode (creates new or overwrites existing)
    FILE *file = fopen("students.txt", "w");
    
    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Write each student's data to file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %.2f\n", 
                students[i].regNo, 
                students[i].name, 
                students[i].age, 
                students[i].marks);
    }
    
    fclose(file);  // Always close files after use
    printf("Data saved to students.txt successfully!\n");
}

void loadFromFile(struct Student students[], int *count) {
    // Open file in read mode
    FILE *file = fopen("students.txt", "r");
    
    // Check if file exists
    if (file == NULL) {
        printf("No saved data found!\n");
        return;
    }
    
    *count = 0;  // Reset count before loading
    
    // Read data until end of file (fscanf returns 4 when successful)
    while (fscanf(file, "%s %s %d %f", 
                  students[*count].regNo, 
                  students[*count].name, 
                  &students[*count].age, 
                  &students[*count].marks) == 4) {
        (*count)++;
    }
    
    fclose(file);  // Close the file
    printf("Data loaded successfully! Total students: %d\n", *count);
}
