#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <memory>

class Component
{
public:
	Component();
	virtual ~Component();
	virtual void AddComponent(std::tr1::shared_ptr<Component> pComp);
	virtual void RemoveComponent();
	virtual void Search(std::string const& strKeyword) = 0;
	void SetName(std::string const& strName);
	std::string GetName() const;
private:
	std::string name;
};

#endif // COMPONENT_H