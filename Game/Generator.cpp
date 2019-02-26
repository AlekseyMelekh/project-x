#include "pch.h"

#include <iostream>
#include <fstream>
#include "Main.h"

void App::Generator()
{
	std::ofstream kek("D:/Projects/University/Game/Maps/1.map");
	for (int i = 0; i < MAP_WBLOCK; ++i)
	{
		for (int j = 0; j < MAP_HBLOCK; ++j)
		{
			kek << "0:2 ";
		}
		kek << "\n";
	}
	kek.close();
}
