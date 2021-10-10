#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 25. ���� ���ϱ�

// N���� �л��� ���������� �ԷµǸ� �� �л��� ������ �Էµ� ������� ����ϴ� ���α׷���
// �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� N(1<=N<=100)�� �Էµǰ�, �� ��° �ٿ� ���������� �ǹ��ϴ� N���� ������ �Էµ�
// ��.���� ������ �Էµ� ��� ���� ������ ���� ó���Ѵ�.�� ���� ���� ������ 92���ε� 92
// ���� 3�� �����ϸ� 1���� 3���̰� �� ���� �л��� 4���� �ȴ�.������ 100�� �����̴�.

// ��¼���
// ù �ٿ� �Էµ� ������� ������ ����Ѵ�.

// ex1)
// input
// 5
// 90 85 92 95 90

// output
// 3 5 2 1 3

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N](); // ����
		int* b = new int[N](); // ���

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			b[i] = 1;
			if (i != 0) {
				for (int j = 0;j < i;j++) {
					if (a[j] > a[i]) {
						b[i]++;
					}
					else if (a[j] < a[i]) {
						b[j]++;
					}
				}
			}
		}

		for (int i = 0; i < N - 1; i++) {
			printf("%d ", b[i]);
		}
		printf("%d\n", b[N - 1]);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}