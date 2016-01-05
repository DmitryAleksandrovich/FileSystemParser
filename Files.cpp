#include "Files.h"


Files::Files()
{
}


Files::~Files()
{
}

void Files::Search(std::string const& strKeyword)
{
	size_t found = GetName().find(strKeyword);
	if(found != std::string::npos)
	{
		std::cout << GetName() << '\n';
	}
}
