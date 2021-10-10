#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 78. 원더랜드(Kruskal MST 알고리즘 : Union&Find 활용)

// 원더랜드에 문제가 생겼다. 원더랜드의 각 도로를 유지보수하는 재정이 바닥난 것이다.
// 원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 도로를 선택하고 나머지
// 도로는 폐쇄하려고 한다.어떤 도로는 도로를 유지보수하면 재정에 도움이 되는 도로도 존재
// 한다.재정에 도움이 되는 도로는 비용을 음수로 표현했다.
// 아래의 그림은 그 한 예를 설명하는 그림이다.

// 위의 지도는 각 도시가 1부터 9로 표현되었고, 지도의 오른쪽은 최소비용 196으로 모든 도시
// 를 연결하는 방법을 찾아낸 것이다.

// 입력설명
// 첫째 줄에 도시의 개수 V(1≤V≤100)와 도로의 개수 E(1≤E≤1,000)가 주어진다. 다음 E개의
// 줄에는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.이는 A번 도시와 B번
// 도시가 유지비용이 C인 도로로 연결되어 있다는 의미이다.C는 음수일 수도 있으며, 절댓값이
// 1,000,000을 넘지 않는다.

// 출력설명
// 모든 도시를 연결하면서 드는 최소비용을 출려한다.

// ex1)
// input
// 9 12
// 1 2 12
// 1 9 25
// 2 3 10
// 2 8 17
// 2 9 8
// 3 4 18
// 3 7 55
// 4 5 44
// 5 6 60
// 5 7 38
// 7 8 35
// 8 9 15

// output
// 196

int unf[101];

struct Edge {
	int v1;
	int v2;
	int val;

	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}

	bool operator<(const Edge &b)const {
		return val < b.val;
	}
};

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int V, E, i, A, B, C, res = 0;

		vector<Edge> Ed;

		scanf("%d %d", &V ,&E);

		for (i = 1;i <= V; i++) {
			unf[i] = i;
		}


		for (i = 0;i < E; i++) {
			scanf("%d %d %d", &A, &B, &C); 
			Ed.push_back(Edge(A, B, C));
		}

		sort(Ed.begin(), Ed.end());

		for (i = 0; i < E; i++) {
			int fa = Find(Ed[i].v1);
			int fb = Find(Ed[i].v2);
			if (fa != fb) {
				res += Ed[i].val;
				Union(Ed[i].v1, Ed[i].v2);
			}
		}
		printf("%d\n", res);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}