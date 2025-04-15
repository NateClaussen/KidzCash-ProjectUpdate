// KidzCash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "student.h"
#include "PointTracker.h"

using KidzCashCore::Student;

int main()
{
    PointTracker tracker;

	Student student1(1, "Johnny", "Joe", 1);
	Student student2(2, "Joel", "Saurey", 11);
	Student student3(3, "Maureen", "Saurey", 111);
	Student student4(4, "Valerie", "Claussen", 1111);
	Student student5(5, "Larry", "Claussen", 11111);



	///*students.push_back(student1);
	//students.push_back(student2);
	//students.push_back(student3);
	//students.push_back(student4);
	//students.push_back(student5);*/

	/*tracker.getManager().AddStudent(student1);
	tracker.getManager().AddStudent(student2);
	tracker.getManager().AddStudent(student3);
	tracker.getManager().AddStudent(student4);
	tracker.getManager().AddStudent(student5);*/

    tracker.DisplayMenu(MenuOption::STUDENTS_NEXT);
    //student::PrintMessage();
    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
