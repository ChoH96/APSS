//https://algospot.com/judge/problem/read/POLY
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


// little bit hard to use memorization
//start with (start) blocks + (left) blocks is  
//total left + start box used
int poly(vector<vector<int>> &mem, int left, int start) {
	int i;
	int ret = 0;
	if (mem[left][start] != -1) return mem[left][start];

	for (i = 1; i <= left; i++) {
		ret += (start + i - 1) * poly(mem, left - i, i);
		ret = ret % 10000000;
	}
	mem[left][start] = ret;

	return ret;
}



int main()
{
	int i, j, tmp;
	int testCase;
	int size;

	vector<vector<int>> mem(101, vector<int>(101, -1));//mem[left][start]
	for (i = 0; i < mem[0].size(); i++) {
		mem[0][i] = 1;
	}


	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> size;
		
		int ret = 0;
		for (i = 1; i <= size; i++) {
			ret += poly(mem, size - i, i);
			ret = ret % 10000000;
		}
		cout << ret << '\n';

		testCase--;
	}
	return 0;
}