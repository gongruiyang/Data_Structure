#include <iostream>
#include <vector>
#include <string>
#include "E:\������\�����\���ѧϰ����\01 �������\02 C++\boost_1_75_0\boost\algorithm\string.hpp"
using namespace std;


void TestSplit()
{
	vector<string> strout;
	string strstr = "https://www.baidu.com";

	boost::split(strout, strstr, boost::is_any_of("./"), boost::token_compress_on);
	for (auto e : strout)
	{
		cout << e << endl;
	}
	cout << endl;
}

int main()
{
	TestSplit();
	return 0;
}