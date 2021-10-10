#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 69. ����Ʈ�� ���̿켱Ž��(BFS)

// �Ʒ� �׸��� ���� ����Ʈ���� ���̿켱Ž���� ������. ���� ���� 6���� �Է¹޾� ó���غ���
// ��.
// 
//                  1
//              2        3
//            4   5    6   7

// ���� �켱 Ž�� : 1 2 3 4 5 6 7

// Queue �� �ְ� / ������ / �� ���� ����� ���� Queue�� �ִ´�

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


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}