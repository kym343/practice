#include<iostream>
#include <algorithm>

using namespace std;

//https://www.acmicpc.net/problem/1978

int find(int A);

int result = 0;

int main(int argc, char** argv) {
	int P;

	freopen("sample_input.txt", "r", stdin);

	cin >> P;

	int *arr = new int[P]();

	for (int i = 0; i < P; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < P; i++) {
		if (arr[i] == 1) {
			continue;
		}
		else if (arr[i] == 2 || arr[i] == 3) {
			result++;
		}
		else {
			result += find(arr[i]);
		}
	}
	
	printf("\n%d", result);


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int find(int A) {
	if (A % 2 == 1) {
		for (int i = 3; i < A - 1; i++) {
			if (A % i == 0) {
				return 0;
			}
		}
		return 1;
	}	
	else {
		return 0;
	}
}