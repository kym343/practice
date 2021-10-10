#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 87. 섬나라 아일랜드(BFS 활용)

// 섬나라 아일랜드의 지도가 격자판의 정보로 주어집니다. 각 섬은 1로 표시되어 상하좌우와 대
// 각선으로 연결되어 있으며, 0은 바다입니다.섬나라 아일랜드에 몇 개의 섬이 있는지 구하는
// 프로그램을 작성하세요.

// 1 1 0 0 0 1 0
// 0 1 1 0 1 1 0
// 0 1 0 0 0 0 0
// 0 0 0 1 0 1 1
// 1 1 0 1 1 0 0
// 1 0 0 0 1 0 0
// 1 0 1 0 1 0 0

// 만약 위와 같다면

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.
// 두 번째 줄부터 격자판 정보가 주어진다.

// 출력설명
// 첫 번째 줄에 섬의 개수를 출력한다.

// ex1)
// input
// 7
// 1 1 0 0 0 1 0
// 0 1 1 0 1 1 0
// 0 1 0 0 0 0 0
// 0 0 0 1 0 1 1
// 1 1 0 1 1 0 0
// 1 0 0 0 1 0 0
// 1 0 1 0 1 0 0

// output
// 5

int ch[51][51];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Loc {
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, k, cnt = 0;

		scanf("%d", &N);

		for (i = 1;i <= N; i++) {
			for (j = 1;j <= N;j++) {
				scanf("%d", &ch[i][j]);
			}
		}

		queue<Loc> Q;
		for (i = 1;i <= N; i++) {
			for (j = 1;j <= N;j++) {
				if (ch[i][j] == 1) {
					Q.push(Loc(i, j));
					ch[i][j] = 0;

					while (!Q.empty()) {
						Loc tmp = Q.front();
						Q.pop();

						for (k = 0; k < 8; k++) {
							if (ch[tmp.x + dx[k]][tmp.y + dy[k]] == 1) {
								Q.push(Loc(tmp.x + dx[k], tmp.y + dy[k]));
								ch[tmp.x + dx[k]][tmp.y + dy[k]] = 0;
							}
						}
					}
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}