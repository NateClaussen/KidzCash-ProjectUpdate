#include "pch.h"
#include "StudentManager.h"

namespace KidzCashCore {
	//Constructors :)
	StudentManager::StudentManager() : StudentManager("Students.KCC", 10) {
		//StudentManager("Students.KCC", 0, 0);
		////students = new FileRepo<Student>("Students.KCC");
		//start = 0;
		//end = students.Read().size(); //I might need a - 1 here for the off by one error
	}
	StudentManager::StudentManager(std::string filename) : StudentManager(filename, 10) {

	}
	StudentManager::StudentManager(std::string Filename, int displayCount) : 
		students(Filename), paginator(students.Read(), displayCount) { }

	void StudentManager::AddTransaction(Student& s, Transaction& t) {
		//I REALLY hope that this works!! I am worried that it is not going to save to the file okay.
		//Add transaction to the student
		s.addTransaction(t);
		//Update the file with that updated student. 
		students.Update(s.getId(), s);
	}

	void StudentManager::voidTransaction(Student& s, Transaction& t) {
		s.removeTransaction(t.getId());
		students.Update(s.getId(), s);
	}

	void StudentManager::AddStudent(Student& s) {
		students.Create(s);
	}

	void StudentManager::RemoveStudent(Student& s){
		students.Delete(s.getId());
	}

	Student StudentManager::GetStudentById(int id) {
		return students.ReadById(id);
	}

	std::vector<Student> StudentManager::GetAllStudents() {
		return students.Read();
	}


	//Pagination
	std::vector<Student> StudentManager::GetNextStudents() {
		paginator.GetNextItems();
	}

	std::vector<Student> StudentManager::GetPreviousStudents() {
		paginator.GetPrevItems();
	}

	void StudentManager::setDisplayCount(int c) { 
		displayCount = c; 
	}

	void StudentManager::setStart(int s) {
		start = s;
	}

}
