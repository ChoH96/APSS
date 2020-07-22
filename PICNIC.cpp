//https://algospot.com/judge/problem/read/PICNIC
//
#include <iostream>

 //choose from lowest index, pair (A, B) should be A < B
 //to avoid overlaped pairs
int countPairs(int numStudents, int *taken, int arr[][10]) {
	int i, idx;
	int answer = 0;

	for (idx = 0; idx < numStudents; idx++) {
		if (!taken[idx]) break;
	}
	if (idx == numStudents) return 1;

	for (i = idx + 1; i < numStudents; i++) {
		if (arr[idx][i] && !taken[i]) {
			taken[idx] = 1;
			taken[i] = 1;

			answer += countPairs(numStudents, taken, arr);

			taken[idx] = 0;
			taken[i] = 0;
		}
	}

	return answer;
}

int main()
{
	int i, j;
	int testCase;
	int numStudents, numPairs;
	
	int tmp1, tmp2;
	int arr[10][10];
	int taken[10];


	scanf("%d", &testCase);
	while (testCase) {
		//inputs
		scanf("%d", &numStudents);
		scanf("%d", &numPairs);
		for (i = 0; i < numStudents; i++) {
			for (j = 0; j < numStudents; j++) {
				arr[i][j] = 0;
			}
			taken[i] = 0;
		}
		while (numPairs) {
			scanf("%d", &tmp1);
			scanf("%d", &tmp2);
			arr[tmp1][tmp2] = 1;
			arr[tmp2][tmp1] = 1;

			numPairs--;
		}
		printf("%d\n", countPairs(numStudents, taken, arr));

		testCase--;
	}
	return 0;
}