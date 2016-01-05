#include "Display.h"

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

void Display::TreeTraversal(std::tr1::shared_ptr<Component> ob)
{
	_finddata_t findData;
	intptr_t done;
	std::string tempPath = GetPathDirectory() + "\\";
	std::string fileName = GetPathDirectory() + "\\*";
	done = _findfirst(fileName.c_str(), &findData);
	bool isDone = (done != -1L);
	if(isDone)
	{
		do
		{
			bool isName = ((strlen(findData.name) == 1) && (findData.name[0] == '.')) ||
				((strlen(findData.name) == 2) && (strstr(findData.name, "..")));
			if(!isName)
			{
				if(findData.attrib & _A_SUBDIR)
				{
					std::tr1::shared_ptr<Component>obCurrent(new Folders);
					ob->AddComponent(obCurrent);
					SetRoot(tempPath + static_cast<std::string>(findData.name));
					obCurrent->SetName(findData.name);
					TreeTraversal(obCurrent);
					SetRoot(tempPath);
				}
				else
				{
					std::tr1::shared_ptr<Component>obCurrent(new Files);
					ob->AddComponent(obCurrent);
					obCurrent->SetName(findData.name);
				}
			}
		}
		while(!_findnext(done, &findData));
		_findclose(done);
	}
}

void Display::UserInteraction(std::tr1::shared_ptr<Component> ob)
{
	TreeTraversal(ob);
	std::string strStream, strOption;
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
			ob->Search(strStream);
			std::cout << '\n';			
		}
		else if(isStrOptionCd)
		{
			ob->RemoveComponent();
			std::cout << "Enter new root: ";
			std::cin >> strStream;
			SetRoot(strStream);
			TreeTraversal(ob);
			std::cout << '\n';			
		}
		else
		{
			continue;
		}
	}
}
