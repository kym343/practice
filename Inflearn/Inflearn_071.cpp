#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 71. �۾��� ã��(BFS : ����Ʈ��Ž��)

// ������ �۾����� �Ҿ���ȴ�. ������ �۾������� ��ġ�����Ⱑ �޷� �ִ�. ������ ��ġ�� �۾�
// ���� ��ġ�� �������� ��ǥ ������ �־����� ������ ���� ��ġ���� �۾����� ��ġ���� ������
// ���� ������� �̵��Ѵ�.
// ������ ��ī�� ������ Ÿ�� ���µ� �� ���� ������ ������ 1, �ڷ� 1, ������ 5�� �̵��� ��
// �ִ�.�ּ� �� ���� ������ ������ �۾����� ��ġ���� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ�
// �ϼ���.

// �Է¼���
// ù ��° �ٿ� ������ ��ġ S�� �۾����� ��ġ E�� �־�����. ������ ��ǥ ���� 1���� 10,000
// �����̴�.

// ��¼���
// ������ �ּ�Ƚ���� ���Ѵ�.

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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}