#include "Component.h"
#include <assert.h>


Component::Component()
{
}


Component::~Component()
{
}

void Component::AddComponent(std::tr1::shared_ptr<Component> pComp)
{
	assert(false);
}

void Component::RemoveComponent()
{
	assert(false);
}


void Component::SetName(std::string const& strName)
{
	name = strName;
}

std::string Component::GetName() const
{
	return name;
}
