//https://algospot.com/judge/problem/read/PACKING
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl


//find answer using memorization
int packing(vector<vector<int>> &mem, int size, int idx, vector<int> volume, vector<int> priority) {
	int i, tmp;
	int ret;

	if (idx == volume.size()) mem[size][idx] = 0;
	if (mem[size][idx] != -1) return mem[size][idx];

	ret = packing(mem, size, idx + 1, volume, priority);
	if (size - volume[idx] >= 0) {
		tmp = packing(mem, size - volume[idx], idx + 1, volume, priority) + priority[idx];
		if (ret < tmp) {
			ret = tmp;
		}
	}
	
	mem[size][idx] = ret;
	return ret;
}


int main()
{
	int i, j, tmp;
	int testCase;
	int things, size;
	

	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> things >> size;

		vector<string> name(things);
		vector<int> volume(things);
		vector<int> priority(things);
		for (i = 0; i < name.size(); i++) {
			cin >> name[i] >> volume[i] >> priority[i];
		}
		
		vector<int> has(things, 0);
		vector<vector<int>> mem(1001, vector<int>(100, -1));
		for (i = 0; i < mem[0].size(); i++) {
			mem[0][i] = 0;
		}

		packing(mem, size, 0, volume, priority);
		

		vector<string> answer;
		tmp = size;

		//trace back using memorizatioin data
		for (i = 0; i < things; i++) {
			if (mem[tmp][i] != mem[tmp][i + 1]) {
				answer.push_back(name[i]);
				tmp -= volume[i];
			}
		}
		
		cout << mem[size][0] << ' ' << answer.size() << '\n';
		for (i = 0; i < answer.size(); i++) {
			cout << answer[i] << '\n';
		}
		


		testCase--;
	}
	return 0;
}