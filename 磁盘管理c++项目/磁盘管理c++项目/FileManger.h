#pragma
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include"md5.h"
using namespace std;
class FileManger
{
public:
	void scannerDir(const string&path);
	void deleteByName(const string& FileName);
	void deleteMD5(const string& md5);
	void deleteAllDuplicateFile();
	void deleteFile(const string& FileName);
	void getCopyList();
	void getMD5toFiles();
	void showCopyList();
	void showAllFile();
private:
	unordered_set<string> files;
	unordered_multimap<string, string> md5tofile;
	unordered_map<string, string> filetomd5;
	MD5 md5;
};