#include "Files.h"

using namespace fl;

Files::Files()
{
}


Files::~Files()
{
}

void Files::Search(std::string const& strKeyword)
{
	/* Search by substring */
	size_t found = GetName().find(strKeyword);
	if(found != std::string::npos)
	{
		std::cout << GetName() << '\n'; // Displays filename
	}
}
