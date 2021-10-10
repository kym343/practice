#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 82. 순열구하기(DFS : Depth First Search)

// 자연수 N과 R이 주어지면 서로 다른 N개의 자연수 중 R개를 뽑아 일렬로 나열하는 프로그램
// 을 작성하세요.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=15)과 R(0<=R<=15)이 주어진다. 단 (N>=R)
// 두 번째 줄에 N개의 서로 다른 자연수가 오름차순으로 주어진다.

// 출력설명
// 순열의 각 경우를 아래와 같이 오름차순으로 출력한다. 마지막 줄에 총 개수도 출력한다.

// ex1)
// input
// 4 3
// 1 3 6 7

// output
// 1 3 6
// 1 3 7
// 1 6 3
// 1 6 7
// 1 7 3
// 1 7 6
// 3 1 6
// 3 1 7
// 3 6 1
// 3 6 7
// 3 7 1
// 3 7 6
// 6 1 3
// 6 1 7
// 6 3 1
// 6 3 7
// 6 7 1
// 6 7 3
// 7 1 3
// 7 1 6
// 7 3 1
// 7 3 6
// 7 6 1
// 7 6 3
// 24

int ch[16], a[16], res[16];
int N, R, cnt;
vector<int> graph;

void DFS(int L) {
	if (L == R) {
		for (int i = 0; i < R;i++) {
			printf("%d ", res[i]);
		}
		puts("");
		cnt++;
	}
	else {
		for (int i = 1;i <= N;i++) {
			if (ch[i] == 0) {
				res[L] = a[i];
				ch[i] = 1;

				DFS(L + 1);
				ch[i] = 0;

			}
		}
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i;

		scanf("%d %d", &N, &R);

		for (i = 1;i <= N;i++) {
			scanf("%d", &a[i]);
		}
		cnt = 0;

		DFS(0);
		printf("%d\n", cnt);

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}