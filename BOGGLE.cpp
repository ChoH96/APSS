//https://algospot.com/judge/problem/read/BOGGLE
//
#include <iostream>

const int dr[8] = { -1,-1, 0, 1, 1, 1, 0,-1 };
const int dc[8] = {  0, 1, 1, 1, 0,-1,-1,-1 };


int isValid(int r, int c) {
	if (0 <= r && r < 5 && 0 <= c && c < 5) return 1;
	return 0;
}

int hasWord(int r, int c, char* word, int idx, char arr[][6]) {
	int i, j;
	int new_r, new_c;
	if (word[idx] == '\0') return 1;
	for (i = 0; i < 8; i++) {
		new_r = r + dr[i];
		new_c = c + dc[i];
		if (isValid(new_r, new_c) && arr[new_r][new_c] == word[idx]) {
			if (hasWord(new_r, new_c, word, idx + 1, arr)) {
				return 1;
			}
		}
	}
	return 0;
}


int main()
{
	int i, j;
	int testCase, numWord;
	char arr[5][6], word[11];

	scanf("%d", &testCase);
	while (testCase) {
		//inputs
		for (i = 0; i < 5; i++) {
			scanf("%s", arr[i]);
		}
		
		scanf("%d", &numWord);
		while(numWord) {
			scanf("%s", word);
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 5; j++) {
					if (arr[i][j] == word[0] && hasWord(i,j,word,1,arr)) {
						printf("%s YES\n", word);
						i = 6;
						j = 6;
					}
				}
			}
			if (i == 5 && j == 5) {
				printf("%s NO\n", word);
			}

			numWord--;
		}

		testCase--;
	}
	return 0;
}