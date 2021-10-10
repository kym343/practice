#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 81. 벨만-포드 알고리즘

// N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 해당 도로를 통행하는 비용이 주어질
// 때 한 도시에서 다른 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 프로그램을 작성하세
// 요.

// 입력설명
// 첫 번째 줄에는 도시의 수N(N<=100)과 도로수 M(M<=200)가 주어지고, M줄에 걸쳐 도로정보
// 와 비용이 주어진다.만약 1번 도시와 2번도시가 연결되고 그 비용이 13이면 “1 2 13”으로
// 주어진다.그 다음 마지막 줄에 출발도시와 도착도시가 주어진다.

// 출력설명
// 출발도시에서 도착도시까지 가는데 걸리는 최소비용을 출력한다. 음의 사이클이 존재할 경우
// -1를 출력한다.

// ex1)
// input
// 5 7
// 1 2 5
// 1 3 4
// 2 3 -3
// 2 5 13
// 3 4 5
// 4 2 3
// 4 5 7
// 1 5

// output
// 14

struct Edge {
	int s;
	int e;
	int val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
};

int dist[101];

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, a, b, c, i, j;

		scanf("%d %d", &N, &M);

		vector<Edge> Ed;

		for (i = 1; i <= N; i++) {
			dist[i] = 2147000000;
		}

		for (i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);

			Ed.push_back(Edge(a, b, c));
		}

		scanf("%d %d", &a, &b);

		dist[a] = 0;
		for (i = 1; i < N;i++) {// 최소 1, 최대 N-1의 사이클
			for (j = 0;j < Ed.size();j++) { // 모든 간선 적용
				int u = Ed[j].s;
				int v = Ed[j].e;
				int w = Ed[j].val;
				if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
				}
			}
		}
		for (j = 0;j < Ed.size();j++) { // N번째 간선 적용
			int u = Ed[j].s;
			int v = Ed[j].e;
			int w = Ed[j].val;
			if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
				printf("-1\n");
				exit(0);
			}
		}

		printf("%d\n", dist[b]);
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}