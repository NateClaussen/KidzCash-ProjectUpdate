#pragma once
#include "pch.h"
#include <iostream>
#include <vector> 
#include "RepoItem.h"
#include "Transaction.h"
#include "InMemoryRepo.h"

namespace KidzCashCore {
	//namespace student {
		class Student : public RepoItem {
		public:
			/// <summary>
			/// Goes through the transactionHistory and totals all of the BUY transactions
			/// </summary>
			/// <returns>Total amount a student has spent</returns>
			float moneySpent();

			Student(int, std::string, std::string, float);
			~Student();

			Student& operator=(const Student& other);
			/// <summary>
			/// Gives the string representation that is written to the file
			/// </summary>
			/// <returns>A single line that represents the student</returns>
			std::string toStr();
			void fromStr(const std::string& str);
			bool addTransaction(Transaction&);
			bool addTransaction(TransType t, float amount);
			void removeTransaction(int);
			std::vector<Transaction> getTransactions() { return TransactionHistory.getItems(); }
			float getPoints();
			void addPoints(float);
			bool removePoints(float);

		protected:
			std::string FirstName, LastName;
			float points;
			InMemoryRepo<Transaction> TransactionHistory;

			
			//std::vector<Transaction> TransactionHistory;
			//void ReadTransactionHistory();
		};
	}
//}
//class Student
//{
//};

