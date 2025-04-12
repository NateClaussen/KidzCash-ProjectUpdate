#pragma once
#include "pch.h"
#include "InMemoryRepo.h"

namespace KidzCashCore {
	template<typename T>
	class InMemoryRepo;

	template<typename T>
	void InMemoryRepo<T>::Create(T item) {
		if (item.getId() <= 0)
			item.setId(items.size() + 1);
		items.push_back(item);
	}

	template<typename T>
	std::vector<T> InMemoryRepo<T>::Read() {
		return items;
	}

	template<typename T>
	T* InMemoryRepo<T>::ReadById(int id) {
		for (T& s : items) {
			if (s.getId() == id) {
				return &s;
			}
		}
		std::cout << "Item Not Found" << std::endl;
		return nullptr;
	}

	template<typename T>
	void InMemoryRepo<T>::Update(int id, T updated) {
		T* searched = ReadById(id);
		if (searched->getId() > 0) {
			*searched = updated;
		}
		else {
			Create(updated);
		}
		//For the file one, I'll have to figure out how to save to that specific spot in the file
		//to save that specific student...
		//what I end up doing is over-writing the file every time with the current state of the vector
	}

	template<typename T>
	void InMemoryRepo<T>::Delete(int id) {
		items.erase(std::remove_if(items.begin(), items.end(),
			[id](const T& s) {
				return (s.getId() == id);
			}
		), items.end());
		/*Student searched = ReadById(id);
		if (searched.getId() > 0) {
			students.erase(find(students.begin(), students.end(), searched));
		}*/
	}
}