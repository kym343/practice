#include<iostream>
#include <algorithm>

using namespace std;

// 3. ������� ��

// �ڿ��� N�� �־����� �ڿ��� N�� ������� ���� ���İ� �Բ� ����ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �ڿ��� N�� �־����ϴ�. (3<N <= 100)

// ��¼���
// ù �ٿ� ���ϴ� ���İ� �Բ� ���� ����մϴ�.

// ex1)
// input
// 20

// output
// 1 + 2 + 4 + 5 + 10 = 22

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	int N;
	
	for (test_case = 0; test_case < T; test_case++) {
		cin >> N;

		int sum = 1;
		int another = N;

		printf("%d", 1);

		for (int i = 2; i < N; i++) {
			if (i > another) {
				break;
			}

			if (N % i == 0) {
				printf(" + %d", i);
				sum += i;

				if (another == N) {
					another = N / i;
				}
			}
		}
		printf(" = %d\n", sum);

	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}