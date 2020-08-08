//https://algospot.com/judge/problem/read/QUANTIZE
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


//try to reduce calculation using accumulate array + memorization
int quantization(vector<vector<int>> &mem, vector<int> acc1, vector<int> acc2, int start, int split) {
	int i, j, tmp;
	int n, m;
	int answer;

	if (mem[start][split] != -1) return mem[start][split];
	int end = acc1.size() - 1;
	
	if (split == 0) {
		n = (end - start);
		m = round((acc1[end] - acc1[start]) / (float)n);
		mem[start][split] = (acc2[end] - acc2[start]) - 2 * m * (acc1[end] - acc1[start]) + (n * m * m);
	}
	else {
		answer = quantization(mem, acc1, acc2, start, split - 1);
		for (i = 1; i < end - start; i++) {
			n = i;
			m = round((acc1[start + i] - acc1[start]) / (float)n);
			tmp = (acc2[start + i] - acc2[start]) - 2 * m * (acc1[start + i] - acc1[start]) + (n * m * m)
				+ quantization(mem, acc1, acc2, start + i, split - 1);

			if (answer > tmp) {
				answer = tmp;
			}
		}
		mem[start][split] = answer;
	}

	return mem[start][split];
}



int main()
{
	int i, j, tmp;
	int testCase;
	int size;
	int split;

	cin >> testCase;
	while (testCase) {
		//inputs

		cin >> size >> split;
		vector<int> arr(size);
		vector<int> acc1(size + 1);
		vector<int> acc2(size + 1);
		vector<vector<int>> mem(size, vector<int>(10, -1));


		for (i = 0; i < size; i++) {
			cin >> arr[i];
		}

		//preparation
		sort(arr.begin(), arr.end());
		acc1[0] = arr[0];
		acc2[0] = arr[0] * arr[0];
		for (i = 0; i < size; i++) {
			acc1[i + 1] = acc1[i] + arr[i];
			acc2[i + 1] = acc2[i] + arr[i] * arr[i];
		}
		
		// calculation
		cout << quantization(mem, acc1, acc2, 0, split - 1) << '\n';

		testCase--;
	}
	return 0;
}