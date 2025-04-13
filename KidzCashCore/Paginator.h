#pragma once
#include "pch.h"

namespace KidzCashCore {
	
	template<typename T>
	class Paginator {
	public:
		//I originally started with the full set in the paginator, but I realized
		//That unless I create a new paginator each time, it would never update
		//the list that I needed to paginate from if there were any updates
		Paginator(int displayCount) 
			: start(0), displayCount(displayCount) {}
		Paginator(int start, int displayCount) 
			: start(start), displayCount(displayCount) {}
		void setDisplayCount(int c) { displayCount = c; }
		void setStart(int s) { start = s; }
		int GetStart() { return start; }
		std::vector<T> GetNextItems(std::vector<T> items) {
			int size = (int)items.size();
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
		std::vector<T> GetPrevItems(std::vector<T> items) {
			int size = (int)items.size();
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

		//Later I can add a function to sort the data before paginating it... by Id or alphabetically?
	protected:
		//std::vector<T> items;
		int displayCount;
		int start;
	};
}