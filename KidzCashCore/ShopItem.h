#pragma once
#include "pch.h"
#include "RepoItem.h"

namespace KidzCashCore {
	//namespace Shop {
		class ShopItem : public RepoItem
		{
		public:
			ShopItem();
			ShopItem(int id, std::string name, float price, int quantity) :
				RepoItem(id), name(name), price(price), quantity(quantity) {}
			std::string toStr() const;
			void fromStr(const std::string&);
		private:
			std::string name;
			float price;
			int quantity;
		};
	//}
}

