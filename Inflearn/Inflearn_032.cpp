#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 32. 선택정렬

// N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
// 정렬하는 방법은 선택정렬입니다.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
// 두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다.각 자연수는 정수형 범위 안에
// 있습니다.

// 출력설명
// 오름차순으로 정렬된 수열을 출력합니다.

// ex1)
// input
// 6
// 13 5 11 7 23 15

// output
// 5 7 11 13 15 23

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N]();

		int i, j, idx=0, tmp, flag;
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}
		// #################################################
		//for (j = 0;j < N - 1;j++) {
		//	int min = a[j];
		//	flag = 0;
		//	for (i = j+1; i < N; i++) {
		//		if (min > a[i]) {
		//			idx = i;
		//			min = a[i];
		//			flag++;
		//		}
		//	}
		//	if (flag != 0) {
		//		tmp = a[idx];
		//		a[idx] = a[j];
		//		a[j] = min;
		//	}
		//}

		//for (i = 0; i < N - 1; i++) {
		//	printf("%d ", a[i]);
		//}
		//printf("%d\n", a[i]);

		// #################################################
		for (i = 0; i < N; i++) {
			idx = i;
			for (j = i + 1;j < N; j++) {
				if (a[j] < a[idx]) {
					idx = j;
				}
			}
			tmp = a[i];
			a[i] = a[idx];
			a[idx] = tmp;
		}

		for (i = 0; i < N; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		// #################################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}