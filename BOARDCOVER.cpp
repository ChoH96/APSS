//https://algospot.com/judge/problem/read/BOARDCOVER
//
#include <iostream>


//	1.	2.	3.	4.
//	**	*	*	**
//	*	**	**	*
const int covers[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1, -1}},
	{{0,0},{0,1},{1, 1}}
};

// check new (r,c) is valid
int isValid(char arr[][21], int height, int width, int r, int c, int idx) {
	int i;
	int new_r, new_c;
	for (i = 0; i < 3; i++) {
		new_r = r + covers[idx][i][0];
		new_c = c + covers[idx][i][1];
		if (0 > new_r || new_r >= height ||
			0 > new_c || new_c >= width ||
			arr[new_r][new_c] != '.') {
			return 0;
		}
	}
	return 1;
}

// setpoints to given value
int setPoints(char arr[][21], int r, int c, int idx, char value) {
	int i;
	for (i = 0; i < 3; i++) {
		arr[r + covers[idx][i][0]][c + covers[idx][i][1]] = value;
	}
	return 1;
}

 //choose from lowest index (r,c)
 //to avoid overlaped pairs
int countAnswers(char arr[][21],int height, int width) {
	int i, j, idx;
	int r, c, oFlag;
	int answer = 0;

	oFlag = 0;
	for (r = 0; r < height; r++) {
		for (c = 0; c < width; c++) {
			if (arr[r][c] == '.') {
				oFlag = 1;
				break;
			}
		}
		if (oFlag) {
			break;
		}
	}
	if (r == height) return 1;

	for (i = 0; i < 4; i++) {
		if (isValid(arr, height, width, r, c, i)) {
			setPoints(arr, r, c, i, '#');

			answer += countAnswers(arr, height,width);

			setPoints(arr, r, c, i, '.');
		}
	}

	return answer;
}

int main()
{
	int i, j;
	int testCase;
	int height, width;

	int tmp;
	char arr[20][21];
	

	scanf("%d", &testCase);
	while (testCase) {
		//inputs
		scanf("%d", &height);
		scanf("%d", &width);
		for (i = 0; i < height; i++) {
			scanf("%s", arr[i]);
		}
		
		tmp = 0;
		for (i = 0; i < height; i++) {
			for (j = 0; j < width; j++) {
				if (arr[i][j] == '.') {
					tmp++;
				}
			}
		}
		
		if (tmp % 3) {
			printf("0\n");
		}
		else {
			printf("%d\n", countAnswers(arr, height, width));
		}

		testCase--;
	}
	return 0;
}