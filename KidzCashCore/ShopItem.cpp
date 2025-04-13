#include "pch.h"
#include "ShopItem.h"


namespace KidzCashCore {
	ShopItem::ShopItem() : RepoItem() {
		name = "";
		price = 0;
		quantity = 0;
	}

	std::string ShopItem::toStr() const {
		std::stringstream ss;
		ss << getId() << "," << name << "," << price << "," << quantity;
		return ss.str();
	}

	void ShopItem::fromStr(const std::string& str) {
		std::stringstream ss(str);
		std::string next;

		std::getline(ss, next, ',');
		setId(std::stoi(next));

		std::getline(ss, name, ',');
		std::getline(ss, next, ',');
		price = std::stof(next);

		std::getline(ss, next, ',');
		quantity = std::stoi(next);
	}
}