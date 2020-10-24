#include <iostream>
#include <algorithm>
using namespace std;
const int M = 27;
int f[27];

void Test()
{
	f[0] = 0;
	int A[3] = { 2, 5, 7 };
	int n = 3;
	for (int i = 1; i <= M;++i)
	{
		//f[i] = min{f[i-A[0]] + 1.....f[i-A[n-1]]+1}
		for (int j = 0; j < n;++j)
		{
			if (i >= A[j] && f[i - A[j]] != INT_MAX)
			{
				f[i] = min(f[i - A[j]] + 1, f[i]);
			}
		}
	}
	if (f[M] ==  INT_MAX)
		f[M] = -1;
	cout << f[M] << endl;
}

int main()
{
	//cout << A(23) << endl;
	Test();
	system("pause");
	return 0;
}