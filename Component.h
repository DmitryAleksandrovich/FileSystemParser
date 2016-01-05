#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <memory>

/* The abstract base class for files and folders */
namespace ct
{
	class Component
	{
	public:
		Component();
		virtual ~Component();
		virtual void AddComponent(std::tr1::shared_ptr<Component> pComp); // Add component in vector
		virtual void RemoveComponent(); // Clear vector
		virtual void Search(std::string const& strKeyword) = 0; // Serch in catalog
		void SetName(std::string const& strName);
		std::string GetName() const;
	private:
		std::string name;
	};
}

#endif // COMPONENT_H