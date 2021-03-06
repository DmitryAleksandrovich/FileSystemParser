#include "Folders.h"

using namespace fr;

Folders::Folders()
{
}


Folders::~Folders()
{
}

void Folders::AddComponent(std::tr1::shared_ptr<Component> pComp)
{
	vComp.push_back(pComp); // Add component in vector
}

void Folders::Search(std::string const& strKeyword)
{
	for (unsigned i = 0; i < vComp.size(); ++i)
	{
		vComp[i]->Search(strKeyword); // Search in all containers
	}
}

void Folders::RemoveComponent()
{
	vComp.clear(); // Clear all components
}
