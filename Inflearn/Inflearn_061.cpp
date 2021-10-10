#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 61. 특정 수 만들기(DFS : MS 인터뷰)

// N개의 원소로 구성된 자연수 집합이 주어지면, 집합의 원소와 ‘+’, ‘-’ 연산을 사용하여 특정
// 수인 M을 만드는 경우가 몇 가지 있는지 출력하는 프로그램을 작성하세요.각 원소는 연산에
// 한 번만 사용합니다.
// 예를 들어{ 2, 4, 6, 8 }이 입력되고, M = 12이면
// 2 + 4 + 6 = 12
// 4 + 8 = 12
// 6 + 8 - 2 = 12
// 2 - 4 + 6 + 8 = 12
// 로 총 4가지의 경우가 있습니다.만들어지는 경우가 존재하지 않으면 - 1를 출력한다.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=10)와 M(1<=M<=100) 주어집니다.
// 두 번째 줄에 집합의 원소 N개가 주어진다.각 원소는 중복되지 않는다.

// 출력설명
// 특정수가 만들어 지는 경우의 수를 출력한다. 없을 경우 -1를 출력한다.

// ex1)
// input
// 4 12
// 2 4 6 8

// output
// 4

int N, M, a[11], i, cnt, path[11];// path 경로확인

void DFS(int L, int sum) {
	if (L == N + 1) {
		if (sum == M) {
			cnt++;
			//for (i = 1;i <= N; i++) {
			//	printf("%d ", path[i]);
			//}
			//puts("");
		}
	}
	else {
		path[L] = a[L];
		DFS(L + 1, sum + a[L]);

		path[L] = -a[L];
		DFS(L + 1, sum - a[L]);

		path[L] = 0;
		DFS(L + 1, sum);
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d %d", &N, &M);

		for (i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}

		cnt = 0;
		DFS(1, 0);
		if (cnt == 0) printf("-1\n");
		else printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}