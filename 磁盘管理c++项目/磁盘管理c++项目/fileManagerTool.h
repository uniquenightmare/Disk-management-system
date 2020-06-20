#pragma once
#include"FileManger.h"
class FileMangerTool
{
public:
	void scanner();
	void delteByName();
	
	void deleteALL();
	
	void deleteFuzzyMatch();
	
private:
	FileManger fm;
};