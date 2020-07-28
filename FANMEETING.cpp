//https://algospot.com/judge/problem/read/FANMEETING
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//implemented using book's algorithm

vector<int> multiply(vector<int> a, vector<int> b) {
	int i, j;
	vector<int> answer = vector<int>(a.size() + b.size() + 1, 0);
	
	for (i = 0; i < a.size(); i++) {
		for (j = 0; j < b.size(); j++) {
			answer[i + j] += a[i] * b[j];
		}
	}
	return answer;
}

vector<int> addTo(vector<int> a, vector<int> b, int shift) {
	int i;
	a.resize(b.size() + shift, 0);

	for (i = 0; i < b.size(); i++) {
		a[i + shift] += b[i];
	}
	return a;
}

vector<int> subFrom(vector<int> a, vector<int> b, int shift) {
	int i;
	a.resize(b.size() + shift, 0);

	for (i = 0; i < b.size(); i++) {
		a[i + shift] -= b[i];
	}
	return a;
}


//find answer in bounded area [start,end)
vector<int> karatsuba(vector<int> a, vector<int> b) {
	int i, j;
	int half;
	vector<int> answer;
	
	if (a.size() < b.size()) {
		return karatsuba(b, a);
	}
	if (b.size() == 0) {
		return vector<int>();
	}
	if (a.size() < 50) {
		return multiply(a, b);
	}

	half = a.size() / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	
	a0 = addTo(a0, a1, 0);
	b0 = addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	z1 = subFrom(z1, z0, 0);
	z1 = subFrom(z1, z2, 0);

	answer = addTo(answer, z0, 0);
	answer = addTo(answer, z1, half);
	answer = addTo(answer, z2, half * 2);

	return answer;
}

int main()
{
	int i, j, tmp;
	int testCase;
	int size;

	cin >> testCase;
	while (testCase) {
		//inputs
		string members;
		string fans;

		cin >> members;
		cin >> fans;
		
		vector<int> a(members.size());
		vector<int> b(fans.size());

		for (i = 0; i < a.size(); i++) a[i] = (members[i] == 'M');
		for (i = 0; i < b.size(); i++) b[b.size() - i - 1] = (fans[i] == 'M');

		vector<int> c = karatsuba(a, b);
		int answer = 0;
		for (i = a.size() - 1; i < b.size(); i++) {
			if (c[i] == 0) {
				answer++;
			}
		}
		printf("%d\n", answer);
		
		testCase--;
	}
	return 0;
}