#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 49. ����� �ִ�

// ������ ��ϳ��̸� �����մϴ�. �������� ���鿡�� �� �ܸ�� ������ ���鿡�� �� �ܸ��� ��
// �� �ִ� ��ϰ����� ����Ͽ� ����� ������ ���鿡�� �� ������� ����� ������ �߽��ϴ�.
// ������ ����� �״µ� ����ؾ� �� �ִ� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.

// ������ ���� �� �� ĭ�� ����� �����Դϴ�. ���鿡���� ���� ������ ������ ���鿡���� ����
// ������ �־����� ����� �� �ִ� ����� ���� ������ ����ϼ���

// �Է¼���
// ù �ٿ� ����� ũ�� N(3<=N<=10)�� �־����ϴ�. ����� ũ��� ���簢�� N*N�Դϴ�.
// �� ��° �ٿ� N���� ���鿡���� ���� ������ ���� �������� �־����ϴ�.
// �� ��° �ٿ� N���� ������ ���� ���� ������ ���ʺ��� �־����ϴ�.
// ����� ���̴� 10 �̸��Դϴ�.

// ��¼���
// ù �ٿ� ����� �ִ� ������ ����մϴ�.

// ex1)
// input
// 4
// 2 0 3 1
// 1 1 2 3

// output
// 17

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, tmp, sum = 0;

		scanf("%d", &N);

		int** a = new int* [N];   // vector< vector<int> > a(N, vector<int>(N, 0));
		for (i = 0; i < N; i++) {
			a[i] = new int[N];
		}

		for (j = 0; j < N; j++) {
			scanf("%d", &tmp);
			for (i = 0; i < N; i++) {
				a[i][j] = tmp;
			}
		}

		for (i = N - 1; i >= 0; i--) {
			scanf("%d", &tmp);
			for (j = 0; j < N; j++) {
				if (tmp < a[i][j]) {
					a[i][j] = tmp;
				}
			}
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				sum += a[i][j];
			}
		}
		delete a;
		printf("%d\n", sum);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}