// Author: Sean Benson, Pho
#include "stdafx.h"
#include "MemoryStructureManager.h"

int main()
{
	FileManager fileManager();

	MemoryStructureManager memoryStructureManager(true);
	memoryStructureManager.~MemoryStructureManager();
	system("pause");
	return 0;
}