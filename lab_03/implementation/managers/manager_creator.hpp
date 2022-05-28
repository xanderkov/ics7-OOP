#pragma once

# include <iostream>
# include <memory>
# include "manager.hpp"


using namespace std;

template <typename ConManager>
class ManagerCreator
{
public:
	shared_ptr<ConManager> getManager() {
		if (!manager)
		{
			manager = createManager();
		}

		return manager;
	}
protected:
	virtual shared_ptr<ConManager> createManager()
	{
		return shared_ptr<ConManager>(make_shared<ConManager>());
	}
private:
	shared_ptr<ConManager> manager = nullptr;
};
