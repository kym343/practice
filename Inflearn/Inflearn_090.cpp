#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 90. 라이언 킹 심바(삼성 SW역량평가 기출 : BFS활용)

// N×N 크기의 정글에 토끼 M마리와 어린 사자 심바가 있다. 정글은 1×1 크기의 격자로 이루
// 어져 있다.각 격자칸에는 토끼 1한마리가 있거나 또는 없을 수 있다.어린 사자 심바는 주어
// 진 정글에서 토끼를 잡아먹고 덩치를 키워 삼촌 스카에게 복수를 하러 갈 예정이다.
// 어린 사자 심바와 토끼는 모두 몸 크기를 가지고 있고, 이 크기는 자연수이다.가장 처음에 어
// 린 사자 심바의 크기는 2이고, 심바는 1초에 인접한 상하좌우 격자칸으로 이동할 수 있다.
// 어린 사자 심바는 자신보다 크기가 큰 토끼가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지
// 나갈 수 있다.심바는 자신보다 크기가 작은 토끼만 잡아먹을 수 있다.크기가 같은 토끼는 먹
// 을 수는 없지만, 그 토끼가 있는 칸은 지날 수 있다.
// 어린 사자 심바가 토끼를 잡아먹기 위한 이동규칙은 다음과 같다.

// 1) 더 이상 먹을 수 있는 토끼가 정글에 없다면 이제 심바는 삼촌 스카에게 복수하러 갈 수
// 있다.
// 2) 먹을 수 있는 토끼가 딱 한마리라면, 그 토끼를 먹으러 간다.
// 3) 먹을 수 있는 토끼가 2마리 이상이면, 거리가 가장 가까운 토끼를 먹으러 간다.
//   ① 거리는 심바가 있는 칸에서 먹으려고 하는 토끼가 있는 칸으로 이동할 때, 지나야하는 칸
//      의 개수의 최소값이다.
//   ② 가장 가까운 토끼가 많으면, 그 중 가장 위쪽에 있는 토끼, 그러한 토끼가 여러 마리라
//      면, 가장 왼쪽에 있는 토끼를 잡아먹는다.

// 심바가 격자칸 하나를 이동하는데 1초 걸리고, 토끼를 먹는데 걸리는 시간은 없다고 가정한다.
// 심바가 해당 격자칸의 토끼를 먹으면, 그 칸은 빈 칸이 된다.
// 심바는 자신의 몸 크기와 같은 마리수 만큼 잡아먹으면 몸의 크기가 1증가한다.
// 만약 심바의 몸크기가 5라면 자신보다 작은 토끼 5마리를 잡아먹으면 심바의 몸 크기는 6으로
// 변한다.
// 정글의 상태가 주어졌을 때, 심바가 몇 초 동안 토끼를 잡아먹고 삼촌 스카에게 복수를 하러
// 갈 수 있는지 구하는 프로그램을 작성하시오.

// 입력설명
// 첫 번째 줄에 정글의 크기 N(2 ≤ N ≤ 25)이 주어진다.
// 둘 번째 줄부터 정글의 지도 정보가 주어진다.
// 0은 빈칸이고, 각 토끼의 크기(1, 2, 3, 4, 5, 6, 7)과 9는 심바를 뜻한다.

// 출력설명
// 첫 번째 줄에 심바가 토끼를 잡아먹고 삼촌 스카에게 복수를 하러갈 수 있는 시간을 출력한다.

// ex1)
// input
// 3
// 0 1 3
// 1 9 1
// 0 1 1

// output
// 10

int map[26][26], ch[26][26];

int dx[4] = { -1, 0, 0, 1 }; //상 좌 우 하
int dy[4] = { 0, 1, -1, 0 };

struct State {
	int x, y, dist;
	State(int a, int b, int c) {
		x = a;
		y = b;
		dist = c;
	}
	bool operator<(const State& b) const {
		if (dist == b.dist) {
			if (x == b.x) return y > b.y;
			else return x > b.x;
		}
		else return dist > b.dist;
	}
};

struct Lion {
	int x;
	int y;
	int size;
	int ate;
	void sizeUp() {
		ate = 0;
		size++;
	}
};

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, res = 0;
		priority_queue<State> pQ;
		Lion simba;

		scanf("%d", &N);

		for (i = 1;i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);

				if (map[i][j] == 9) {
					simba.x = i;
					simba.y = j;
					map[i][j] = 0;
				}
			}
		}
		
		pQ.push(State(simba.x, simba.y, 0));
		simba.size = 2;
		simba.ate = 0;

		while (!pQ.empty()) {
			State tmp = pQ.top();
			pQ.pop();

			int x = tmp.x;
			int y = tmp.y;
			int dist = tmp.dist;

			if (map[x][y] != 0 && map[x][y] < simba.size) {// 잡아 먹을 수 있나
				simba.x = x;
				simba.y = y;
				simba.ate++;
				if (simba.ate >= simba.size) simba.sizeUp();
				map[x][y] = 0;
				for (i = 1;i <= N;i++) { // 체크 배열 초기화
					for (j = 1;j <= N;j++) {
						ch[i][j] = 0;
					}      
				}
				while (!pQ.empty()) pQ.pop(); // pQ 초기화
				res = tmp.dist; // 처음으로부터 마지막 토끼 잡아먹으려 이동한 거리
			}
			for (i = 0;i < 4;i++) { // 퍼져나가기
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 1 || xx > N || yy < 1 && yy > N ||
					map[xx][yy] > simba.size || ch[xx][yy] > 0) continue;
				pQ.push(State(xx, yy, dist + 1)); // 최초 심바의 위치로부터 계산
				ch[xx][yy] = 1;
			}
		}
		printf("%d\n", res);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}