#include "pch.h"
#include "RepoBase.h"
#include "RepoItem.h"


namespace KidzCashCore {
	template<class T>
	RepoBase<T>::RepoBase() {

	}
	template<class T>
	void RepoBase<T>::Create(T item) {
		std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	}

	//std::vector<RepoItem*> RepoBase::Read() {
	//	std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	//	//Hopefully this doesn't create a memory leak
	//	std::vector<RepoItem*> items;
	//	return items;
	//}

	//RepoItem RepoBase::ReadById(int id) {
	//	std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	//	RepoItem item(-1);
	//	return item;
	//}

	template<class T>
	void RepoBase<T>::Update(int id, T&) {
		std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	}

	template<class T>
	void RepoBase<T>::Delete(int id) {
		std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	}
	
}