#include "pch.h"
#include "RepoItem.h"

namespace KidzCashCore {
	int RepoItem::getId() const {
		return Id;
	}

	void RepoItem::setId(int id) {
		Id = id;
	}
}
