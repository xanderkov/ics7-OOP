#pragma once

#include <map>
#include <string>
#include "../load_director.hpp"

class DirectorSolution
{
	using CallBackMap = std::map<size_t, std::shared_ptr<LoadDirector>> ;

public:
	DirectorSolution() = default;

	template <typename Tprod>
	bool registration(size_t id);
	void initByConfig();
	bool check(size_t id) { return callbacks.erase(id) == 1; }

	std::shared_ptr<LoadDirector> createDirector(size_t id);

private:
	CallBackMap callbacks{};
};


