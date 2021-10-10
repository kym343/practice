#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 28. N!���� 0�� ����

// �ڿ��� N�� �ԷµǸ� N! ������ ���� �ڸ����� ���������� ��0���� �� �� �ִ��� ���ϴ� ���α�
// ���� �ۼ��ϼ���.
// ���� 5!= 5 �� 4 �� 3 �� 2 �� 1 = 120���� �����ڸ����� �������� ��0���� ������ 1�Դϴ�.
// ���� 12!= 479001600���� �����ڸ����� �������� ��0���� ������ 2�Դϴ�.

// �Է¼���
// ù �ٿ� �ڿ��� N(10<=N<=1,000)�� �Էµȴ�.

// ��¼���
// ���� �ڸ����� ���ӵ� 0�� ������ ����մϴ�.

// ex1)
// input
// 12

// output
// 5

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);
		
		int cnt = 0, num = 5;

		while (num<=N) {
			cnt += N / num;
			num *= 5;
		}

		printf("%d\n", cnt);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}