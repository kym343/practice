#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 88. 미로의 최단거리 통로(BFS 활용)

// 7*7 격자판 미로를 탈출하는 최단경로의 경로수를 출력하는 프로그램을 작성하세요. 경로수는
// 출발점에서 도착점까지 가는데 이동한 횟수를 의미한다.출발점은 격자의(1, 1) 좌표이고, 탈
// 출 도착점은(7, 7)좌표이다.격자판의 1은 벽이고, 0은 도로이다.
// 격자판의 움직임은 상하좌우로만 움직인다.미로가 다음과 같다면

// 출 0 0 0 0 0 0
//  0 1 1 1 1 1 0
//  0 0 0 1 0 0 0
//  1 1 0 1 0 1 1
//  1 1 0 1 0 0 0
//  1 0 0 0 1 0 0
//  1 0 1 0 0 0 도

// 입력설명
// 첫 번째 줄부터 7*7 격자의 정보가 주어집니다.

// 출력설명
// 첫 번째 줄에 최단으로 움직인 칸의 수를 출력한다. 도착할 수 없으면 -1를 출력한다.

// ex1)
// input
// 0 0 0 0 0 0 0
// 0 1 1 1 1 1 0
// 0 0 0 1 0 0 0
// 1 1 0 1 0 1 1
// 1 1 0 1 0 0 0
// 1 0 0 0 1 0 0
// 1 0 1 0 0 0 0

// output
// 12

int ch[8][8];
int map[8][8];

int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1, 1 };

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
		int i, j;

		for (i = 1; i <= 7; i++) {
			for (j = 1; j <= 7; j++) {
				scanf("%d", &ch[i][j]);
				map[i][j] = 2147000000;
			}
		}
		
		map[1][1] = 0;
		queue<Loc> Q;
		Q.push(Loc(1, 1));

		while (!Q.empty()) {
			Loc tmp = Q.front();
			Q.pop();
			for (i = 0;i < 4;i++) {
				if (ch[tmp.x + dx[i]][tmp.y + dy[i]] != 1 && tmp.x + dx[i] > 0 && tmp.x + dx[i] <= 7 
					&& tmp.y + dy[i] > 0 && tmp.y + dy[i] <= 7) {
					Q.push(Loc(tmp.x + dx[i], tmp.y + dy[i]));
					ch[tmp.x + dx[i]][tmp.y + dy[i]] = 1;
					map[tmp.x + dx[i]][tmp.y + dy[i]] = map[tmp.x][tmp.y] + 1;
				}
			}
		}
		if (map[7][7] != 0) printf("%d\n", map[7][7]);
		else printf("-1\n");
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}