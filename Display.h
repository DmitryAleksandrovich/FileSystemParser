#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <io.h>
#include <string>
#include <memory>
#include "Component.h"
#include "Folders.h"
#include "Files.h"

/* Convenience class for user interaction */
namespace dl
{
	class Display
	{
	public:
		Display(std::string const& initalRoot);
		~Display();
		void TreeTraversal(std::tr1::shared_ptr<ct::Component> ob); // Read the directory tree
		void UserInteraction(std::tr1::shared_ptr<ct::Component> ob); // Function for user interaction
		void SetRoot(std::string const& newRoot); // Change root
		std::string GetPathDirectory() const; // Get path root
	private:
		std::string pathDirectory;
		enum lenghtName
		{
			lenghtNameOnePoint = 1,
			lenghtNameTwoPoints = 2
		};
		/* Dissalow the implicit generation copy constructor and assignment operator */
		Display(Display const&);
		Display& operator=(Display const&);
	};
}

#endif // DISPLAY_H