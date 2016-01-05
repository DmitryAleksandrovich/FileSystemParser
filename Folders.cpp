#include "Folders.h"

Folders::Folders()
{
}


Folders::~Folders()
{
}

void Folders::AddComponent(std::tr1::shared_ptr<Component> pComp)
{
	vComp.push_back(pComp);
}

void Folders::Search(std::string const& strKeyword)
{
	for (unsigned i = 0; i < vComp.size(); i++)
	{
		vComp[i]->Search(strKeyword);
	}
}

void Folders::RemoveComponent()
{
	vComp.clear();
}
