#include"FileManger.h"
#include"fileutil.hpp"

void FileManger::scannerDir(const string&path)
{
	files.clear();
	searchDir(path, files);
	showAllFile();
	getMD5toFiles();
	getCopyList();
	showCopyList();
	showAllFile();
}
void FileManger::getCopyList()
{
	filetomd5.clear();
	std::unordered_map<string, string>::iterator it =md5tofile.begin();
	while (it != md5tofile.end())
	{
		if (md5tofile.count(it->first) > 1)
		{
			auto pairIt = md5tofile.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second)
			{
				filetomd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			it = pairIt.second;
		}
		else
		{
			files.erase(it->second);
			it = md5tofile.erase(it);
			
		}
		
	}
}
void FileManger::getMD5toFiles()
{
	md5tofile.clear();
	for (auto &ch : files)
	{
		md5.reset();
		md5tofile.insert(make_pair(md5.getFileMD5(ch.c_str()), ch));
	}
}
void FileManger::deleteByName(const string& FileName)
{
	if (!filetomd5.count(FileName))
	{
		cout << "no exist!" << endl;
		return;
	}
	deleteMD5(filetomd5[FileName]);
}
void FileManger::deleteMD5(const string& md5)
{
	if (!md5tofile.count(md5))
	{
		cout << "no exist!" << endl;
		return;

	}
	auto pairIt = md5tofile.equal_range(md5);
	cout << md5 << "--->" << md5tofile.count(md5) << endl;
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second)
	{
		files.erase(curIt->second);
		filetomd5.erase(curIt->second);
		deleteFile(curIt->second.c_str());
		++count;
	}
	curIt = pairIt.first;
	++curIt;
	md5tofile.erase(curIt, pairIt.second);
}
void FileManger::deleteAllDuplicateFile()
{
	unordered_set<string> md5set;
	for (auto &ch : md5tofile)
	{
		md5set.insert(ch.first);
	}
	for (auto &ch : md5set)
	{
		deleteMD5(ch);
	}
}
void FileManger::deleteFile(const string& FileName)
{
	unordered_set<string>allFiles;
	for (auto &ch : files)
	{
		if (ch.find(FileName) != string::npos)
			allFiles.insert(ch);
	}
	for (auto ch : allFiles)
	{
		if (!filetomd5.count(ch))
		{
			deleteByName(ch);
		}
	}
}
void FileManger::showCopyList()
{
	auto it = md5tofile.begin();
	int size = md5tofile.size();
	int count = 0;
	while (it != md5tofile.end())
	{
		int id = 1;
		auto pairIt = md5tofile.equal_range(it->first);
		auto curIt = pairIt.first;
		cout << "Cur Md5:" << it->first << endl;
		while (curIt != pairIt.second)
		{
			cout << "\t第" << id << "个文件: ";
			cout << curIt->second << endl;
			count++;
		}
		it = pairIt.second;
	}
	cout << "文件大小:" << size << "\t" << count << endl;
}
void FileManger::showAllFile()
{
	for (auto &ch : files)
	{
		cout << ch << endl;
	}
}
