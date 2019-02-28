#include "pch.h"

#include <iostream>
#include <fstream>
#include "Main.h"

void App::Generator()
{
	srand(time(NULL));
	std::ofstream kek("Maps/1.map");
	for (int i = 0; i < MAP_WBLOCK; ++i)
	{
		for (int j = 0; j < MAP_HBLOCK; ++j)
		{
			if (j < 7)
				kek << "1:0 ";
			else {
				if (rand() & 1)
					kek << "0:2 ";
				else
					kek << "1:0 ";
			}
		}
		kek << "\n";
	}
	kek.close();
}
