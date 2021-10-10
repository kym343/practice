#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 65. 미로탐색(DFS)

// 65. 미로탐색(DFS)
// 7 * 7 격자판 미로를 탈출하는 경로의 가지수를 출력하는 프로그램을 작성하세요.출발점은 격
// 자의(1, 1) 좌표이고, 탈출 도착점은(7, 7)좌표이다.격자판의 1은 벽이고, 0은 통로이다.격
// 자판의 움직임은 상하좌우로만 움직인다.미로가 다음과 같다면

// 위의 지도에서 출발점에서 도착점까지 갈 수 있는 방법의 수는 8가지이다.

// 입력설명
// 첫 번째 줄부터 7*7 격자의 정보가 주어집니다.

// 출력설명
// 첫 번째 줄에 경로의 가지수를 출력한다.

// ex1)
// input
// 0 0 0 0 0 0 0
// 0 1 1 1 1 1 0
// 0 0 0 1 0 0 0
// 1 1 0 1 0 1 1
// 1 1 0 0 0 0 1
// 1 1 0 1 1 0 0
// 1 0 0 0 0 0 0

// output
// 8

int a[8][8], cnt, ch[8][8];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(int x, int y) { 
	int i, xx, yy;
	if (x == 7 && y == 7) cnt++;
	else {
		// ##############################################################
		//if (x < 7 && a[x + 1][y] == 0 && ch[x + 1][y] == 0) {// down
		//	ch[x + 1][y] = 1;
		//	DFS(x + 1, y);
		//	ch[x + 1][y] = 0;
		//}
		//if (y < 7 && a[x][y + 1] == 0 && ch[x][y + 1] == 0) {// right
		//	ch[x][y + 1] = 1;
		//	DFS(x, y + 1);
		//	ch[x][y + 1] = 0;
		//}
		//if (x > 1 && a[x - 1][y] == 0 && ch[x - 1][y] == 0) {// up
		//	ch[x - 1][y] = 1;
		//	DFS(x - 1, y);
		//	ch[x - 1][y] = 0;
		//}
		//if (y > 1 && a[x][y - 1] == 0 && ch[x][y - 1] == 0) {// left
		//	ch[x][y - 1] = 1;
		//	DFS(x, y - 1);
		//	ch[x][y - 1] = 0;
		//}
		// ##############################################################
		for (i = 0; i < 4; i++) {
			xx = x + dx[i];
			yy = y + dy[i];

			if (xx < 1 || xx > 7 || yy < 1 || yy > 7) continue; // 좋네
			if (a[xx][yy] == 0 && ch[xx][yy] == 0) {
				ch[xx][yy] = 1;
				DFS(xx, yy);
				ch[xx][yy] = 0;
			}
		}
		// ##############################################################
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, tmp;

		for (i = 1;i < 8;i++) {
			for (j = 1;j < 8;j++) {
				scanf("%d", &tmp);
				a[i][j] = tmp;
			}
		}
		cnt = 0;
		ch[1][1] = 1;
		DFS(1, 1);

		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}