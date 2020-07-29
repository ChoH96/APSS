//https://algospot.com/judge/problem/read/JUMPGAME
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//find answer in bounded area [start,end)
int jump(int r, int c, vector<vector<int>> arr, vector<vector<int>> &map) {
	if (r >= arr.size() || c >= arr.size()) {
		return 0;
	}
	if (map[r][c] != -1) {
		return map[r][c];
	}

	int jumpSize = arr[r][c];
	int answer = (jump(r + jumpSize, c, arr, map) || jump(r, c + jumpSize, arr, map));
	
	map[r][c] = answer;
	return answer;
}

int main()
{
	int i, j, tmp;
	int testCase;
	int size;

	cin >> testCase;
	while (testCase) {
		//inputs

		cin >> size;
		vector<vector<int>> arr(size, vector<int>(size));
		vector<vector<int>> map(size, vector<int>(size, -1));
		map[size - 1][size - 1] = 1;

		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				cin >> arr[i][j];
			}
		}

		if (jump(0, 0, arr, map)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
		testCase--;
	}
	return 0;
}