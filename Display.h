#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <io.h>
#include <string>
#include <memory>
#include "Component.h"
#include "Folders.h"
#include "Files.h"

namespace dl
{
	class Display
	{
	public:
		Display(std::string const& initalRoot);
		~Display();
		void TreeTraversal(std::tr1::shared_ptr<ct::Component> ob);
		void UserInteraction(std::tr1::shared_ptr<ct::Component> ob);
		void SetRoot(std::string const& newRoot);
		std::string GetPathDirectory() const;
	private:
		std::string pathDirectory;
		Display(Display const&);
		Display& operator=(Display const&);
	};
}

#endif // DISPLAY_H