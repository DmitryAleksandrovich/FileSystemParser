#ifndef FOLDERS_H
#define FOLDERS_H
#include "Component.h"
#include <vector>

/* Implementation of the composite object */
namespace fr
{
	class Folders: public ct::Component
	{
	public:
		Folders();
		~Folders();
		void AddComponent(std::tr1::shared_ptr<Component> pComp) override; // Add component in vector
		void Search(std::string const& strKeyword) override; // Serch in catalog
		void RemoveComponent() override; // Clear vector
	private:
		std::vector<std::tr1::shared_ptr<Component>> vComp;
		/* Dissalow the implicit generation copy constructor and assignment operator */
		Folders(Folders const&);
		Folders& operator=(Folders const&);
	};
}

#endif // FOLDERS_H