//https://algospot.com/judge/problem/read/CLOCKSYNC
//
#include <iostream>


const int connected[10][16] = {
//	  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
	{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
	{ 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{ 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
};

// check new (r,c) is valid
int isDone(int arr[16]) {
	int i;
	for (i = 0; i < 16; i++) {
		if (arr[i] != 0) return 0;
	}
	return 1;
}

//choose from lowest switch
//if not possible return big value(64)
int countAnswers(int arr[16], int idx) {
	int i, j;
	int tmp;
	
	int answer = 64; // 2^6 > max 3*16
	if (isDone(arr)) return 0;
	else if (idx == 10) return 64;

	for (i = 0; i < 4; i++) {
		tmp = i + countAnswers(arr, idx + 1);
		if (answer > tmp) {
			answer = tmp;
		}

		//prepare for next
		for (j = 0; j < 16; j++) {
			if (connected[idx][j]) {
				arr[j] = (arr[j] + 1) % 4;
			}
		}
	}
	
	return answer;
}

int main()
{
	int i, j;
	int testCase;
	
	int tmp;
	int arr[16];

	scanf("%d", &testCase);
	while (testCase) {
		//inputs
		for (i = 0; i < 16; i++) {
			scanf("%d", &tmp);
			arr[i] = tmp / 3 % 4;
		}

		tmp = countAnswers(arr, 0);
		if (tmp == 64) { //impossible
			printf("-1\n");
		}
		else {
			printf("%d\n", tmp);
		}
		
		testCase--;
	}
	return 0;
}