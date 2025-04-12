#include "pch.h"
#include "Student.h"
#include "InMemoryRepo.h"

namespace KidzCashCore {
	Student::Student(int id, std::string firstName, std::string lastName, float accountBalance) : RepoItem(id)
	{
		FirstName = firstName;
		LastName = lastName;
		points = accountBalance;
		TransactionHistory = new InMemoryRepo<Transaction>();
		//ReadTransactionHistory();
	}

	Student::Student(const Student& other) : RepoItem(other.getId()) {
		FirstName = other.FirstName;
		LastName = other.LastName;
		points = other.points;

		TransactionHistory = new InMemoryRepo<Transaction>();
		for (const Transaction& t : other.TransactionHistory->getItems()) {
			TransactionHistory->Create(t);
		}
	}

	Student::~Student() {
		delete TransactionHistory;
		//for (auto t : TransactionHistory) {
			//delete t;
		//}
	}

	bool Student::addTransaction(Transaction& t) {
		switch (t.getType()) {
		case DEPOSIT:
			addPoints(t.getAmount());
			TransactionHistory->Create(t);
			return true;
		case WITHDRAWL:
		case BUY:
			if (removePoints(t.getAmount())) {
				TransactionHistory->Create(t);
				return true;
			}
			else {
				return false;
			}
		case OTHER:
			TransactionHistory->Create(t);
			return true;
			break;
		}
		return false;
	}

	bool Student::addTransaction(TransType t, float amount) {
		Transaction trans(-1,t, amount);
		return addTransaction(trans);
	}

	void Student::removeTransaction(int id) {
		TransactionHistory->Delete(id);
	}

	std::vector<Transaction> Student::getTransactions() {
		return TransactionHistory->Read();
	}

	Student& Student::operator=(const Student& other) {
		if (this != &other) {
			FirstName = other.FirstName;
			LastName = other.LastName;
			points = other.points;
			setId(other.getId());

			delete TransactionHistory;
			TransactionHistory = new InMemoryRepo<Transaction>();
			for (const Transaction& t : other.TransactionHistory->getItems()) {
				TransactionHistory->Create(t);
			}
		}
		return *this;
	}

	float Student::moneySpent() {
		float total = 0;
		for (Transaction t : TransactionHistory->getItems()) {
			total += t.getAmount();
		}
		return total;
	}

	void Student::addPoints(float p) {
		points += p;
	}
	
	bool Student::removePoints(float p) {
		if (p < 0 || points < p) {
			return false;
		}
		else {
			points -= p;
			return true;
		}
	}

	float Student::getPoints() {
		return points;
	}


	std::string Student::toStr() {
		std::stringstream ss;
		ss << getId() << "," << LastName << "," << FirstName << "," << points;

		//Ideally, I would probably make a separate "transactions" file that would hold all of the transactions
		//and then connect each transaction to a student... but for the purpose of the final
		//I think that I am just going to have all of the transactions be on one line... might
		//get a little messy, but oh well, this file isn't really meant to be read by humans anyways lol...
		for (Transaction t : TransactionHistory->getItems()) {
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
		points = std::stof(next);

		if (!transactionPart.empty()) {
			TransactionHistory->getItems().clear();
			std::stringstream ts(transactionPart);
			std::string trans;
			while (std::getline(ts, trans, '|')) {
				Transaction t;
				t.fromStr(trans);
				TransactionHistory->Create(t);
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