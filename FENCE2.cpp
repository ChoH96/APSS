//https://algospot.com/judge/problem/read/FENCE
//
#include <iostream>
#include <vector>
using namespace std;
//implemented without using book's algorithm

//search from height 1 to 100000
//skip un used height and check used value to optimize
int maxAnswer(int size, int used[], int heights[], vector<vector<int>> idx) {
	int i, j, tmp;
	int left, right;
	int answer = 0;

	for (i = 1; i <= 10000; i++) {
		if (heights[i]) {
			for (j = 0; j < idx[i].size(); j++) {
				//better optimization can be done
				//by checking already checked values
				left = 0;
				right = 0;

				while (idx[i][j] - left - 1 >= 0 && !used[idx[i][j] - left - 1]) {
					left++;
				}
				while (idx[i][j] + right + 1 < size && !used[idx[i][j] + right + 1]) {
					right++;
				}

				tmp = i * (right + left + 1);
				if (answer < tmp) {
					answer = tmp;
				}

				used[idx[i][j]] = 1;
			}
			/*for (j = 0; j < idx[i].size(); j++) {
				used[j] = 1;
			}*/
		}
	}
	return answer;
}

int main()
{
	int i, j, tmp;
	int testCase;
	int size;	

	scanf("%d", &testCase);
	while (testCase) {

		int arr[10001];
		int used[10001] = { 0 };
		int heights[10001] = { 0 };
		vector<vector<int>> idx(10001, vector<int>());

		//inputs
		scanf("%d", &size);
		for (i = 0; i < size; i++) {
			scanf("%d", &arr[i]);
			heights[arr[i]] = 1;
			idx[arr[i]].push_back(i);
		}
		printf("%d\n", maxAnswer(size, used, heights, idx));

		testCase--;
	}
	return 0;
}