#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool static findNumberIn2DArray(vector<vector<int>>& v, int target)
	{

		if (v.size() == 0 || v[0].size()) return false;

		int rows = v.size();
		int cols = v[0].size();

		int col = cols - 1, row = 0;
		while (col >= 0 && row < rows)
		{
			if (v[row][col] < target)
				row++;
			else if (v[row][col] > target)
				col--;
			else
				return true;
		}
		return false;
	}
};

int main()
{
	vector<vector<int>> v = {
		{ 1, 4, 7, 11, 15 },
		{ 2, 5, 8, 12, 19 },
		{ 3, 6, 9, 16, 22 },
		{ 10, 13, 14, 17, 24 },
		{ 18, 21, 23, 26, 30 }
	};
	int target = 5;
	Solution::findNumberIn2DArray(v, target);

	return 0;
}