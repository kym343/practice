#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 63. 인접행렬(가중치 방향그래프)

// 아래 그림과 같은 그래프 정보를 인접행렬로 표현해보세요.

// 입력설명
// 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
// 결정보와 거리비용이 주어진다.

// 출력설명
// 인접행렬을 출력하세요.

// ex1)
// input
// 6 9
// 1 2 7
// 1 3 4
// 2 1 2
// 2 3 5
// 2 5 5
// 3 4 5
// 4 2 2
// 4 5 5
// 6 4 5

// output
// 0 7 4 0 0 0
// 2 0 5 0 5 0
// 0 0 0 5 0 0
// 0 2 0 0 5 0
// 0 0 0 0 0 0
// 0 0 0 5 0 0

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, tmp, x, y;

		scanf("%d %d", &N, &M);

		int** a = new int*[N]();
		for (i = 0; i < N; i++) {
			a[i] = new int[N] {0};
		}

		for (i = 0;i < M;i++) {
			scanf("%d %d %d", &x, &y, &tmp);

			a[x - 1][y - 1] = tmp;
		}


		for (i = 0;i < N;i++) {
			for (j = 0;j < N;j++) {
				printf("%d ", a[i][j]);
			}
			puts("");
		}
		delete a;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}