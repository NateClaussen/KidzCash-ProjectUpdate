#pragma once
#include "pch.h"
#include <iostream>
#include <vector> 
#include "RepoItem.h"
#include "Transaction.h"


namespace KidzCashCore {

	template<typename T>
	class InMemoryRepo;

	//namespace student {
	class Student : public RepoItem {
	public:
		/// <summary>
		/// Goes through the transactionHistory and totals all of the BUY transactions
		/// </summary>
		/// <returns>Total amount a student has spent</returns>
		float moneySpent();

		Student();
		Student(int, std::string, std::string, float);
		Student(const Student& other);
		~Student();

		Student& operator=(const Student& other);
		/// <summary>
		/// Gives the string representation that is written to the file
		/// </summary>
		/// <returns>A single line that represents the student</returns>
		std::string toStr() const;
		void fromStr(const std::string& str);
		bool addTransaction(Transaction&);
		bool addTransaction(TransType t, float amount);
		void removeTransaction(int);
		std::vector<Transaction> getTransactions();
		float getPoints();
		void addPoints(float);
		bool removePoints(float);

		std::string GetFirstName() { return FirstName; }
		std::string GetLastName() { return LastName; }

	protected:
		std::string FirstName, LastName;
		float points;
		InMemoryRepo<Transaction>* TransactionHistory;


		//std::vector<Transaction> TransactionHistory;
		//void ReadTransactionHistory();
	};
}
//}
//class Student
//{
//};

