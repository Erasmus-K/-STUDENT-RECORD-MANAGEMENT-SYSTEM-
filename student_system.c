#include <stdio.h>
#include <string.h>

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
    
    (*count)++;  // Increment count
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    printf("\n%-20s %-30s %-10s %-10s\n", "Reg No", "Name", "Age", "Marks");
    printf("-----------------------------------------------------------------------\n");
    
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
    
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].regNo, searchReg) == 0) {
            printf("\nStudent Found!\n");
            printf("Reg No: %s\n", students[i].regNo);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    
    printf("Student not found!\n");
}

void saveToFile(struct Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %.2f\n", 
                students[i].regNo, 
                students[i].name, 
                students[i].age, 
                students[i].marks);
    }
    
    fclose(file);
    printf("Data saved to students.txt successfully!\n");
}

void loadFromFile(struct Student students[], int *count) {
    FILE *file = fopen("students.txt", "r");
    
    if (file == NULL) {
        printf("No saved data found!\n");
        return;
    }
    
    *count = 0;
    while (fscanf(file, "%s %s %d %f", 
                  students[*count].regNo, 
                  students[*count].name, 
                  &students[*count].age, 
                  &students[*count].marks) == 4) {
        (*count)++;
    }
    
    fclose(file);
    printf("Data loaded successfully! Total students: %d\n", *count);
}
