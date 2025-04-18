#pragma once
#include <iostream>

namespace KidzCashCore {
	class RepoItem
	{
	public:
		RepoItem(int id) : Id(id) {}
		RepoItem() : Id(-1) {}
		int getId() const;
		void setId(int);
		virtual std::string toStr() const = 0;
		virtual void fromStr(const std::string&) = 0;
	private:
		int Id;
	};
}
