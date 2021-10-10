#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 88. �̷��� �ִܰŸ� ���(BFS Ȱ��)

// 7*7 ������ �̷θ� Ż���ϴ� �ִܰ���� ��μ��� ����ϴ� ���α׷��� �ۼ��ϼ���. ��μ���
// ��������� ���������� ���µ� �̵��� Ƚ���� �ǹ��Ѵ�.������� ������(1, 1) ��ǥ�̰�, Ż
// �� ��������(7, 7)��ǥ�̴�.�������� 1�� ���̰�, 0�� �����̴�.
// �������� �������� �����¿�θ� �����δ�.�̷ΰ� ������ ���ٸ�

// �� 0 0 0 0 0 0
//  0 1 1 1 1 1 0
//  0 0 0 1 0 0 0
//  1 1 0 1 0 1 1
//  1 1 0 1 0 0 0
//  1 0 0 0 1 0 0
//  1 0 1 0 0 0 ��

// �Է¼���
// ù ��° �ٺ��� 7*7 ������ ������ �־����ϴ�.

// ��¼���
// ù ��° �ٿ� �ִ����� ������ ĭ�� ���� ����Ѵ�. ������ �� ������ -1�� ����Ѵ�.

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

int dx[4] = { -1, 1, 0, 0 }; // �����¿�
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


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}