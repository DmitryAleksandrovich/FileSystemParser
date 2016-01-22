#include "Component.h"
#include "Folders.h"
#include "Display.h"



int main(int argc, char* argv[])
{
	std::tr1::shared_ptr<ct::Component> ob(new fr::Folders);
	dl::Display ds("C:\\Program Files\\Common Files"); // Specifies the root

	ds.UserInteraction(ob);
	
	return 0;
}

