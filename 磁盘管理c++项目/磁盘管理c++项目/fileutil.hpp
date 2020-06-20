#pragma once
#include<io.h>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;
void searchDir(const string& path, unordered_set<string> &subFiles);
void deleteFile(const char* filename);
