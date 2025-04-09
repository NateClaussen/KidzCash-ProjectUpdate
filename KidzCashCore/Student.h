#pragma once
#include <iostream>
#include <vector> 
#include "RepoItem.h"

namespace KidzCashCore {
	//namespace student {

		enum TransType { DEPOSIT = 0, WITHDDRAWL, BUY, OTHER };
		struct Transaction {
			std::string day, month, year;
			float amount;
			TransType type;

			Transaction(std::string day, std::string month, std::string year, TransType type, float amount) :
				day(day), month(month), year(year), type(type), amount(amount) {
			}
		};

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

