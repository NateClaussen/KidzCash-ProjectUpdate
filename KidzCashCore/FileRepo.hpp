#pragma once
#include "pch.h"
#include "FileRepo.h"

namespace KidzCashCore {

	template<typename T>
	FileRepo<T>::FileRepo(std::string filename) :filename(filename){
		Load();
	}

	template<typename T>
	void FileRepo<T>::Create(T item) {
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
			cerr << "Could not open file to save to file." << endl;
			return;
		}
		for (const T& item : items) {
			out << item.toStr() << "\n";
		}
	}

	template<typename T>
	void FileRepo<T>::Load() {
		std::ifstream fin(filename);
		std::string line;
		while (std::getline(fin, line)) {
			T item;
			item.fromStr(line);
			items.push_back(item);
		}
	}
}

