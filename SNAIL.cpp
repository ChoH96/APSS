//https://algospot.com/judge/problem/read/SNAIL
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ios_base::sync_with_stdio(false)
//try to use '\n' than endl

//memorization 
//return possiblilty of when(days), where(depth) snail can be
double snail(vector<vector<double>>& mem, int days, int depth) {
	int i, j;
	double answer = 0;
	if (depth < 0) return 0;
	if (mem[days][depth] != -1) return mem[days][depth];

	answer = 0.25 * snail(mem, days - 1, depth - 1) + 0.75 * snail(mem, days - 1, depth - 2);
	return mem[days][depth] = answer;
}

int main()
{
	int i, j, tmp;
	int testCase;
	int depth;
	int days;

	cin >> testCase;

	//every testCase calucation gets faster
	vector<vector<double>> mem(1001, vector<double>(1001, -1)); //days, depth
	mem[0][0] = 1;
	for (i = 1; i < 1001; i++) {
		mem[0][i] = 0;
	}

	while (testCase) {
		//inputs
		cin >> depth >> days;

		double tmp = 0;
		for (i = 0; i < depth; i++) { 
			tmp += snail(mem, days, i);
		}
		printf("%.10lf\n", 1 - tmp);//subtract unreachable possibliltes

		testCase--;
	}
	return 0;
}