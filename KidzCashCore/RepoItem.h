#pragma once
namespace KidzCashCore {
	class RepoItem
	{
	public:
		RepoItem(int id) : Id(id) {}
		int getId() const;
		void setId(int);
	private:
		int Id;
	};
}
