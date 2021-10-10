#include <iostream>
#include <algorithm>

using namespace std;

// 10. �ڸ����� ��

// N���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���ϰ�, �� ���� �ִ��� �ڿ����� ���
// �ϴ� ���α׷��� �ۼ��ϼ���. �� �ڿ����� �ڸ����� ���� ���ϴ� �Լ��� int digit_sum(int x)��
// �� �ۼ��ؼ� ���α׷��� �ϼ���.

// �Է¼���
// N���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���ϰ�, �� ���� �ִ��� �ڿ����� ���
// �ϴ� ���α׷��� �ۼ��ϼ���.�� �ڿ����� �ڸ����� ���� ���ϴ� �Լ��� int digit_sum(int x)��
// �� �ۼ��ؼ� ���α׷��� �ϼ���.

// ��¼���
// �ڸ����� ���� �ִ��� �ڿ����� ����Ѵ�. �ڸ����� ���� �ִ��� �ڿ����� �������� ��� ��
// �� ���� ���� ū ���� ����մϴ�.

// ex1)
// input
// 5
// 125 15232 79 1325 97

// output
// 97
int digit_sum(int x);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N];
		int* b = new int[N] {0};
		
		int max = -1;
		int sol = -1;

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);

			b[i] = digit_sum(a[i]);
			
			if (max < b[i]) {
				sol = a[i];
				max = b[i];
			}
			else if (max == b[i]) {
				if (sol < a[i]) {
					sol = a[i];
				}
			}
		}

		printf("%d\n", sol);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

int digit_sum(int x) {

	int sum = 0;
	int c = x;

	while (c > 0) {
		sum += c % 10;
		c /= 10;//(c - (c % 10)) / 10;
	}
	
	return sum;
}