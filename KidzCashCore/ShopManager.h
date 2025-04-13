#pragma once
#include "pch.h"
#include "FileRepo.h"
#include "ShopItem.h"
#include "Paginator.h"

namespace KidzCashCore {
	class ShopManager {
	public:
		//Constructors
		ShopManager();
		ShopManager(std::string);
		ShopManager(std::string filename, int displayCount);

		void AddShopItem(ShopItem&);
		void RemoveShopItem(ShopItem&);
		void EditShopItem(int, ShopItem&);
		ShopItem* GetShopItemById(int id);

		//Maybe I move this function to a different class? One that's 
		// higher voidup the food chain?
		//bool MakePurchase(Student&, Transaction&);


		//Pagination
		std::vector<ShopItem> GetAllShopItems();
		std::vector<ShopItem> GetNextShopItems();
		std::vector<ShopItem> GetPreviousShopItems();
		void setStart(int);
		void setDisplayCount(int);

	protected:
		FileRepo<ShopItem> shopItems;
		Paginator<ShopItem> paginator;
	};
}