#include "pch.h"
#include "Student.h"


namespace KidzCashCore {
	Student::Student(int id, std::string firstName, std::string lastName, float accountBalance) : RepoItem(id)
	{
		FirstName = firstName;
		LastName = lastName;
		AccountBalance = accountBalance;
		
		//ReadTransactionHistory();
	}

	Student::~Student() {
		//for (auto t : TransactionHistory) {
			//delete t;
		//}
	}

	Student& Student::operator=(const Student& other) {
		if (this != &other) {
			TransactionHistory.clear();
			TransactionHistory = other.TransactionHistory;
			FirstName = other.FirstName;
			LastName = other.LastName;
			AccountBalance = other.AccountBalance;
		}
		return *this;
	}

	float Student::moneySpent() {
		float total = 0;
		for (Transaction t : TransactionHistory) {
			total += t.amount;
		}
		return total;
	}

	//void Student::ReadTransactionHistory() {
		//Read the file and get all of the transaction history for this student?? I might need to move this 
		//to another file?
	//}
	//namespace student {
		/*void PrintMessage() {
			std::cout << "Hello World! I have changed now again!!! MUAHAHAHAHA. Change now?????" << std::endl;
		}*/
	//}
}