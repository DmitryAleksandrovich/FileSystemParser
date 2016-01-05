#include <io.h>
#include <iostream>
#include <windows.h>
#include <memory>
#include "Component.h"
#include "Folders.h"
#include "Display.h"



int main(int argc, char* argv[])
{
	std::tr1::shared_ptr<ct::Component> ob(new fr::Folders);
	dl::Display ds("C:\\Program Files");

	ds.UserInteraction(ob);
	
	return 0;
}

