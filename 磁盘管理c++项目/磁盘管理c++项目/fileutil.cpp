#define  _CRT_SECURE_NO_WARNINGS 1
#include"fileutil.hpp"
void searchDir(const string& path, unordered_set<string> &subFiles)
{
	string matchFile = path + "\\" + "*.*";
	_finddata_t fileAttr;
	long handle = _findfirst(matchFile.c_str(), &fileAttr);
	if (handle == -1)
	{
		perror("search failed !");
		cout << matchFile << endl;
		return;
	}
	do
	{
		if (fileAttr.attrib & _A_SUBDIR)
		{
			if (strcmp(fileAttr.name, ".") && strcmp(fileAttr.name, ".."))
				searchDir(path + "\\" + fileAttr.name, subFiles);
		}
		else
		{
			subFiles.insert(path + "\\" + fileAttr.name);
		}
	} while (!_findnext(handle, &fileAttr));
	_findclose(handle);
}

void deleteFile(const char* filename)
{
	if (!remove(filename))
	{
		cout << "delete" << filename << "success" << endl;
	}
	else
	{
		perror("detele file failed");
	}
}