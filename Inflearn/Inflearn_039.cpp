#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 39. �� �迭 ��ġ��

// ������������ ������ �� �� �迭�� �־����� �� �迭�� ������������ ���� ����ϴ� ���α׷�
// �� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� ù ��° �迭�� ũ�� N(1<=N<=100)�� �־����ϴ�.
// �� ��° �ٿ� N���� �迭 ���Ұ� ������������ �־����ϴ�.
// �� ��° �ٿ� �� ��° �迭�� ũ�� M(1 <= M <= 100)�� �־����ϴ�.
// �� ��° �ٿ� M���� �迭 ���Ұ� ������������ �־����ϴ�.
// �� �迭�� ���Ҵ� int�� ������ ũ�⸦ ���� �ʽ��ϴ�.

// ��¼���
// ������������ ���ĵ� �迭�� ����մϴ�.

// ex1)
// input
// 3
// 1 3 5
// 5
// 2 3 6 7 9

// output
// 1 2 3 3 5 6 7 9

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, idx_a=0, idx_b=0;

		scanf("%d", &N);

		int* a = new int[N]();
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}

		scanf("%d", &M);

		int* b = new int[M]();
		for (i = 0;i < M;i++) {
			scanf("%d", &b[i]);
		}

		int* c = new int[N+M]();
		// #############################################################
		//for (i = 0;i < N + M;i++) {
		//	if (idx_a != N && idx_b != M) {
		//		if (a[idx_a] <= b[idx_b]) {
		//			c[i] = a[idx_a];
		//			idx_a++;
		//		}
		//		else {
		//			c[i] = b[idx_b];
		//			idx_b++;
		//		}
		//	}
		//	else if (idx_a == N) {
		//		for (j = i;j < N + M;j++) {
		//			c[j] = b[idx_b];
		//			idx_b++;
		//		}
		//		break;
		//	}
		//	else if (idx_b == M) {
		//		for (j = i;j < N + M;j++) {
		//			c[j] = a[idx_a];
		//			idx_a++;
		//		}
		//		break;
		//	}
		//}
		// #############################################################
		int idx_c=0;
		while (idx_a < N && idx_b < M) {
			if (a[idx_a] < b[idx_b]) {
				c[idx_c++] = a[idx_a++];
			}
			else {
				c[idx_c++] = b[idx_b++];
			}
		}
		while (idx_a < N) c[idx_c++] = a[idx_a++];
		while (idx_b < M) c[idx_c++] = b[idx_b++];
		// #############################################################
		for (i = 0;i < N + M;i++) {
			printf("%d ", c[i]);
		}
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}