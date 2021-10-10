#include <iostream>
#include <algorithm>

using namespace std;

// 20. ���� ���� ��

// A, B �� ����� ���������� ������ �մϴ�. �� N���� ������ �Ͽ� A�� �̱�� A�� ����ϰ�,
// B�� �̱�� B�� ����մϴ�.��� ��쿡�� D�� ����մϴ�.
// ����, ����, ���� ������ 1:����, 2 : ����, 3 : ���� ���ϰڽ��ϴ�.
// ���� ��� N = 5�̸�

//   ȸ��   1 2 3 4 5
// A�� ���� 2 3 3 1 3
// B�� ���� 1 1 2 2 3
//   ����   A B A B D

// �� ����� �� ȸ�� ����, ����, �� ������ �־����� �� ȸ�� ���� �̰���� ����ϴ� ���α׷�
// �� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� ���� Ƚ���� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
// �� ��° �ٿ��� A�� �� ����, ����, �� ������ N�� �־����ϴ�.
// �� ��° �ٿ��� B�� �� ����, ����, �� ������ N�� �־����ϴ�.

// ��¼���
// �� �ٿ� �� ȸ�� ���ڸ� ����մϴ�. ����� ���� D�� ����մϴ�.

// ex1)
// input
// 5
// 2 3 3 1 3
// 1 1 2 2 3

// output
// A
// B
// A
// B
// D

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;
		scanf("%d", &N);

		int *a = new int[N](); // *** �����Ҵ�
		int num, diff;

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			if (a[i] == num) {
				printf("D\n");
			}
			else {
				diff = a[i] - num;
				if (diff == 1 || diff == -2) {
					printf("A\n");
				}
				else {
					printf("B\n");
				}
			}
		}
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}