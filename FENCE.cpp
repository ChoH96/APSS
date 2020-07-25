//https://algospot.com/judge/problem/read/FENCE
//
#include <iostream>

//implemented using book's algorithm

//find answer in bounded area [start,end)
int maxAnswer(int arr[], int start, int end) {
	int i, j, tmp;
	int half;
	int left, right, height;
	int answer;

	if ((end - start) == 1) return arr[start];

	//check left max, right max
	half = (start + end) / 2;
	answer = maxAnswer(arr, start, half);
	tmp = maxAnswer(arr, half, end);
	if (answer < tmp) {
		answer = tmp;
	}

	//check if area is in the middle
	//[left, right)
	left = half - 1;
	right = half + 1;
	
	height = arr[left];
	if (height > arr[right - 1]) {
		height = arr[right - 1];
	}

	while (1) {
		tmp = (right - left) * height;
		if (answer < tmp) {
			answer = tmp;
		}
		

		if (left == start && right == end) {
			break;
		}
		else if (left == start || (right != end && arr[left - 1] < arr[right])){
			right++;
			if (height > arr[right - 1]) {
				height = arr[right - 1];
			}
		}
		else if (right == end || (left != start && arr[left - 1] >= arr[right])) {
			left--;
			if (height > arr[left]) {
				height = arr[left];
			}
		}
	}

	return answer;
}

int main()
{
	int i, j, tmp;
	int testCase;
	int size;

	int arr[20000];

	scanf("%d", &testCase);
	while (testCase) {
		//inputs
		scanf("%d", &size);
		for (i = 0; i < size; i++) {
			scanf("%d", &arr[i]);
		}
		printf("%d\n", maxAnswer(arr, 0, size));
		
		testCase--;
	}
	return 0;
}