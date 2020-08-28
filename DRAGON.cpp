//https://algospot.com/judge/problem/read/DRAGON
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl

int MAX_LEN = 1000000100;
string Bn(vector<string>& memA, vector<string>& memB, int nth);
string An(vector<string>& memA, vector<string>& memB, int nth);

//A(0) = FX, B(0) = YF
//A(n) = A(n-1) + B(n-1)
//B(n) = A(n-1) - B(n-1)
string An(vector<string> &memA, vector<string> &memB, int nth) {
	if (nth < memA.size()) {
		if (!memA[nth].empty()) return memA[nth];
		else return memA[nth] = An(memA, memB, nth - 1) + "+" + Bn(memA, memB, nth - 1);
	}
	else {//not used
		return An(memA, memB, nth - 1) + "+" + Bn(memA, memB, nth - 1);
	}
}
string Bn(vector<string>& memA, vector<string>& memB, int nth) {
	if (nth < memB.size()) {
		if (!memB[nth].empty()) return memB[nth];
		else return memB[nth] = An(memA, memB, nth - 1) + "-" + Bn(memA, memB, nth - 1);
	}
	else {//not used
		return An(memA, memB, nth - 1) + "-" + Bn(memA, memB, nth - 1);
	}
}

//returns string [start, start + size)
string dragon(vector<string>& memA, vector<string>& memB, vector<int> len, int isA, int nth, int start, int size) {
	int i, tmp;
	int mid, left;
	string answer = "";

	//base case
	//if (start <= 0 || size <= 0) return answer;
	if (isA && nth < memA.size()) return An(memA,memB,nth).substr(start - 1, size);
	if (!isA && nth < memA.size()) return Bn(memA, memB, nth).substr(start - 1, size);

	mid = len[nth - 1] + 1;
	//left
	if (start < mid) {
		left = mid - start;
		if (left > size) {
			left = size;
		}
		answer += dragon(memA, memB, len, 1, nth - 1, start, left);
		
		size -= left;
		start += left;
	}
	//mid operator
	if (start == mid && start + size - 1 >= mid) {
		if (isA) answer += "+";
		else answer += "-";
		
		size -= 1;
		start += 1;
	}
	//right
	if (start + size - 1 > mid) {
		answer += dragon(memA, memB, len, 0, nth - 1, start - mid, size);
	}

	return answer;
}


int main()
{
	int i, j, tmp;
	int testCase;
	int nth;
	int start, size;

	vector<int> len(51, MAX_LEN); //len[29] > 1000000000
	len[0] = 2;
	for (i = 1; i < 29; i++) {
		len[i] = 2 * len[i - 1] + 1;
	}

	//try to save memory
	//n generation dragon curve size is 3*2^n - 1
	vector<string> memA(7);
	memA[0] = "FX";
	vector<string> memB(7);
	memB[0] = "YF";

	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> nth >> start >> size;
		
		cout << dragon(memA, memB, len, 1, nth, start, size) << '\n';

		testCase--;
	}

	return 0;
}