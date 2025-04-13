#pragma once
#include "StudentManager.h"

using KidzCashCore::StudentManager;

enum MenuOption {STUDENTS_NEXT = 0, STUDENTS_PREV, ADD_POINTS, REMOVE_POINTS, };
class PointTracker
{
public:
	void DisplayMenu(MenuOption);
	//void DisplayNextStudents();
	void AddPoints(int id, float p);
	void RemovePoints(int id, float p);
	StudentManager getManager() { return manager; }

private:
	void DisplayStudents(std::vector<KidzCashCore::Student>);
	StudentManager manager;
	//KidzCashCore::Student* selected;
};

