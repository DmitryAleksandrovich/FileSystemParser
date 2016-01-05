#ifndef FILES_H
#define FILES_H
#include "Component.h"
#include <iostream>

class Files: public Component
{
public:
	Files();
	~Files();
	void Search(std::string const& strKeyword);
private:
	Files(Files const&);
	Files& operator=(Files const&);
};

#endif // FILES_H