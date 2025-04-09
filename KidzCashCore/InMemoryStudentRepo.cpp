#include "pch.h"
#include "InMemoryStudentRepo.h"

namespace KidzCashCore {
	void InMemoryStudentRepo::Create(Student student) {
		if (student.getId() <= 0)
			student.setId(students.size() + 1);
		students.push_back(student);
	}

	std::vector<Student> InMemoryStudentRepo::Read() {
		return students;
	}

	Student InMemoryStudentRepo::ReadById(int id) {
		for (Student s : students) {
			if (s.getId() == id) {
				return s;
			}
		}
		std::cout << "Person Not Found" << std::endl;
	}

	void InMemoryStudentRepo::Update(int id, Student updated) {
		Student searched = ReadById(id);
		if (searched.getId() > 0) {
			searched = updated;
		}
		else {
			Create(updated);
		}
		//For the file one, I'll have to figure out how to save to that specific spot in the file
		//to save that specific student...
	}

	void InMemoryStudentRepo::Delete(int id) {
		students.erase(std::remove_if(students.begin(), students.end(),
			[id](const Student& s) {
				return (s.getId() == id);
			}
		), students.end());
		/*Student searched = ReadById(id);
		if (searched.getId() > 0) {
			students.erase(find(students.begin(), students.end(), searched));
		}*/
	}

}