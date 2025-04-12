#pragma once
#include "pch.h"
#include "FileRepo.h"
#include "Paginator.h"

namespace KidzCashCore {
	/// <summary>
	/// This class is to put together all of the abstractified pieces and
	/// aggregate the students.
	/// It uses Composition of classes!!
	/// </summary>
	class StudentManager
	{
	public:
		/// <summary>
		/// Default values:
		/// Filename: "Students.KCC"
		/// DisplayCount: 10  
		/// </summary>
		StudentManager();
		StudentManager(std::string);
		StudentManager(std::string Filename, int displayCount);
		
		//Point Management
		void AddPoints(int, float);
		void AddPointsTrans(int, float);
		bool RemovePoints(int, float);
		bool RemovePointsTrans(int, float);
		//void AddTransaction(Student&, Transaction&);
		//void voidTransaction(Student&, Transaction&);

		//Actual Student Management
		void AddStudent(Student&);
		void RemoveStudent(Student&);
		Student* GetStudentById(int id);

		//Pagination
		std::vector<Student> GetAllStudents();
		std::vector<Student> GetNextStudents();
		std::vector<Student> GetPreviousStudents();
		void setStart(int);
		void setDisplayCount(int);
		
	private:
		//This creates an automatic in-memory and file repo
		//because a file repo is an in-memory repo too
		FileRepo<Student> students;
		Paginator<Student> paginator;		
	};
}

