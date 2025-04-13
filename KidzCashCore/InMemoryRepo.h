#pragma once
#include "pch.h"
#include "RepoBase.h"
#include "Student.h"
#include "Transaction.h"
#include <algorithm>

namespace KidzCashCore {
	template<typename T>
	class InMemoryRepo : public RepoBase<T>
	{
		static_assert(std::is_base_of<RepoItem, T>::value, "T must be derived from RepoItem!");
	public:
		InMemoryRepo() {}
		virtual void Create(const T&);
		virtual std::vector<T> Read();
		virtual T* ReadById(int);
		virtual void Update(int, T);
		virtual void Delete(int);
		//Read part of CRUD
		std::vector<T> getItems() { return Read(); }
	protected:
		std::vector<T> items;

	};

	//template<typename T>
//class InMemoryRepo;

	template<typename T>
	void InMemoryRepo<T>::Create(const T& item) {
		//I ran into some const issues with setting the ID and decided to auto-populate the
		//Id here in the create method. 
		T newItem = item;

		bool idTaken = std::any_of(items.begin(), items.end(), [&](const T& i) {
			return i.getId() == newItem.getId();
			});

		if (newItem.getId() <= 0 || idTaken) {
			int newId = (int)items.size() + 1;
			while (std::any_of(items.begin(), items.end(), [&](const T& i) {return i.getId() == newId; })) {
				++newId;
			}
			newItem.setId(newId);
		}

		items.push_back(newItem);


		//if (item.getId() <= 0)
			//item.setId((int)items.size() + 1);
		//items.push_back(item);
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

#include "InMemoryRepo.hpp"

