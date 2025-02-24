#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

class Course {
public:
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

void loadCourseData(string fileName, vector<Course>& courses) {
    stream file(fileName);
    (file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }
    // Read file and load data into courses vector
    // Read each line and parse courseNumber, courseTitle, prerequisites
}

void printCourseList(const vector<Course>& courses) {
    for (const auto& course : courses) {
        cout << course.courseNumber << ": " << course.courseTitle << endl;
    }
}

void printCourseInfo(const vector<Course>& courses, const string& courseNumber) {
    for (const auto& course : courses) {
        if (course.courseNumber == courseNumber) {
            cout << "Course Title: " << course.courseTitle << endl;
            cout << "Prerequisites: ";
            for (const auto& prerequisite : course.prerequisites) {
                cout << prerequisite << " ";
            }
            cout << endl;
            return;
        }
    }
    cerr << "Course not found." << endl;
}

int main() {
    vector<Course> courses;
    int option;
    string fileName, courseNumber;

    do {
        cout << "Menu Options:" << endl;
        cout << "1. Load course data" << endl;
        cout << "2. Print course list" << endl;
        cout << "3. Print course info" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter file name: ";
            cin >> fileName;
            loadCourseData(fileName, courses);
            break;
        case 2:
            printCourseList(courses);
            break;
        case 3:
            cout << "Enter course number: ";
            cin >> courseNumber;
            printCourseInfo(courses, courseNumber);
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cerr << "Invalid option. Please try again." << endl;
        }
    } while (option != 9);

    return 0;
}

