#ifndef FILES_H
#define FILES_H
#include "Component.h"
#include <iostream>

/* Implementation of the leaf object */
namespace fl
{
	class Files: public ct::Component
	{
	public:
		Files();
		~Files();
		void Search(std::string const& strKeyword) override; // Serch files
	private:
		/* Dissalow the implicit generation copy constructor and assignment operator */
		Files(Files const&);
		Files& operator=(Files const&);
	};
}

#endif // FILES_H