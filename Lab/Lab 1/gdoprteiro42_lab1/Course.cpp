/*
	Functions for Course Structure
	LAB 1 - CSC1310
	Gabriel Porteiro
	1/22/2024
*/

#include "Course.h"

// Function to handle new course creation
Course* createCourse(string name, string location, int sectionCount, int creditHours) {

    // Allocate course and sections
    Course* newCourse = new Course;
    string* sections = new string[sectionCount];

    // Set course attributes
    (*newCourse).name = name;
    (*newCourse).location = location;
    (*newCourse).creditHours = creditHours;
    (*newCourse).sections = sections;
    (*newCourse).sectionCount = sectionCount;

    return newCourse;

}

// Function to print all the attributes and sections of a course
void printCourse(Course* myCourse) {

    // Display main info
    cout << left << setw(24) << "COURSE NAME:" << (*myCourse).name << endl << endl;
    cout << setw(24) << "COURSE LOCATION:" << (*myCourse).location << endl << endl;
    cout << setw(24) << "COURSE HOURS:" << (*myCourse).creditHours << endl << endl;
    cout << "COURSE SECTIONS:" << endl << endl;

    // Display sections
    for (int i = 0; i < (*myCourse).sectionCount; i ++) {

        cout << setw(24) << "" << (*myCourse).sections[i] << endl << endl;

    }

}

// Function to deletes a course by releasing all it's memory
void destroyCourse(Course* myCourse) {

    // Delete all sections
    delete [] (*myCourse).sections;

    // Delete the course
    delete myCourse;

}
