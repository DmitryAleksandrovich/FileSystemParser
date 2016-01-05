#include <io.h>
#include <iostream>
#include <windows.h>
#include <memory>
#include "Component.h"
#include "Folders.h"
#include "Display.h"



int main(int argc, char* argv[])
{
	std::tr1::shared_ptr<Component> ob(new Folders);
	Display ds("D:\\GitHub");

	ds.UserInteraction(ob);
	
	return 0;
}

