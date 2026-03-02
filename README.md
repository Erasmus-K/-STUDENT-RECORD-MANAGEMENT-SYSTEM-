# Student Record Management System

A simple console-based student record management system written in C for university assignment.

## 📋 Project Overview

This program allows users to manage student records with features like adding, displaying, searching, and persisting data to files.

## 🎯 Learning Objectives

This project demonstrates:
- **Variables and Data Types** (int, float, char arrays)
- **Control Structures** (if-else statements, while loops, for loops)
- **Arrays** (storing multiple students)
- **Functions** (modular code organization)
- **Structures** (grouping related data)
- **File Handling** (saving and loading data)

## 🏗️ Program Structure

### Student Structure
```c
struct Student {
    char regNo[20];   // Registration number
    char name[30];    // Student name
    int age;          // Age
    float marks;      // Marks
};
```

### Functions
- `addStudent()` - Add a new student record
- `displayStudents()` - Display all students in table format
- `searchStudent()` - Search for a student by registration number
- `saveToFile()` - Save records to students.txt
- `loadFromFile()` - Load records from students.txt

## 🚀 How to Compile and Run

### On Linux/macOS:
```bash
gcc student_system.c -o student_system
./student_system
```

### On Windows:
```bash
gcc student_system.c -o student_system.exe
student_system.exe
```

## 📖 How to Use

1. **Add Student**: Enter registration number, name, age, and marks
2. **Display Students**: View all students in a formatted table
3. **Search Student**: Find a student by registration number
4. **Save to File**: Persist data to students.txt
5. **Load from File**: Retrieve previously saved data
6. **Exit**: Close the program

## 💡 Example Usage

```
===== STUDENT RECORD SYSTEM =====
1. Add Student
2. Display Students
3. Search Student
4. Save to File
5. Load from File
6. Exit
Enter choice: 1

--- Add Student ---
Enter Registration No: CS101
Enter Name: John
Enter Age: 20
Enter Marks: 85.5
Student added successfully!
```

## 📁 Files

- `student_system.c` - Main source code
- `students.txt` - Data file (created after first save)
- `README.md` - This documentation

## 🔑 Key Concepts Explained

### Pointers
Used in functions like `addStudent(struct Student students[], int *count)` to modify the original count variable.

### String Comparison
Uses `strcmp()` from `<string.h>` to compare registration numbers (can't use `==` for strings in C).

### File I/O
- `fopen()` - Opens a file
- `fprintf()` - Writes formatted data to file
- `fscanf()` - Reads formatted data from file
- `fclose()` - Closes the file

### Arrays of Structures
`struct Student students[100]` creates an array that can hold up to 100 student records.

## ⚠️ Limitations

- Maximum 100 students
- Names cannot contain spaces (use underscore instead)
- No data validation for negative ages or marks

## 🎓 Assignment Requirements Met

✅ Structure definition  
✅ Array of structures  
✅ Menu system with if-else  
✅ All required functions implemented  
✅ File handling (save/load)  
✅ String comparison using strcmp()

## 📝 Author

University C Programming Assignment

## 📄 License

Free to use for educational purposes.
