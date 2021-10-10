#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 25. 석차 구하기

// N명의 학생의 수학점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력하는 프로그램을
// 작성하세요.

// 입력설명
// 첫 줄에 N(1<=N<=100)이 입력되고, 두 번째 줄에 수학점수를 의미하는 N개의 정수가 입력된
// 다.같은 점수가 입력될 경우 높은 석차로 동일 처리한다.즉 가장 높은 점수가 92점인데 92
// 점이 3명 존재하면 1등이 3명이고 그 다음 학생은 4등이 된다.점수는 100점 만점이다.

// 출력설명
// 첫 줄에 입력된 순서대로 석차를 출력한다.

// ex1)
// input
// 5
// 90 85 92 95 90

// output
// 3 5 2 1 3

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N](); // 점수
		int* b = new int[N](); // 등수

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			b[i] = 1;
			if (i != 0) {
				for (int j = 0;j < i;j++) {
					if (a[j] > a[i]) {
						b[i]++;
					}
					else if (a[j] < a[i]) {
						b[j]++;
					}
				}
			}
		}

		for (int i = 0; i < N - 1; i++) {
			printf("%d ", b[i]);
		}
		printf("%d\n", b[N - 1]);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}