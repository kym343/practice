#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 32. ��������

// N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
// �����ϴ� ����� ���������Դϴ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
// �� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�.�� �ڿ����� ������ ���� �ȿ�
// �ֽ��ϴ�.

// ��¼���
// ������������ ���ĵ� ������ ����մϴ�.

// ex1)
// input
// 6
// 13 5 11 7 23 15

// output
// 5 7 11 13 15 23

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N]();

		int i, j, idx=0, tmp, flag;
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}
		// #################################################
		//for (j = 0;j < N - 1;j++) {
		//	int min = a[j];
		//	flag = 0;
		//	for (i = j+1; i < N; i++) {
		//		if (min > a[i]) {
		//			idx = i;
		//			min = a[i];
		//			flag++;
		//		}
		//	}
		//	if (flag != 0) {
		//		tmp = a[idx];
		//		a[idx] = a[j];
		//		a[j] = min;
		//	}
		//}

		//for (i = 0; i < N - 1; i++) {
		//	printf("%d ", a[i]);
		//}
		//printf("%d\n", a[i]);

		// #################################################
		for (i = 0; i < N; i++) {
			idx = i;
			for (j = i + 1;j < N; j++) {
				if (a[j] < a[idx]) {
					idx = j;
				}
			}
			tmp = a[i];
			a[i] = a[idx];
			a[idx] = tmp;
		}

		for (i = 0; i < N; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		// #################################################
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}