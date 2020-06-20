#include"fileManagerTool.h"
void FileMangerTool::scanner()
{
	cout << "input Dir_Name:" << endl;
	string path;
	getline(cin, path);
	fm.scannerDir(path);
}
void FileMangerTool::delteByName()
{
	cout << "Intput FileName:" << endl;
	string filename;
	getline(cin, filename);
	fm.deleteByName(filename);
}
void FileMangerTool::deleteALL()
{
	fm.deleteAllDuplicateFile();
}
void FileMangerTool::deleteFuzzyMatch()
{
	cout << "Intput FileName:" << endl;
	string filename;
	getline(cin, filename);
	fm.deleteFile(filename);
}