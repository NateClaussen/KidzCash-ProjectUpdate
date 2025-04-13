#pragma once
#include "pch.h"
#include "InMemoryRepo.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

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
	class FileRepo : public InMemoryRepo<T> {
		static_assert(std::is_base_of<RepoItem, T>::value, "T must be derived from RepoItem!");
	public:
		FileRepo(std::string filename);
		void Create(const T& item);
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

	template<typename T>
	FileRepo<T>::FileRepo(std::string filename) :filename(filename) {
		Load();
	}

	template<typename T>
	void FileRepo<T>::Create(const T& item) {
		InMemoryRepo<T>::Create(item);
		Save();
	}

	template<typename T>
	void FileRepo<T>::Update(int id, T item) {
		InMemoryRepo<T>::Update(id, item);
		Save();
	}

	template<typename T>
	void FileRepo<T>::Delete(int id) {
		InMemoryRepo<T>::Delete(id);
		Save();
	}

	template<typename T>
	void FileRepo<T>::Save() {
		std::ofstream fout(filename);
		if (!fout) {
			std::cerr << "Could not open file to save to file." << std::endl;
			return;
		}
		for (const T& item : this->items) {
			fout << item.toStr() << "\n";
		}
	}

	template<typename T>
	void FileRepo<T>::Load() {
		std::ifstream fin(filename);
		std::string line;
		while (std::getline(fin, line)) {
			T item;
			item.fromStr(line);
			this->items.push_back(item);
		}
	}
}