#include<iostream>
#include <algorithm>

using namespace std;

// 4. ���� ����

// N(2 <= N <= 100)���� ���̰� �Էµ˴ϴ�.�� N���� ��� �� ���� �������̰� ���� ���� ����
// �� ���ϱ�� ? �ִ� ���� ���̸� ����ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �ڿ��� N(2 <= N <= 100)�� �Էµǰ�, �� ���� �ٿ� N���� ���̰� �Էµȴ�.

// ��¼���
// ù �ٿ� �ִ� �������̸� ����մϴ�.

// ex1)
// input
// 10
// 13 15 34 23 45 65 33 11 26 42


// output
// 54

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		cin >> N;

		int num;
		cin >> num;

		int max = num; // -2147000000
		int min = num; // 2147000000

		for (int i = 1; i < N; i++) {
			cin >> num;

			if(num > max){
				max = num;
			}
			else if (num < min) {
				min = num;
			}
		}

		printf("%d\n", max - min);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}