#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 35. Special Sort(���� ���ͺ�)

// N���� ������ �ԷµǸ� ����� �Էµ� ���� �����ؾ� �Ѵ�.
// ���� ������ ���ʿ� ���������� ���ʿ� �־�� �Ѵ�.���� ���������� ���������� ��������
// ������ ����� �Ѵ�.

// �Է¼���
// ù ��° �ٿ� ���� N(5<=N<=100)�� �־�����, �� ���� �ٺ��� ������ ������ ������ �־���
// ��.���� 0�� �Էµ��� �ʴ´�.

// ��¼���
// ���ĵ� ����� ����Ѵ�.

// ex1)
// input
// 8
// 1 2 3 -3 -2 5 6 -6

// output
// -3 -2 -6 1 2 3 5 6

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);
		// ###############################################
		int i, idx=0, num;
		int* a = new int[N]();// ���
		int* b = new int[N]();// ���� -> ������

		for (i = 0;i < N;i++) {
			scanf("%d", &num);

			if (num > 0) {
				a[i - idx] = num;
			}
			else {
				b[idx] = num;
				idx++;
			}
		}

		for (i = idx;i < N;i++) {
			b[i] = a[i - idx];
		}

		for (i = 0;i < N;i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		// ###############################################
		// ��������(���� ����� �ڰ� ������ swap)
		//int i, j, tmp;
		//int* a = new int[N]();

		//for (i = 0;i < N;i++) {
		//	scanf("%d", &a[i]);
		//}
		//for (i = 0; i < N - 1; i++) {
		//	for (j = 0; j < N - i - 1;j++) {
		//		if (a[j] > 0 && a[j + 1] < 0) {
		//			tmp = a[j];
		//			a[j] = a[j + 1];
		//			a[j + 1] = tmp;
		//		}
		//	}
		//}

		//for (i = 0;i < N;i++) {
		//	printf("%d ", a[i]);
		//}
		//printf("\n");
		// ###############################################
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}