#pragma once
#include "pch.h"
#include "InMemoryRepo.h"
#include "Student.h"
namespace KidzCashCore {
    //I could make this a template calss and then I could use it for
    //both students and shop items, but nahh...
   /* class InMemoryStudentRepo : public InMemoryRepo<Student>
    {
    public:
        virtual void Create(const Student&);
        virtual std::vector<Student> Read();
        virtual Student* ReadById(int);
        virtual void Update(int, Student);
        virtual void Delete(int);
    protected:
        std::vector<Student> students;
    };*/
}

