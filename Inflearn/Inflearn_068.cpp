#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 68. 최소비용(DFS : 가중치 방향그래프 인접리스트)

// 가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그
// 램을 작성하세요.

// 입력설명
// 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
// 결정보가 주어진다.

// 출력설명
// 총 가지수를 출력한다.

// ex1)
// input
// 5 8
// 1 2 12
// 1 3 6
// 1 4 10
// 2 3 2
// 2 5 2
// 3 4 3
// 4 2 2
// 4 5 5

// output
// 13

int N, M, ch[21], minn=2147000000;
vector<pair<int, int> > a[21];

void DFS(int v, int sum) {
	int i;
	if (v == N) {
		if (sum < minn) minn = sum;
	}
	else {
		for (i = 0;i < a[v].size(); i++) {
			if (ch[a[v][i].first] == 0) {
				ch[a[v][i].first] = 1;
				DFS(a[v][i].first, sum + a[v][i].second);
				ch[a[v][i].first] = 0;
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
		int i, x, y, tmp;
		scanf("%d %d", &N, &M);

		for (i = 0;i < M;i++) {
			scanf("%d %d %d", &x, &y, &tmp);
			a[x].push_back({ y, tmp }); // = a[x].push_back(make_pair( y, tmp ));
		}
		ch[1] = 1;
		DFS(1, 0);
		printf("%d\n", minn);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}