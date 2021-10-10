#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 80. 다익스트라 알고리즘

// 아래의 가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용을 출력하는 프로
// 그램을 작성하세요. (경로가 없으면 Impossible를 출력한다)

// 입력설명
// 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
// 결정보와 거리비용이 주어진다.

// 출력설명
// 1번 정점에서 각 정점으로 가는 최소 비용을 2번 정점부터 차례대로 출력하세요.

// ex1)
// input
// 6 9
// 1 2 12
// 1 3 4
// 2 1 2
// 2 3 5
// 2 5 5
// 3 4 5
// 4 2 2
// 4 5 5
// 6 4 5

// output
// 2 : 11
// 3 : 4
// 4 : 9
// 5 : 14
// 6 : impossible

struct Edge {
	int vex;
	int dis;

	Edge(int a, int b) {
		vex = a;
		dis = b;
	}

	bool operator<(const Edge& b) const{
		return dis > b.dis;
	}
};

// 다익스트라 -> 간선값이 양수일 때만!

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, a, b, c, sum;

		scanf("%d %d", &N, &M);

		priority_queue<Edge> pQ; // priority_queue<Edge, vector<Edge>, greater<Edge> > pQ;
		vector<pair<int, int> > graph[30];
		vector<int>  dist(N + 1, 2147000000); // dist[i] : 1번 정점에서 i 정점까지 가는 최소 비용
		
		for (i = 0;i < M;i++) {
			scanf("%d %d %d", &a, &b, &c);

			// 단방향 가중치 인접 리스트
			graph[a].push_back(make_pair(b, c));
		}

		pQ.push(Edge(1, 0));
		dist[1] = 0;
		while (!pQ.empty()) {
			int now = pQ.top().vex;  // 현재 정점
			int cost = pQ.top().dis; // 현재 정점의 비용
			pQ.pop();

			if (cost > dist[now]) continue; // 이미 최소값이 저장되어있으면 pQ에 있는 건 그냥 pop하기 위해서
			                                // top이 (2, 12) 일때 이미 2에는 11이 저장되 있으므로 거른다
			for (i = 0;i < graph[now].size();i++) {
				int next = graph[now][i].first;
				int nextDis = cost + graph[now][i].second;

				if (dist[next] > nextDis) { // 저장된 값보다 작으면 갱신!
					dist[next] = nextDis;
					pQ.push(Edge(next, nextDis)); // 갱신된 거면 현재 정점될 가능성 있으므로 pQ에 넣는다 
				}
			}

		}

		for (i = 2; i <= N; i++) {
			if (dist[i] != 2147000000) printf("%d : %d\n", i, dist[i]);
			else printf("%d : impossible\n");
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}