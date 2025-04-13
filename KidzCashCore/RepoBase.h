#pragma once
#include "pch.h"
#include "RepoItem.h"

namespace KidzCashCore {
	//class RepoBase;

	template<typename T>
	class RepoBase 
	{
		static_assert(std::is_base_of<RepoItem, T>::value, "T must be derived from RepoItem!");
	public:
		RepoBase();
		/// <summary>
		/// Adds Item to repository
		/// </summary>
		/// <param name="obj"></param>
		virtual void Create(const T&);
		/// <summary>
		/// Returns all of the items in the repository
		/// I originally had this as a vector of pointers, but
		/// decided that it is better to just have the objects 
		/// (at least until I need to use it for polymorphism
		/// or more memory contorl. But honestly, I'd rather it just
		/// memory management for me on the heap! LOLz
		/// </summary>
		virtual std::vector<T> Read() = 0;
		virtual T* ReadById(int) = 0;
		/// <summary>
		/// Updates the first
		/// </summary>
		/// <param name="">The Id of the object you want to update</param>
		/// <param name="">The object you want to update</param>
		virtual void Update(int, T&);
		/// <summary>
		/// Deletes the object with that Id
		/// </summary>
		/// <param name="Id">Id of object to delete</param>
		virtual void Delete(int);
		virtual ~RepoBase() = default;
	protected:
		//I don't think that I need to have that in this base class?
		// As long as the children of this class implement the public
		// functions in some way, it doesn't really matter how they
		// save each item individually... i.e. in a database, in a
		// list, array, etc... as long as the public interface works, 
		// I don't really care lol. We love abstraction!
		//std::vector<RepoItem> items;
	};

	template<typename T>
	RepoBase<T>::RepoBase() {

	}

	template<typename T>
	void RepoBase<T>::Create(const T& item) {
		std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	}

	template<typename T>
	void RepoBase<T>::Update(int id, T&) {
		std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	}

	template<typename T>
	void RepoBase<T>::Delete(int id) {
		std::cout << "Uh oh! The polymorphism didn't work!" << std::endl;
	}
}

