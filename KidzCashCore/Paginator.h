#pragma once
#include "pch.h"

namespace KidzCashCore {
	
	template<typename T>
	class Paginator {
	public:
		Paginator(std::vector<T> items, int displayCount) 
			: items(items), start(0), displayCount(displayCount) {}
		Paginator(std::vector<T> items, int start, int displayCount) 
			: items(items), start(start), displayCount(displayCount) {}
		void setDisplayCount(int c) { displayCount = c; }
		void setStart(int s) { start = s; }
		int GetStart() { return start; }
		std::vector<T> GetNextItems() {
			int size = items.size();
			if (displayCount >= size) {
				return items;
			}
			else {
				std::vector<T> output;
				for (int i = 0; i < displayCount; ++i) {
					int index = (start + i) % size;
					output.push_back(items[index]);
				}
				start = (start + displayCount) % size;
				return output;
			}
		}
		std::vector<T> GetPrevItems() {
			int size = items.size();
			if (displayCount >= size) {
				return items;
			}
			else {
				start = (start - displayCount + size) % size;
				std::vector<T> output;
				for (int i = 0; i < displayCount; ++i) {
					int index = (start + i) % size;
					output.push_back(items[index]);
				}
				return output;
			}
		}
	protected:
		std::vector<T> items;
		int displayCount;
		int start;
	};
}