#pragma once
#include "pch.h"
#include "RepoItem.h"

namespace KidzCashCore {
	//namespace Shop {
		class ShopItem : public RepoItem
		{
		public:
			ShopItem(int id, std::string name, float price, int quantity) :
				RepoItem(id), name(name), price(price), quantity(quantity) {}

		private:
			std::string name;
			float price;
			int quantity;
		};
	//}
}

