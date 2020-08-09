//https://algospot.com/judge/problem/read/WILDCARD
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl

bool wildcard(string wString, string cString, int wIdx, int cIdx, bool afterStar) {
	int i, j, k, tmp;
	//if (wIdx >= wString.size()) return true;

	if (afterStar) {
		if (wIdx == wString.size()) return true;

		for (j = cIdx; j < cString.size() && wString[wIdx] != cString[j]; j++);
		if (j == cString.size()) return false;

		return wildcard(wString, cString, wIdx + 1, j + 1, false)
			|| wildcard(wString, cString, wIdx, j + 1, true);
	}
	else {
		for (i = wIdx, j = cIdx; i < wString.size(); i++, j++) {
			if (wString[i] == '*') {
				for (k = 1; i + k < wString.size() && wString[i + k] == '*'; k++);
				return wildcard(wString, cString, i + k, j, true);
			}
			else {
				if (j >= cString.size()) return false;
				if (wString[i] != '?' && wString[i] != cString[j]) return false;
			}
		}
		if (j < cString.size()) return false;
		else return true;
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
		for (i = 0; i < size; i++) {
			cin >> cString;
			//
			if (wildcard(wString,cString,0,0,false)) {
				answer.push_back(cString);
			}
		}

		sort(answer.begin(), answer.end());
		for (i = 0; i < answer.size(); i++) {
			cout <<  "   " << answer[i] << '\n';
		}
		


		testCase--;
	}
	return 0;
}