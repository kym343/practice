#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 64. 경로 탐색(DFS)

// 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프
// 로그램을 작성하세요.아래 그래프에서 1번 정점에서 5번 정점으로 가는 가지 수는

// 1 2 3 4 5
// 1 2 5
// 1 3 4 2 5
// 1 3 4 5
// 1 4 2 5
// 1 4 5

// 총 6 가지입니다.

// 입력설명
// 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
// 결정보가 주어진다.

// 출력설명
// 총 가지수를 출력한다.

// ex1)
// input
// 5 9
// 1 2
// 1 3
// 1 4
// 2 1
// 2 3
// 2 5
// 3 4
// 4 2
// 4 5

// output
// 6
int N, M, cnt;
int a[21][21], ch[21];

void DFS(int v) {
	int i;
	if (v == N) {
		cnt++;
	}
	else {
		for (i = 1;i <= N;i++) {
			if (a[v][i] == 1 && ch[i]==0) {
				ch[i] = 1;
				DFS(i);
				ch[i] = 0; // 다시 닫아줘야한다!
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
		int i, x ,y;

		scanf("%d %d", &N, &M);

		for (i = 1;i <= M;i++) {
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
		}
		
		cnt=0;
		ch[1] = 1;
		DFS(1);
		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}