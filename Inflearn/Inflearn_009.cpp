#include <iostream>
#include <algorithm>

using namespace std;

// 9. ����� ���

// �ڿ��� N�� �ԷµǸ� 1���� N������ �� ���ڵ��� ����� ������ ����ϴ� ���α׷��� �ۼ���
// ����.���� N�� 8�� �Էµȴٸ� 1(1��), 2(2��), 3(2��), 4(3��), 5(2��), 6(4��), 7(2��), 8(4	��) �� ���� �� ������ ����� ������ �������ϴ�.
// ����� ������ ���� 1���� ���ʴ�� ����� ������ ����ϸ� �˴ϴ�.
// 1 2 2 3 2 4 2 4 �� ���� ����Ѵ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(5<=N<=50,000)�� �־�����.

// ��¼���
// ù ��° �ٿ� 1���� N���� ����� ������ ������� ����Ѵ�.

// ex1)
// input
// 8

// output
// 1 2 2 3 2 4 2 4

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N + 1];
		fill_n(a, N+1, 1);

		for (int i=2; i <= N; i++) {
			for (int j = i; j <= N; j += i) {
				a[j]++;
			}
		}

		for (int i = 1; i <N; i++) {
			printf("%d ", a[i]);
		}
		printf("%d\n", a[N]);

	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}