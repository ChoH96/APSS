//https://algospot.com/judge/problem/read/NUMB3RS
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip> //setprecision
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl



double numbers(vector<vector<double>> &mem, vector<vector<int>> map, vector<int> deg, int day, int city) {
	int i, j, tmp;
	double ret;

	if (mem[day][city] != -1) return mem[day][city];

	ret = 0;
	for (i = 0; i < map.size(); i++) {
		if (map[i][city] == 1) {
			ret += numbers(mem, map, deg, day - 1, i) / deg[i];
		}
	}

	mem[day][city] = ret;
	return ret;
}




int main()
{
	int i, j, tmp;
	int testCase;
	int size;
	int day, city;

	cin >> testCase;
	while (testCase) {
		//inputs

		cin >> size >> day >> city;
		vector<vector<int>> map(size, vector<int>(size, 0));
		vector<int> deg(size);
		
		vector<vector<double>> mem(day, vector<double>(size, -1));
		
		for (i = 0; i < size; i++) {
			int cnt = 0;
			for (j = 0; j < size; j++) {
				cin >> tmp;
				if (tmp == 1) {
					map[i][j] = tmp;
					cnt++;
				}
			}
			deg[i] = cnt;
		}

		//mem[0][i] fill day 0
		for (i = 0; i < map.size(); i++) {
			if (map[city][i] == 1) {
				mem[0][i] = 1.0 / deg[city];
			}
			else {
				mem[0][i] = 0.0;
			}
		}

		cin >> size;
		for (i = 0; i < size; i++) {
			cin >> tmp;
			cout << setprecision(8) << numbers(mem, map, deg, day - 1, tmp) << ' ';
		}
		cout << '\n';


		testCase--;
	}
	return 0;
}