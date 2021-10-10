#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 66. 경로 탐색(DFS : 인접리스트 방법) ver. Vector

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

// ###############################################################
// vector<int> c[3]; // c라는 이름을 가진 vector가 3개 생김
// c[0].push_back(1);
// c[1].push_back(2);
// c[2].push_back(3);
// printf("%d\n", c[2][0]);
// 
// vector<pair<int, int> > graph[3];
// graph[1].push_back({3, 5});
// graph[1].push_back({2, 7});
// graph[1].push_back({1, 8});
// graph[2].push_back(make_pair(7, 7)); // make_pair(7, 7) = {7 , 7}
// printf("%d %d\n", graph[2][0].first, graph[2][0].second);
// ###############################################################

int N, M, ch[30], cnt = 0;
vector<int> map[30];

void DFS(int v) {
	int i;
	if (v == N) cnt++;
	else {
		for (i = 0;i < map[v].size();i++) {
			if (ch[map[v][i]]==0) {
				ch[map[v][i]] = 1;
				DFS(map[v][i]);
				ch[map[v][i]] = 0;
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
		scanf("%d %d", &N, &M);

		int i, a, b;

		for (i = 0;i < M;i++) {
			scanf("%d %d", &a, &b);
			map[a].push_back(b);
		}
		ch[1] = 1;
		DFS(1);
		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}