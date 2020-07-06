#define  _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;
class BitMap
{
public:
	BitMap(size_t range)
	{
		vec.resize((range >> 5)+1);
	}
	void set(int data)
	{
		int idx = data >> 5;
		int bitidx = data % 32;
		vec[idx] |= 1 << bitidx;
	}
	bool test(int data)
	{
		int idx = data >> 5;
		int bitidx = data % 32;
		return (vec[idx] >> bitidx) & 1;
	}
	void reset(int data)
	{
		int idx = data >> 5;
		int bitidx = data % 32;
		vec[idx] &= ~(1 << bitidx);
	}
private:
	vector<int> vec;
};
void test()
{
	BitMap bm(500);
	bm.set(16);
	bm.set(63);
	cout << bm.test(63) << endl;
	cout << bm.test(16) << endl;
	cout << bm.test(0) << endl;
}
int main()
{
	test();
	system("pause");

	return 0;
}