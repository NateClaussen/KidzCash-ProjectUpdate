#include "PointTracker.h"
#include "StudentManager.h"
#include <vector>
#include <iomanip>
#include <string>
#include "Student.h"

using KidzCashCore::Student;

void PointTracker::DisplayStudents(std::vector<Student> students) {
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "| " << std::setw(10) << "   ID     ";
	std::cout << "| " << std::setw(15) << "First Name   ";
	std::cout << "| " << std::setw(16) << "Last Name     ";
	std::cout << "| " << std::setw(10) << " Points  |" << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;

	for (Student& s : students) {
		std::cout << std::left;
		std::cout << "|";
		std::cout << "    " << std::setw(10) << s.getId();
		std::cout << std::setw(16) << s.GetFirstName();
		std::cout << std::setw(17) << s.GetLastName();
		std::cout << std::setw(10) << s.getPoints();
		std::cout << "|" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
	}
}

void PointTracker::InputMainMenu() {
	std::string input;
	std::cout << "                 <-- Prev(1) (2)Next -->\n";
	std::cin >> input;
	if (stoi(input) == 1) {
		DisplayMenu(MenuOption::STUDENTS_NEXT);
	}
	else {
		DisplayMenu(MenuOption::STUDENTS_PREV);
	}
}

void PointTracker::DisplayMenu(MenuOption menu) {
	system("CLS");
	switch (menu) {
	case STUDENTS_NEXT:
		DisplayStudents(manager.GetNextStudents());
		InputMainMenu();
		break;
	case STUDENTS_PREV:
		DisplayStudents(manager.GetPreviousStudents());
		InputMainMenu();
		break;
	case ADD_POINTS:
		break;
	case REMOVE_POINTS:
		break;
	}
}

void PointTracker::AddPoints(int id, float p) {
	manager.AddPoints(id, p);
}

void PointTracker::RemovePoints(int id, float p) {
	manager.RemovePoints(id, p);
}