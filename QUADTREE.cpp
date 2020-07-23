//https://algospot.com/judge/problem/read/QUADTREE
//
#include <iostream>
using namespace std;
//used string for convenience

// 1,2		to	3,4
// 3,4			1,2
string reverseQuadtree(string quadtree) {
	int i, j;
	int size;
	int split[5] = { 1 };
	string answer = "";
	
	if (quadtree[0] != 'x') return quadtree;// one color
	
	//check index of area
	for (i = 0; i < 4; i++) {
		size = 1;
		for (j = 0; j < size; j++) {
			if (quadtree[split[i] + j] == 'x') {
				size += 4;
			}
		}
		split[i + 1] = split[i] + size;
	}

	answer += "x";
	answer += reverseQuadtree(quadtree.substr(split[2], split[3] - split[2]));//3
	answer += reverseQuadtree(quadtree.substr(split[3], split[4] - split[3]));//4
	answer += reverseQuadtree(quadtree.substr(split[0], split[1] - split[0]));//1
	answer += reverseQuadtree(quadtree.substr(split[1], split[2] - split[1]));//2
	
	return answer;
}

int main()
{
	int i, j;
	int testCase;

	string arr;

	/*scanf("%d", &testCase);*/
	cin >> testCase;
	while (testCase) {
		//inputs
		cin >> arr;

		cout << reverseQuadtree(arr) << endl;

		testCase--;
	}
	return 0;
}