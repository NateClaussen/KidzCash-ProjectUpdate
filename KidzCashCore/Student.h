#pragma once
#include <iostream>
#include <vector> 
#include "RepoItem.h"
#include "Transaction.h"

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

		protected:
			std::string FirstName, LastName;
			float AccountBalance;
			std::vector<Transaction> TransactionHistory;
			//void ReadTransactionHistory();
		};
	}
//}
//class Student
//{
//};

