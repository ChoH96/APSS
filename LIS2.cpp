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
	vector<int> lastValue(arr.size() + 1, -1); // use index 0 ~ N-1, N is not used

	//find LIS that include and start from arr[i]  
	lastValue[0] = arr[0];
	for (i = 1; i < arr.size(); i++) {
		for (j = 0; lastValue[j] != -1 && lastValue[j] < arr[i]; j++);// +more optimization can be done using binary search
		lastValue[j] = arr[i];
	}

	//find max
	// +more optimization can be done using binary search
	for (i = 0; lastValue[i] != -1; i++);
	answer = i;

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