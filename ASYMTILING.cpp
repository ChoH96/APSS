//https://algospot.com/judge/problem/read/ASYMTILING
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


//simple math with memorization
int tiling(vector<int>& mem, int size) {
	int ret;
	if (mem[size] != -1) return mem[size];

	ret = (tiling(mem, size - 1) + tiling(mem, size - 2)) % 1000000007;
	mem[size] = ret;
	return ret;
}

//use tiling function
int asymTiling(vector<int>& mem, int size) {
	int tmp, ret;
	
	ret = tiling(mem, size);
	if (size % 2 == 0) {
		tmp = (tiling(mem, size / 2) + tiling(mem, size / 2 - 1)) % 1000000007;
	}
	else {
		tmp = tiling(mem, size / 2);
	}
	ret = (ret - tmp + 1000000007) % 1000000007;

	return ret;
}

int main()
{
	int i, j, tmp;
	int testCase;
	int size;

	vector<int> mem(101, -1);
	mem[0] = 1;
	mem[1] = 1;
	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> size;

		cout << asymTiling(mem, size) << '\n';

		testCase--;
	}
	return 0;
}