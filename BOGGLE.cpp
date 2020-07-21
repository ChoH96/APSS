//https://algospot.com/judge/problem/read/BOGGLE
//
#include <iostream>

//all 8 directions
const int dr[8] = { -1,-1, 0, 1, 1, 1, 0,-1 };
const int dc[8] = {  0, 1, 1, 1, 0,-1,-1,-1 };

// check index r,c is within the limit
int isValid(int r, int c) {
	if (0 <= r && r < 5 && 0 <= c && c < 5) return 1;
	return 0;
}

// check using movable points(map)
int hasWord(char* word, int idx, char arr[][6], int map[][5]) {
	int i, j, k;
	int cnt = 0;
	int newMap[5][5] = { 0 };// next movable points
	if (word[idx] == '\0') return 1;
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (map[i][j] && word[idx] == arr[i][j]) {
				for (k = 0; k < 8; k++) {
					if (isValid(i + dr[k], j + dc[k])) {
						newMap[i + dr[k]][j + dc[k]] = 1;
						cnt++;
					}
				}
			}
		}
	}
	if (cnt) return hasWord(word, idx + 1, arr, newMap);
	else return 0;
}


int main()
{
	int i, j;
	int testCase, numWord;
	char arr[5][6], word[11];
	int map[5][5];
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			map[i][j] = 1;
		}
	}

	scanf("%d", &testCase);
	while (testCase) {
		//inputs
		for (i = 0; i < 5; i++) {
			scanf("%s", arr[i]);
		}
		
		scanf("%d", &numWord);
		while(numWord) {
			scanf("%s", word);
			
			if (hasWord(word, 0, arr, map)) {
				printf("%s YES\n", word);
			}
			else {
				printf("%s NO\n", word);
			}

			numWord--;
		}

		testCase--;
	}
	return 0;
}