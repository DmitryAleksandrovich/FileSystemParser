#include "Display.h"

using namespace dl;

Display::Display(std::string const& initalRoot)
{
	pathDirectory = initalRoot;
}


Display::~Display()
{
}

std::string Display::GetPathDirectory() const
{
	return pathDirectory;
}

void Display::SetRoot(std::string const& newRoot)
{
	pathDirectory = newRoot;
}

void Display::TreeTraversal(std::tr1::shared_ptr<ct::Component> ob)
{
	_finddata_t findData;
	intptr_t done;
	std::string tempPath = GetPathDirectory() + "\\"; // Add slashes
	std::string fileName = GetPathDirectory() + "\\*"; // Search all files and folders
	done = _findfirst(fileName.c_str(), &findData); // First element of search
	bool isDone = (done != -1L);
	if(isDone)
	{
		do
		{
			bool isName = ((strlen(findData.name) == 1) && (findData.name[0] == '.')) ||
				((strlen(findData.name) == 2) && (strstr(findData.name, ".."))); // Ignore folders names "." and ".."
			if(!isName)
			{
				if(findData.attrib & _A_SUBDIR)
				{
					/* Read and write in vector information folders */
					std::tr1::shared_ptr<ct::Component>obCurrent(new fr::Folders);
					ob->AddComponent(obCurrent); // Add new folder
					SetRoot(tempPath + static_cast<std::string>(findData.name)); // Add to path folder name
					obCurrent->SetName(findData.name); // Write folder name
					TreeTraversal(obCurrent); // Recursive function call
					SetRoot(tempPath); // Restoring the path
				}
				else
				{
					/* Read and write in vector information files */
					std::tr1::shared_ptr<ct::Component>obCurrent(new fl::Files);
					ob->AddComponent(obCurrent); // Add new file
					obCurrent->SetName(findData.name); // Write filename
				}
			}
		}
		while(!_findnext(done, &findData));
		_findclose(done);
	}
}

/* Get the user's commands and run a search in the catalog or change the root */
void Display::UserInteraction(std::tr1::shared_ptr<ct::Component> ob)
{
	TreeTraversal(ob); // Read function directory
	std::string strStream, strOption; // Values for ui
	while(1)
	{
		std::cout << "Current directory: " << pathDirectory << '\n';
		std::cout << "If you want to search files in the current directory, enter \"DIR\".";
		std::cout << "If you want to change root directory, enter \"CD\"\n";
		std::cin >> strOption;
		bool isStrOptionDir = (strOption == "DIR" || strOption == "dir");
		bool isStrOptionCd = (strOption == "CD" || strOption == "cd");
		if(isStrOptionDir)
		{
			std::cout << "Enter the full name or part of the file name: ";
			std::cin >> strStream;
			std::cout << "\nSearch results files:\n";
			ob->Search(strStream); // Run search
			std::cout << '\n';			
		}
		else if(isStrOptionCd)
		{
			ob->RemoveComponent();
			std::cout << "Enter new root: ";
			std::cin >> strStream;
			SetRoot(strStream); // Charge root
			TreeTraversal(ob); // Read function directory
			std::cout << '\n';			
		}
		else
		{
			continue;
		}
	}
}
