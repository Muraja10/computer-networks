#include <stdio.h>
using namespace std;
// Define constants
#define NUM_DEPARTMENTS 12
#define MAX_EMPLOYEES 100

// Define structures
typedef struct {
    char gender;
    int age;
    float wage;
} Employee;

typedef struct {
    int numEmployees;
    int numWomen;
    int numMen;
    float totalWage;
    float avgAgeWomen;
    float avgAgeMen;
} DepartmentStats;

// Function to calculate department statistics
void calculateDepartmentStats(Employee employees[], int numEmployees, DepartmentStats departmentStats[]) {
    int i;

    // Initialize department statistics
    for (i = 0; i < NUM_DEPARTMENTS; i++) {
        departmentStats[i].numEmployees = 0;
        departmentStats[i].numWomen = 0;
        departmentStats[i].numMen = 0;
        departmentStats[i].totalWage = 0;
        departmentStats[i].avgAgeWomen = 0;
        departmentStats[i].avgAgeMen = 0;
    }

    // Calculate department statistics
    for (i = 0; i < numEmployees; i++) {
        int department = employees[i].department - 1;

        departmentStats[department].numEmployees++;
        departmentStats[department].totalWage += employees[i].wage;

        if (employees[i].gender == 'F') {
            departmentStats[department].numWomen++;
            departmentStats[department].avgAgeWomen += employees[i].age;
        } else if (employees[i].gender == 'M') {
            departmentStats[department].numMen++;
            departmentStats[department].avgAgeMen += employees[i].age;
        }
    }

    // Calculate average age
    for (i = 0; i < NUM_DEPARTMENTS; i++) {
        if (departmentStats[i].numWomen > 0) {
            departmentStats[i].avgAgeWomen /= departmentStats[i].numWomen;
        }
        if (departmentStats[i].numMen > 0) {
            departmentStats[i].avgAgeMen /= departmentStats[i].numMen;
        }
    }
}

int main() {
    // Declare and initialize employee data
    Employee employees[MAX_EMPLOYEES] = {
        {'M', 25, 5000.0, 1},
        {'F', 30, 6000.0, 1},
        {'M', 35, 7000.0, 2},
        // Add more employee data here
    };
    int numEmployees = 3; // Update the number of employees accordingly

    // Declare department statistics array
    DepartmentStats departmentStats[NUM_DEPARTMENTS];

    // Calculate department statistics
    calculateDepartmentStats(employees, numEmployees, departmentStats);

    // Output results
    printf("a. Wages of women compared with those of men:\n");
    // Calculate and print wage comparison

    printf("b. Total number of employees in each department:\n");
    // Print total number of employees in each department

    printf("c. Number of women and men in each department:\n");
    // Print number of women and men in each department

    printf("d. Average age of women and men in each department:\n");
    // Print average age of women and men in each department

    return 0;
}

