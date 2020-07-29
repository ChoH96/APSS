//https://algospot.com/judge/problem/read/JUMPGAME
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int isValid(int r, int c, int n) {
	if (0 <= r && r < n && 0 <= c && c < n) {
		return 1;
	}

	return 0;
}

//find answer by updating reachable poionts (r,c)
int reachable(vector<vector<int>> arr) {
	int i, j;
	int n = arr.size();

	vector<vector<int>> map(n, vector<int>(n, 0));
	map[0][0] = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j]) {
				if (isValid(i + arr[i][j], j, n)) {
					map[i + arr[i][j]][j] = 1;
				}
				if (isValid(i, j + arr[i][j], n)) {
					map[i][j + arr[i][j]] = 1;
				}
			}
		}
	}

	return map[n - 1][n - 1];
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
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				cin >> arr[i][j];
			}
		}

		if (reachable(arr)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		testCase--;
	}
	return 0;
}