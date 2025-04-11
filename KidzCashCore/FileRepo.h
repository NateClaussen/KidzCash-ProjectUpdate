#pragma once
#include "InMemoryRepo.hpp"

namespace KidzCashCore {
	/// <summary>
	/// I will fully admit that I got the idea of how to implement this
	/// online. 
	/// Based off of what I was reading, extending the InMemroyRepo and just overriding
	/// everything in the file each time you write with what is saved in
	/// memory is probably the easiest way to implement the file system that
	/// I am trying to achieve. There shouldn't be a SUPER amount of items in the shop
	/// or students, so this should not affect performance or memory too much :)
	/// </summary>
	/// <typeparam name="T">RepoItem</typeparam>
	template<typename T> 
	class FileRepo : InMemoryRepo<T> {
		static_assert(std::is_base_of<RepoItem, T>::value, "T must be derived from RepoItem!");
	public:
		FileRepo(std::string filename) : filename(filename) {}
		void Create(T item);
		void Update(int, T);
		void Delete(int);

		/// <summary>
		/// Each time that you add/change/remove anything, you save to the file
		/// the contents that are in the InMemoryVector
		/// </summary>
		void Save();
		/// <summary>
		/// When the class is initialized, you can Load the vector of items from the
		/// file. 
		/// </summary>
		void Load();
	private:
		std::string filename;
	};
}