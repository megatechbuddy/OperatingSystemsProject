// Author: Sean Benson, Pho
#include "stdafx.h"
#include "OperatingSystemsProject.h"

OperatingSystemsProject::OperatingSystemsProject()
{
	Menu();
	system("pause");
}

void OperatingSystemsProject::Menu()
{
	memoryStructureManager.getFAT();
	DisplayInstructions();
	DisplayFiles();
	GiveOptions();
}

void OperatingSystemsProject::DisplayInstructions()
{
	std::cout << "Do Stuff." << "\n";
}

void OperatingSystemsProject::DisplayFiles()
{
	fat = memoryStructureManager.getFAT();
	//display files in fat
	for (int i = 0; i < fat->fileList.size(); i++) {
		FAT::CSC322FILE tempFile = fat->fileList[i];
		//write files into it
		//writing the file works
		//fwrite, ftell
		std::vector<Drivers::Word> writeWords;
		for (unsigned int i=0; i < 100; i++) {
			Drivers::Word tempWord;
			tempWord.letter1 = 66;
			tempWord.letter2 = 66;
			writeWords.push_back(tempWord);
		}
		if (tempFile.Deleted == true) {
			//do garbage collection
		}
		else {
			//is it a fat?
			if (tempFile.FAT == true) {
				//do some recursion to it

			}
			else {
				//see if it is a file
				//it is usable
				if (tempFile.Used == true) {
					//put something in it then display it
					memoryStructureManager.CSC322_fwrite(writeWords, tempFile);
					//display it
					//reading the file works
					std::cout << "File Name: " << tempFile.name << "\n";
					std::vector<Drivers::Word> words = memoryStructureManager.CSC322_fopen(tempFile);
					memoryStructureManager.CSC322_fread(words, 0);
				}
				else {
					//leave it empty
				}
			}
		}
	}

	int success = memoryStructureManager.CSC322_fseek(fat->getCSC322FILE(0).TotalBlocks,fat->getCSC322FILE(0).StartBlock);
					
	

	//memoryStructureManager.CSC322_remove(fat.getCSC322FILE(0));

	//check removing file

	//int success2 = memoryStructureManager.cs
	//if (success) {
	//	//TODO: loop through all files
	//	std::cout << fat->getCSC322FILE(0).name << "\n";
	//}
	//else {
	//	std::cout << "Failed to find files." << "\n";
	//}
	
	//TODO
	std::cout << "Find files." << "\n";
}

void OperatingSystemsProject::GiveOptions()
{
	std::cout << "Select File to View" << "\n";
	std::cout << "Select File to Remove" << "\n";

}

OperatingSystemsProject::~OperatingSystemsProject()
{
}

int main()
{
	OperatingSystemsProject operatingSystemsProject;
	return 0;
}