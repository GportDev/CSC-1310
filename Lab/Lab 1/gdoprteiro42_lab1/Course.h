/*
	Header file for Course Structure
	LAB 1 - CSC1310
	Gabriel Porteiro
	1/22/2024
*/

// Create file guards
#ifndef COURSE_H
#define COURSE_H

// Include necessary libraries
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Define course struct
struct Course {
    string name;
    string location;
    string* sections;
    int sectionCount;
    int creditHours;
};

// Create functions prototypes
Course* createCourse(string, string, int, int);

void destroyCourse(Course* myCourse);

void printCourse(Course* myCourse);


// Close file guards
#endif