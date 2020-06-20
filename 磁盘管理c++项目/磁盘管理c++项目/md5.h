#ifndef MD5_H_
#define MD5_H_
#endif
#pragma once
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<fstream>
using namespace std;
typedef unsigned int uint32;
#define SIZE 64
class MD5
{
public:
	MD5()
	{
		init();
	}
	uint32 F(uint32 x, uint32 y, uint32 z)
	{
		return (x & y) | ((~x) & z);
	}
	uint32 G(uint32 x, uint32 y, uint32 z)
	{
		return (x & z) | (y & (~z));
	}
	uint32 H(uint32 x, uint32 y, uint32 z)
	{
		return  x ^ y ^ z;
	}
	uint32 I(uint32 x, uint32 y, uint32 z)
	{
		return   y ^ (x | (~z));
	}
	void init();
	uint32 leftShift(uint32 sum, uint32 s)
	{
		return (sum << s) | (sum >> (32 - s));
	}
	void calMD5(uint32* chunk);
	void calFinalMD5();
	void reset();
	std::string getStringMD5(const std::string& str);
	std::string getFileMD5(const char *filePath);
	std::string chageHex(uint32 n);
private:
	static int _leftShift[64];
	uint32 _k[SIZE];
	char _chunk[SIZE];
	uint32 _lastByte;
	uint32 _totalByte;
	uint32 _a;
	uint32 _b;
	uint32 _c;
	uint32 _d;
};