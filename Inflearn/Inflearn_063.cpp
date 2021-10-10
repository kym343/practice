#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 63. �������(����ġ ����׷���)

// �Ʒ� �׸��� ���� �׷��� ������ ������ķ� ǥ���غ�����.

// �Է¼���
// ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ��
// �������� �Ÿ������ �־�����.

// ��¼���
// ��������� ����ϼ���.

// ex1)
// input
// 6 9
// 1 2 7
// 1 3 4
// 2 1 2
// 2 3 5
// 2 5 5
// 3 4 5
// 4 2 2
// 4 5 5
// 6 4 5

// output
// 0 7 4 0 0 0
// 2 0 5 0 5 0
// 0 0 0 5 0 0
// 0 2 0 0 5 0
// 0 0 0 0 0 0
// 0 0 0 5 0 0

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, tmp, x, y;

		scanf("%d %d", &N, &M);

		int** a = new int*[N]();
		for (i = 0; i < N; i++) {
			a[i] = new int[N] {0};
		}

		for (i = 0;i < M;i++) {
			scanf("%d %d %d", &x, &y, &tmp);

			a[x - 1][y - 1] = tmp;
		}


		for (i = 0;i < N;i++) {
			for (j = 0;j < N;j++) {
				printf("%d ", a[i][j]);
			}
			puts("");
		}
		delete a;
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}