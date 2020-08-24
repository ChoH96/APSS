//https://algospot.com/judge/problem/read/MORSE
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


//return nCm value using memorization
//if return value is larger than 1000000001 returns 1000000001
int combination(vector<vector<int>> &mem, int n, int m) {
	int i, ret;
	if (mem[n][m] != -1) return mem[n][m];

	ret = combination(mem, n - 1, m) + combination(mem, n - 1, m - 1);
	//if too big
	if (ret > 1000000001) ret = 1000000001;

	mem[n][m] = ret;
	mem[n][n - m] = ret;
	return ret;
}

//find nth morse code
//using nCm value calculated from combination function
string morse(vector<vector<int>>& mem, int morseL, int morseS, int nth) {
	int i, tmp;
	string ret = "";
	if (nth == 1) {
		for (i = 0; i < morseL; i++) {
			ret += "-";
		}
		for (i = 0; i < morseS; i++) {
			ret += "o";
		}
		return ret;
	}
	
	tmp = combination(mem, morseL + morseS - 1, morseL - 1);
	if (nth <= tmp) {
		return "-" + morse(mem, morseL - 1, morseS, nth);
	}
	else {
		return "o" + morse(mem, morseL, morseS - 1, nth - tmp);
	}
}



int main()
{
	int i, j, tmp;
	int testCase;
	int morseL, morseS, nth;

	vector<vector<int>> mem(201, vector<int>(201, -1));
	for (i = 0; i < mem.size(); i++) {
		mem[i][0] = 1;
		mem[i][i] = 1;
	}

	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> morseL >> morseS >> nth;

		cout << morse(mem, morseL, morseS, nth) << '\n';

		testCase--;
	}
	return 0;
}