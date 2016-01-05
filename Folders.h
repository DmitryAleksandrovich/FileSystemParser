#ifndef FOLDERS_H
#define FOLDERS_H
#include "Component.h"
#include <vector>

class Folders: public Component
{
public:
	Folders();
	~Folders();
	void AddComponent(std::tr1::shared_ptr<Component> pComp);
	void Search(std::string const& strKeyword);
	void RemoveComponent();
private:
	std::vector<std::tr1::shared_ptr<Component>> vComp;
	Folders(Folders const&);
	Folders& operator=(Folders const&);
};

#endif // FOLDERS_H