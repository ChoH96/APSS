//https://algospot.com/judge/problem/read/TRIANGLEPATH
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl

int main()
{
	int i, j, tmp;
	int testCase;
	int size;
	int answer;
	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> size;
		vector<int> arr(size, 0);
		vector<int> prev(size, 0);


		//handle problem while getting inputs 
		for (i = 1; i <= size; i++) {
			cin >> tmp;
			arr[0] = prev[0] + tmp;
			for (j = 1; j < i; j++) {
				cin >> tmp;
				if (prev[j - 1] < prev[j]) {
					arr[j] = prev[j] + tmp;
				}
				else {
					arr[j] = prev[j - 1] + tmp;
				}
			}
			prev = arr;
		}

		answer = arr[0];
		for (i = 1; i < size; i++) {
			if (answer < arr[i]) {
				answer = arr[i];
			}
		}
		cout << answer << '\n';

		testCase--;
	}
	return 0;
}