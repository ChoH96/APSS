//https://algospot.com/judge/problem/read/LIS
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


//return Length of increasing subsequence 
int LIS(vector<int> arr) {
	int i, j;
	int answer = 0;
	vector<int> startFrom(arr.size());

	//find LIS that include and start from arr[i]  
	for (i = startFrom.size() - 1; i >= 0; i--) {
		startFrom[i] = 1;
		for (j = i + 1;j < startFrom.size(); j++) {
			if (arr[i] < arr[j] && startFrom[i] < startFrom[j] + 1) {
				startFrom[i] = startFrom[j] + 1;
			}
		}
	}

	//find max
	for (i = 0; i < startFrom.size(); i++) {
		if (answer < startFrom[i]) {
			answer = startFrom[i];
		}
	}

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

		vector<int> arr(size);
		for (i = 0; i < size; i++) {
			cin >> arr[i];
		}

		cout << LIS(arr) << '\n';

		testCase--;
	}
	return 0;
}