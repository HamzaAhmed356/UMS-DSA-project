# UMS – University Management System (C++)

## Project Overview
UMS (University Management System) is a console-based C++ application designed to manage
student admissions, teacher job applications, and administrative operations.

The system uses Data Structures such as Binary Search Trees and Linked Lists to store
records dynamically during runtime. This project is developed for educational purposes
to demonstrate Object-Oriented Programming and Data Structures concepts.

---

## Objectives
- Allow students to apply for admission
- Allow teachers to apply for jobs
- Enable administrator to review applications
- Accept or reject applications
- Track application status through portals
- Practice Binary Search Trees and Linked Lists

---

## Concepts and Technologies Used

### Programming Language
- C++

### Object-Oriented Programming
- Classes and Objects
- Encapsulation
- Dynamic Memory Allocation
- Pointers

### Data Structures
- Binary Search Tree (BST)  
  Used for storing student admission applications based on CNIC
- Linked List / Stack  
  Used for storing teacher job applications

### Other Concepts
- Menu-driven programming
- Recursive tree traversal
- Console-based user interface
- Input validation

---

## System Modules

### Student Module
- Apply for admission
- Login to student portal
- View application status
  - Pending
  - Noticed
  - Accepted (Student ID generated)

Student records are stored in a Binary Search Tree using CNIC as the key.

---

### Teacher Module
- Apply for teaching job
- Login to teacher portal
- View job application status

Teacher records are stored using a Linked List (stack behavior).

---

### Admin Module
- View all student admission records
- Accept student admissions
- Generate student IDs
- View teacher job applications (future scope)
- Accept teacher job applications (future scope)

---

## Data Structure Design

### Student Records
- Stored in Binary Search Tree
- Key used: CNIC
- Displayed using inorder traversal

### Teacher Records
- Stored in Linked List
- New records added at the head (stack implementation)

---

## How to Run the Project
1. Open Visual Studio or any C++ compiler
2. Create a Console Application
3. Paste the source code into the project
4. Compile and run the program
5. Use menu options to navigate the system

---

## Sample Menus

### Main Menu
Login as Student

Login as Teacher

Login as Administrator

Exit

shell
Copy code

### Student Menu
Apply for Admission

Login to Student Portal

Exit

shell
Copy code

### Admin Menu
Show All Student Records

Accept Student Admission

Show Teacher Job Applications

Accept Teacher Job Application

Exit

yaml
Copy code

---

## Limitations
- Data is not stored permanently
- No database or file handling
- No authentication system for admin
- Windows-specific due to use of system("cls")

---

## Future Improvements
- Add file handling or database support
- Implement admin authentication
- Complete teacher job acceptance functionality
- Improve user interface
- Remove goto statements
- Convert project to GUI-based application

---

## Developer
HamzaAhmed365

---

## License
This project is developed for learning and academic purposes only.

---

## Final Note
This project is suitable for:
- Data Structures practice
- Object-Oriented Programming learning
- Semester projects
- Understanding BST and Linked List implementation
