#pragma once
#include "pch.h"
#include "ShopManager.h"

namespace KidzCashCore {
	ShopManager::ShopManager() : ShopManager("Shop.KCC", 10) {

	}
	ShopManager::ShopManager(std::string filename) : ShopManager(filename, 10) {
	}
	ShopManager::ShopManager(std::string filename, int displayCount) 
		: shopItems(filename), paginator(displayCount) {
	}

	void ShopManager::AddShopItem(ShopItem& item) {
		shopItems.Create(item);
	}

	void ShopManager::RemoveShopItem(ShopItem& item) {
		shopItems.Delete(item.getId());
	}

	void ShopManager::EditShopItem(int id, ShopItem& updated) {
		shopItems.Update(id, updated);
	}

	ShopItem* ShopManager::GetShopItemById(int id) {
		return shopItems.ReadById(id);
	}

	//I think that I will decide to move this into a different class that has both a StudentManager
	//and a ShopManager because then I can make sure that it gets saved to the file... where if I
	//do it here, then great I modified the student, but it doesn't actually save anything to the 
	//file lol...
	/*bool ShopManager::MakePurchase(Student& s, Transaction& t) {
		s.addTransaction(t);

		return false;
	}*/

	std::vector<ShopItem> ShopManager::GetAllShopItems() {
		return shopItems.Read();
	}
	
	std::vector<ShopItem> ShopManager::GetNextShopItems() {
		return paginator.GetNextItems(shopItems.Read());
	}

	std::vector<ShopItem> ShopManager::GetPreviousShopItems() {
		return paginator.GetPrevItems(shopItems.Read());
	}

	void ShopManager::setStart(int s) {
		paginator.setStart(s);
	}
	void ShopManager::setDisplayCount(int d) {
		paginator.setDisplayCount(d);
	}
}