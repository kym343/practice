#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 29. 3�� ������?(small)

// �ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���� �� 3�� ������ �� ��
// �ִ��� ���Ϸ��� �մϴ�.
// ���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5����
// 3�� ������ 2���Դϴ�.
// �ڿ��� N�� �ԷµǸ� 1���� N���� ���ڸ� ���� ��, 3�� ������ �� ������ ���Ͽ� ����ϴ�
// ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �ڿ����� ���� N(3<=N<=100,000)�� �־����ϴ�.

// ��¼���
// 3�� ������ ����ϼ���.

// ex1)
// input
// 15

// output
// 2

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int num, cnt = 0;
		for (int i = 3;i < N;i++) {
			num = i;
			while (num > 0) {
				if (num % 10 == 3) {
					cnt++;
				}
				num /= 10;
			}
		}
		printf("%d\n", cnt);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}