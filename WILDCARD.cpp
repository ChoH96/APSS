//https://algospot.com/judge/problem/read/WILDCARD
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


//match wIdx ~, cIdx ~
//when wString[wIdx] == '*' searching forward is faster in the test case
//searching backward also works
int wildcard(vector<vector<int>> &mem, string wString, string cString, int wIdx, int cIdx) {
	int i, j, k, tmp;

	int& ret = mem[wIdx][cIdx];
	if (ret != -1) return ret;
	
	if (wString[wIdx] == '*') {
		for(i=0;cIdx + i <= cString.size();i++){
		tmp = wildcard(mem, wString, cString, wIdx + 1, cIdx + i);
			if (tmp) {
				return ret = tmp;
			}
		}
		return ret = 0;
	}
	else{
		if (wString[wIdx] == '?' || wString[wIdx] == cString[cIdx]) {
			return ret = wildcard(mem, wString, cString, wIdx + 1, cIdx + 1); //wIdx + 1, cIdx + 1
		}
		else {
			return ret = 0;
		}
	}
}




int main()
{
	int i, j, tmp;
	int testCase;
	int size;

	cin >> testCase;
	while (testCase) {
		vector<string> answer;
		string wString;
		string cString;

		//inputs
		cin >> wString;
		cin >> size;
		while (size) {
			cin >> cString;
			
			//memorization 
			vector<vector<int>> mem(wString.size() + 1, vector<int>(cString.size() + 1, -1));
			mem[wString.size()][cString.size()] = 1;
			
			//filling edges
			for (i = 0; i < wString.size(); i++) {
				mem[i][cString.size()] = 0;
			}

			for (i = 0; i < cString.size() && cString[i] == '*'; i++) {
				mem[wString.size()][i] = 1;
			}
			for (; i < cString.size(); i++) {
				mem[wString.size()][i] = 0;
			}

			//use
			if (wildcard(mem, wString, cString, 0, 0)) {
				answer.push_back(cString);
			}

			//print mem
			/*for (i = 0; i < mem.size(); i++) {
				for (j = 0; j < mem[i].size(); j++) {
					printf("%4d", mem[i][j]);
				}
				printf("\n");
			}*/


			size--;
		}

		sort(answer.begin(), answer.end());
		for (i = 0; i < answer.size(); i++) {
			cout /*<< "           "*/ << answer[i] << '\n';
		}
		


		testCase--;
	}
	return 0;
}