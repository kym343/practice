#include<iostream>
#include <algorithm>

using namespace std;

// 1. 1���� N���� M�� �����

// �ڿ��� N�� �ԷµǸ� 1���� N������ �� �� M�� ������� ����ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �ڿ��� N�� M�� ���ʴ�� �Էµ˴ϴ�.(3 <= M<N <= 1000)

// ��¼���
// ù �ٿ� M�� ������� ����Ѵ�.

// ex1)
// input
// 15 3

// output
// 45

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	int N;
	int M;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;

		int sum = 0;

		for (int i = M; i <= N; i = i + M) {
			sum += i;
		}

		printf("%d\n", sum);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}