#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <io.h>
#include <string>
#include <memory>
#include "Component.h"
#include "Folders.h"
#include "Files.h"

class Display
{
public:
	Display(std::string const& initalRoot);
	~Display();
	void TreeTraversal(std::tr1::shared_ptr<Component> ob);
	void UserInteraction(std::tr1::shared_ptr<Component> ob);
	void SetRoot(std::string const& newRoot);
	std::string GetPathDirectory() const;
private:
	std::string pathDirectory;
};

#endif // DISPLAY_H