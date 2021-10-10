#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 71. 송아지 찾기(BFS : 상태트리탐색)

// 현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 현수의 위치와 송아
// 지의 위치가 직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지 다음과
// 같은 방법으로 이동한다.
// 현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수
// 있다.최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성
// 하세요.

// 입력설명
// 첫 번째 줄에 현수의 위치 S와 송아지의 위치 E가 주어진다. 직선의 좌표 점은 1부터 10,000
// 까지이다.

// 출력설명
// 점프의 최소횟수를 구한다.

// ex1)
// input
// 5 14

// output
// 3

int ch[10001], cnt[10001];


int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int S, E, x, i;
		int dx[3] = { -1, 1, 5 };
		queue<int> Q;

		scanf("%d %d", &S, &E);

		ch[S] = 1;
		Q.push(S);
		while (!Q.empty()) {
			x = Q.front();
			Q.pop();
			for (i = 0;i < 3;i++) {
				if (x + dx[i] <= 0 || x + dx[i] > 10000) continue; //
				if (ch[x + dx[i]] == 0) {
					ch[x + dx[i]] = 1;
					Q.push(x + dx[i]);
					// printf("%d -> %d\n", x, x + dx[i]);
					cnt[x + dx[i]] = cnt[x] + 1;
					// printf("dis[%d] = %d\n", x + dx[i], dis[x + dx[i]]);
				}
			}
			if (cnt[E] != 0) break;
		}
		printf("%d\n", cnt[E]);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}