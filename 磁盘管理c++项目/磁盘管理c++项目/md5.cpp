#define  _CRT_SECURE_NO_WARNINGS 1
#include"md5.h"

int MD5::_leftShift[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
void MD5::init()
{
	for (int i = 0; i < 64; i++)
	{
		_k[i] = static_cast<uint32>(abs(sin(i + 1.0) * pow(2.0, 32)));
	}
	reset();
}
void MD5::reset()
{
	_a = 0x67452301;
	_b = 0xefcdab89;
	_c = 0x98badcfe;
	_d = 0x10325476;
	memset(_chunk, 0, SIZE);
	_lastByte = _totalByte = 0;
}
void MD5::calMD5(uint32* chunk)
{
	int a = _a, b = _b, c = _c, d = _d;
	int f, g;
	for (int i = 0; i < 64; i++)
	{
		if (i >= 0 && i < 16)
		{
			f = F(b, c, d);
			g = i;
		}
		else if (i >= 16 && i < 32)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i < 48)
		{
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		int tmp = d;
		d = c;
		c = b;
		b += leftShift(a + f + chunk[g] + _k[i], _leftShift[i]);
		a = tmp;
	}
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}
void MD5::calFinalMD5()
{
	char *p = _chunk + _lastByte;
	*p++ = 0x80;
	int remainByte = SIZE - _lastByte - 1;
	if (remainByte < 8)
	{
		memset(p, 0, remainByte);
		calMD5((uint32*)_chunk);
		memset(_chunk, 0, SIZE);
	}
	else
	{
		memset(p, 0, remainByte);
	}
	unsigned long long totalBits = _totalByte;
	totalBits *= 8;
	((unsigned long long *)_chunk)[7] = totalBits;
	calMD5((uint32*)_chunk);
}
std::string MD5::getStringMD5(const std::string& str)
{
	if (str.empty())
	{
		return chageHex(_a).append(chageHex(_b)).append(chageHex(_c)).append(chageHex(_d));
	}
	_totalByte = str.size();
	uint32 chunkNum = _totalByte / SIZE;
	const char *strPtr = str.c_str();
	for (int i = 0; i < chunkNum; i++)
	{
		memcpy(_chunk, strPtr + i * SIZE, SIZE);
		calMD5((uint32*)_chunk);
	}
	_lastByte = _totalByte % SIZE;
	memcpy(_chunk, strPtr + chunkNum * SIZE, _lastByte);
	calFinalMD5();
	return chageHex(_a).append(chageHex(_b)).append(chageHex(_c)).append(chageHex(_d));
}
std::string MD5::getFileMD5(const char* filePath)
{
	ifstream fin(filePath, ifstream::binary);
	if (!fin.is_open())
	{
		cout << filePath;
		perror("file open failed!");
		return "";
	}
	while (!fin.eof())
	{
		/*fin.seekg(0, fin.end);
		uint32 length = fin.tellg();
		fin.seekg(0, fin.beg);
		char * totalData = new char[length];
		fin.read(totalData, length)*/;

		fin.read(_chunk, SIZE);
		if (SIZE != fin.gcount())
		{
			break;
		}
		_totalByte += SIZE;
		calMD5((uint32*)_chunk);
	}
	_lastByte = fin.gcount();
	_totalByte += _lastByte;
	calFinalMD5();
	return chageHex(_a).append(chageHex(_b)).append(chageHex(_c)).append(chageHex(_d));
}
std::string MD5::chageHex(uint32 n)
{
	string strMap = "0123456789abcdef";
	string ret;
	for (int i = 0; i < 4; i++)
	{
		int curByte = (n >> (i * 8)) & 0xff;
		string curstr;
		curstr += strMap[curByte / 16];
		curstr += strMap[curByte % 16];
		ret += curstr;
	}
	return ret;
}