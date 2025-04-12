#pragma once
#include "pch.h"
#include "RepoItem.h"

namespace KidzCashCore {
    enum TransType {DEPOSIT = 0, WITHDRAWL, BUY, OTHER };
    //I could make this a struct and remove all of the getters/setters
    //but for now I think I'll keep it. 
    class Transaction : public RepoItem
    {
    public:
        Transaction();
        Transaction(int id, std::string day, std::string month, std::string year, TransType type, float amount) :
            RepoItem(id), day(day), month(month), year(year), type(type), amount(amount) {}
        /// <summary>
        /// Creates a transaction with the current date
        /// </summary>
        /// <param name="id">id of the transaction</param>
        /// <param name="type">type of transaction</param>
        /// <param name="amount">acmount the transaction was for</param>
        Transaction(int id, TransType type, float amount);
        std::string toStr();
        void fromStr(const std::string& str);
        //This whole section of code tells me I should prolly convert
        //this back into a struct, but ohhhhh welllll... I'll keep it 
        //for now...
        std::string getDay() { return day; }
        std::string getMonth() { return month; }
        std::string getYear() { return year; }
        float getAmount() { return amount; }
        TransType getType() { return type; } 

        void setDay(std::string d) { day = d; }
        void setMonth(std::string m) { month = m; }
        void setYear(std::string y) { year = y; }
        void setAmount(float a) { amount = a; }
        void setType(TransType t) { type = t; }


    protected:
        std::string day, month, year;
        float amount;
        TransType type;
    };
}

