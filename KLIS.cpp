//https://algospot.com/judge/problem/read/KLIS
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int max value + 1
//2^31 
double TWO_POW_31 = pow(2, 31);

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


//returns KLIS inverse
vector<int> KLIS(vector<int> mem, vector<double> cnt, vector<int> arr, int pre, int len, int nth) {
	int i, tmp;
	vector<int> answer;

	if (len == 0) return answer;
	while (1) {
		//find first index that make  LIS
		tmp = -1;
		for (i = 0; i < mem.size(); i++) {
			if (mem[i] == len && pre < arr[i]) {
				if (tmp == -1 || arr[tmp] > arr[i]) {
					tmp = i;
				}
			}
		}

		if (nth <= cnt[tmp]) {
			answer = KLIS(mem, cnt, arr, arr[tmp], len - 1, nth);
			answer.push_back(arr[tmp]);
			return answer;
		}
		else {
			arr[tmp] = 100001;//visited
			nth -= cnt[tmp];
		}
	}
}


//return Length of increasing subsequence 
int LIS(vector<int> &mem, vector<double> &cnt, vector<int> arr) {
	int i, j;
	int answer = 0;
	
	//find LIS that include and start from arr[i]  
	for (i = mem.size() - 1; i >= 0; i--) {
		mem[i] = 1;
		for (j = i + 1; j < mem.size(); j++) {
			if (arr[i] < arr[j] && mem[i] < mem[j] + 1){
				mem[i] = mem[j] + 1;
			}
		}
	}
	//fill cnt
	for (i = mem.size() - 1; i >= 0; i--) {
		cnt[i] = 0;
		for (j = i + 1; j < mem.size(); j++) {
			if (arr[i] < arr[j] && mem[i] == mem[j] + 1) {
				cnt[i] += cnt[j];
				if (cnt[i] > TWO_POW_31) {
					cnt[i] = TWO_POW_31;
					break;
				}
			}
		}
		if (cnt[i] == 0) cnt[i] = 1;
	}


	//find max
	for (i = 0; i < mem.size(); i++) {
		if (answer < mem[i]) {
			answer = mem[i];
		}
	}

	return answer;
}


int main()
{
	int i, j, tmp;
	int testCase;
	int size;
	int nth, len;

	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> size >> nth;

		vector<int> arr(size);
		vector<int> mem(arr.size());
		vector<double> cnt(arr.size());
		for (i = 0; i < size; i++) {
			cin >> arr[i];
		}

		//calc
		int len = LIS(mem, cnt, arr);
		vector<int> answer = KLIS(mem, cnt, arr, 0, len , nth);
		
		//print
		cout << len << '\n';
		for (i = answer.size() - 1; i >= 0; i--) {
			cout << answer[i] << ' ';
		}
		cout << '\n';

		testCase--;
	}
	return 0;
}