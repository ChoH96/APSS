//https://algospot.com/judge/problem/read/FENCE
//
#include <iostream>
#include <vector>
using namespace std;
//implemented without using book's algorithm

//search from height 1 to 100000
//skip un used height and check used value to optimize
int maxAnswer(int size, int check[], int used[], vector<vector<int>> idx) {
	int i, j, tmp;
	int left, right;
	int answer = 0;

	for (i = 0; i <= 10000; i++) {
		if (check[i]) {
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

				tmp = i * (right + left +1); //height(i) * width(left + right + 1)
				if (answer < tmp) {
					answer = tmp;
				}

				used[idx[i][j]] = 1;
			}
		}
	}
	return answer;
}

int main()
{
	int i, j, tmp;
	int testCase;
	int size, height;	

	scanf("%d", &testCase);
	while (testCase) {
		int used[20000] = { 0 };//used index
		int check[10001] = { 0 };//height to be checked
		vector<vector<int>> idx(10001, vector<int>());

		//inputs
		scanf("%d", &size);
		for (i = 0; i < size; i++) {
			scanf("%d", &height);
			check[height] = 1;
			idx[height].push_back(i);
		}
		printf("%d\n", maxAnswer(size, check, used, idx));

		testCase--;
	}
	return 0;
}