#include "pch.h"
#include "Transaction.h"
#include <ctime>
#include <sstream>

namespace KidzCashCore {
	Transaction::Transaction(int id, TransType Type, float Amount) : RepoItem(id) {
		type = Type;
		amount = Amount;

		std::time_t t = std::time(nullptr);

		std::tm now;
		localtime_s(&now, &t);


		day = now.tm_mday;
		month = now.tm_mon + 1;
		year = now.tm_year + 1900;
	}

	Transaction::Transaction() : RepoItem(-1) {
		type = TransType::OTHER;
		amount = 0;
		std::time_t t = std::time(nullptr);

		std::tm now;
		localtime_s(&now, &t);


		day = now.tm_mday;
		month = now.tm_mon + 1;
		year = now.tm_year + 1900;
	}

	std::string Transaction::toStr() const {
		std::stringstream ss;
		ss << getId() << "," << day << "," << month << "," << year << "," << type << "," << amount;
		return ss.str();
	}

	void Transaction::fromStr(const std::string& str) {
		std::stringstream ss(str);
		std::string next;

		std::getline(ss, next, ',');
		setId(std::stoi(next));

		std::getline(ss, day, ',');
		std::getline(ss, month, ',');
		std::getline(ss, year, ',');

		//TransType
		std::getline(ss, next, ',');
		setType(static_cast<TransType>(stoi(next)));

		//Transaction Amount
		std::getline(ss, next, ',');
		setAmount(stof(next));

	}

}