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
			total += t.getAmount();
		}
		return total;
	}

	std::string Student::toStr() {
		std::stringstream ss;
		ss << getId() << "," << LastName << "," << FirstName << "," << AccountBalance;

		//Ideally, I would probably make a separate "transactions" file that would hold all of the transactions
		//and then connect each transaction to a student... but for the purpose of the final
		//I think that I am just going to have all of the transactions be on one line... might
		//get a little messy, but oh well, this file isn't really meant to be read by humans anyways lol...
		for (Transaction t : TransactionHistory) {
			ss << "|" << t.toStr();
		}
		return ss.str();
	}

	void Student::fromStr(const std::string& str) {
		//separate the student from the transaction so that it parses correctly
		auto pos = str.find('|');
		std::string studentPart = (pos == std::string::npos) ? str : str.substr(0, pos);
		std::string transactionPart = (pos == std::string::npos) ? "" : str.substr(pos + 1);

		std::stringstream ss(studentPart);
		std::string next;
		std::getline(ss, next, ',');
		setId(std::stoi(next));

		std::getline(ss, LastName, ',');
		std::getline(ss, FirstName, ',');
		std::getline(ss, next, ',');
		AccountBalance = std::stof(next);

		if (!transactionPart.empty()) {
			TransactionHistory.clear();
			std::stringstream ts(transactionPart);
			std::string trans;
			while (std::getline(ts, trans, '|')) {
				Transaction t;
				t.fromStr(trans);
				TransactionHistory.push_back(t);
			}
		}
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