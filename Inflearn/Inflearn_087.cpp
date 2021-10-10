#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 87. ������ ���Ϸ���(BFS Ȱ��)

// ������ ���Ϸ����� ������ �������� ������ �־����ϴ�. �� ���� 1�� ǥ�õǾ� �����¿�� ��
// �������� ����Ǿ� ������, 0�� �ٴ��Դϴ�.������ ���Ϸ��忡 �� ���� ���� �ִ��� ���ϴ�
// ���α׷��� �ۼ��ϼ���.

// 1 1 0 0 0 1 0
// 0 1 1 0 1 1 0
// 0 1 0 0 0 0 0
// 0 0 0 1 0 1 1
// 1 1 0 1 1 0 0
// 1 0 0 0 1 0 0
// 1 0 1 0 1 0 0

// ���� ���� ���ٸ�

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=20)�� �־����ϴ�.
// �� ��° �ٺ��� ������ ������ �־�����.

// ��¼���
// ù ��° �ٿ� ���� ������ ����Ѵ�.

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


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}