#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 69. 이진트리 넓이우선탐색(BFS)

// 아래 그림과 같은 이진트리를 넓이우선탐색해 보세요. 간선 정보 6개를 입력받아 처리해보세
// 요.
// 
//                  1
//              2        3
//            4   5    6   7

// 넓이 우선 탐색 : 1 2 3 4 5 6 7

// Queue 에 넣고 / 꺼내고 / 그 값과 연결된 수를 Queue에 넣는다

// ex1)
// input
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7

// output
// 1 2 3 4 5 6 7

int Q[10], front = -1, back = -1, ch[10];
vector<int> map[10];

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i, a, b, x;
		for (i = 1;i <= 6; i++) {
			scanf("%d %d", &a, &b);
			map[a].push_back(b);
			map[b].push_back(a);
		}

		Q[++back] = 1;
		ch[1] = 1;
		while (front < back) {
			x = Q[++front];
			printf("%d ", x);
			for (i = 0; i < map[x].size(); i++) {
				if (ch[map[x][i]] == 0) {
					ch[map[x][i]] = 1;
					Q[++back] = map[x][i];
				}
			}
		}
		puts("");
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}