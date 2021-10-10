#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 70. 그래프 최단거리(BFS)

// 다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.

// 입력설명
// 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
// 결정보가 주어진다.

// 출력설명
// 1번 정점에서 각 정점으로 가는 최소 간선수를 2번 정점부터 차례대로 출력하세요.

// ex1)
// input
// 6 9
// 1 3
// 1 4
// 2 1
// 2 5
// 3 4
// 4 5
// 4 6
// 6 2
// 6 5

// output
// 2 : 3
// 3 : 1
// 4 : 1
// 5 : 2
// 6 : 2

// ###########################################################
//int N, M, ch[21], minn[21];
//vector<int> a[21];
//
//void BFS(int v, int cnt, int t) {
//	int i;
//	if (v == t) {
//		if (cnt < minn[t]) minn[t] = cnt;
//	}
//	else {
//		for (i = 0;i < a[v].size();i++) {
//			if (ch[a[v][i]] == 0) {
//				ch[a[v][i]] = 1;
//				// printf("%d -> %d\n", v, a[v][i]);
//				BFS(a[v][i], ++cnt, t);
//				ch[a[v][i]] = 0;
//				cnt--;
//			}
//		}
//	}
//}
// ###########################################################
int N, M, ch[21], dis[21];
vector<int> a[21];
// ###########################################################

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i, x, y, tmp;

		scanf("%d %d", &N, &M);

		for (i = 0; i < M;i++) {
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		// ###################################################
		//for (i = 1; i <= N;i++) {
		//	minn[i] = 2147000000;
		//}

		//ch[1] = 1;
		//for (i = 2;i <= N;i++) {
		//	BFS(1, 0, i);
		//	printf("%d : %d\n", i, minn[i]);
		//}
		// ###################################################
		queue<int> Q;
		Q.push(1);
		ch[1] = 1;
		while (!Q.empty()) {
			tmp = Q.front();
			Q.pop();
			for (i = 0;i < a[tmp].size();i++) {
				if (ch[a[tmp][i]] == 0) {
					ch[a[tmp][i]] = 1;
					Q.push(a[tmp][i]);
					dis[a[tmp][i]] = dis[tmp] + 1;
				}
			}
		}

		for (i = 2; i <= N; i++) {
			printf("%d : %d\n", i, dis[i]);
		}
		// ###################################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}