#pragma once
#include "pch.h"
#include "RepoBase.h"
#include "Student.h"

namespace KidzCashCore {
	template<typename T>
	class InMemoryRepo : public RepoBase<T>
	{
		static_assert(std::is_base_of<RepoItem, T>::value, "T must be derived from RepoItem!");
	public:
		virtual void Create(T);
		virtual std::vector<T> Read();
		virtual T* ReadById(int);
		virtual void Update(int, T);
		virtual void Delete(int);
		//Read part of CRUD
		std::vector<T> getItems() { return Read(); }
	protected:
		std::vector<T> items;

	};
}

