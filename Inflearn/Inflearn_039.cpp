#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 39. 두 배열 합치기

// 오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램
// 을 작성하세요.

// 입력설명
// 첫 번째 줄에 첫 번째 배열의 크기 N(1<=N<=100)이 주어집니다.
// 두 번째 줄에 N개의 배열 원소가 오름차순으로 주어집니다.
// 세 번째 줄에 두 번째 배열의 크기 M(1 <= M <= 100)이 주어집니다.
// 네 번째 줄에 M개의 배열 원소가 오름차순으로 주어집니다.
// 각 배열의 원소는 int형 변수의 크기를 넘지 않습니다.

// 출력설명
// 오름차순으로 정렬된 배열을 출력합니다.

// ex1)
// input
// 3
// 1 3 5
// 5
// 2 3 6 7 9

// output
// 1 2 3 3 5 6 7 9

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, idx_a=0, idx_b=0;

		scanf("%d", &N);

		int* a = new int[N]();
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}

		scanf("%d", &M);

		int* b = new int[M]();
		for (i = 0;i < M;i++) {
			scanf("%d", &b[i]);
		}

		int* c = new int[N+M]();
		// #############################################################
		//for (i = 0;i < N + M;i++) {
		//	if (idx_a != N && idx_b != M) {
		//		if (a[idx_a] <= b[idx_b]) {
		//			c[i] = a[idx_a];
		//			idx_a++;
		//		}
		//		else {
		//			c[i] = b[idx_b];
		//			idx_b++;
		//		}
		//	}
		//	else if (idx_a == N) {
		//		for (j = i;j < N + M;j++) {
		//			c[j] = b[idx_b];
		//			idx_b++;
		//		}
		//		break;
		//	}
		//	else if (idx_b == M) {
		//		for (j = i;j < N + M;j++) {
		//			c[j] = a[idx_a];
		//			idx_a++;
		//		}
		//		break;
		//	}
		//}
		// #############################################################
		int idx_c=0;
		while (idx_a < N && idx_b < M) {
			if (a[idx_a] < b[idx_b]) {
				c[idx_c++] = a[idx_a++];
			}
			else {
				c[idx_c++] = b[idx_b++];
			}
		}
		while (idx_a < N) c[idx_c++] = a[idx_a++];
		while (idx_b < M) c[idx_c++] = b[idx_b++];
		// #############################################################
		for (i = 0;i < N + M;i++) {
			printf("%d ", c[i]);
		}
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}