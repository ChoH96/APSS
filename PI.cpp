//https://algospot.com/judge/problem/read/PI
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl

int getDifficulty(string arr, int idx, int size) {
	int i, j, tmp;

	//same value
	for (i = 1; i < size && arr[idx + i - 1] == arr[idx + i]; i++);
	if (i == size) return 1;
	
	//++ or --
	tmp = arr[idx + 0] - arr[idx + 1];
	if (tmp == 1 || tmp == -1) {
		for (i = 2; i < size && arr[idx + i - 1] - arr[idx + i] == tmp; i++);
		if (i == size) return 2;
	}

	//switch between 2 num
	for (i = 2; i < size && arr[idx + i - 2] == arr[idx + i]; i += 2);
	for (j = 3; j < size && arr[idx + j - 2] == arr[idx + j]; j += 2);
	if (i >= size && j >= size) return 4;
	
	//gradual
	tmp = arr[idx + 0] - arr[idx + 1];
	for (i = 2; i < size && arr[idx + i - 1] - arr[idx + i] == tmp; i++);
	if (i == size) return 5;
	
	// else
	return 10;
}


//use memorization 
int pi(string arr, int start, vector<int>& mem) {
	int i, j, tmp;
	int answer = 100000;
	int size; 
	
	//already done
	if (mem[start] != -1) return mem[start];
	
	size = arr.size() - start;
	if (size <= 5) { //size >= 3
		mem[start] = getDifficulty(arr, start, size);
		return mem[start];
	}
	else {
		for (i = 3; i < 6; i++) {
			if (size - i >= 3) {
				tmp = getDifficulty(arr, start, i) + pi(arr, start + i, mem);
				if (answer > tmp) {
					answer = tmp;
				}
			}
		}
		mem[start] = answer;
		return mem[start];
	}
}


int main()
{
	int i, j, tmp;
	int testCase;
	int size;

	//use to get input larger than 4096
	/*char mybuffer[200000];
	setvbuf(stdin, mybuffer, _IOFBF, sizeof(mybuffer));*/

	cin >> testCase;
	while (testCase) {
		//inputs

		string arr;
		cin >> arr;

		vector<int> mem(arr.size(), -1);
		cout << pi(arr, 0, mem) << '\n';

		testCase--;
	}
	return 0;
}