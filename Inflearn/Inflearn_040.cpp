#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 40. ������(�������� �˰���)

// �� ���� A, B�� �־����� �� ������ �������� ����ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� ���� A�� ũ�� N(1<=N<=30,000)�� �־����ϴ�.
// �� ��° �ٿ� N���� ���Ұ� �־����ϴ�.���Ұ� �ߺ��Ǿ� �־����� �ʽ��ϴ�.
// �� ��° �ٿ� ���� B�� ũ�� M(1 <= M <= 30, 000)�� �־����ϴ�.
// �� ��° �ٿ� M���� ���Ұ� �־����ϴ�.���Ұ� �ߺ��Ǿ� �־����� �ʽ��ϴ�.
// �� ������ ���Ҵ� int�� ������ ũ�⸦ ���� �ʽ��ϴ�.

// ��¼���
// �� ������ �������� �������� �����Ͽ� ����մϴ�.

// ex1)
// input
// 5
// 2 7 10 5 3
// 5
// 3 10 5 17 12

// output
// 3 5 10

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, pos1=0, pos2=0, pos3=0, tmp;
		// ##############################################
		//scanf("%d", &N);
		//
		//int* a = new int[N]();
		//for (i = 0;i < N;i++) {
		//	scanf("%d", &a[i]);
		//}

		//scanf("%d", &M);
		//int* b = new int[M]();
		//for (i = 0;i < M;i++) {
		//	scanf("%d", &b[i]);
		//}

		//int* c;
		//if (N <= M) {
		//	c = new int[N]();
		//}
		//else {
		//	c = new int[M]();
		//}

		//for (i = 1;i < N;i++) {
		//	tmp = a[i];
		//	for (j = i - 1;j >= 0;j--) {
		//		if (a[j] > tmp) {
		//			a[j + 1] = a[j];
		//		}
		//		else break;
		//	}
		//	a[j + 1] = tmp;
		//}

		//for (i = 1;i < M;i++) {
		//	tmp = b[i];
		//	for (j = i - 1;j >= 0;j--) {
		//		if (b[j] > tmp) {
		//			b[j + 1] = b[j];
		//		}
		//		else break;
		//	}
		//	b[j + 1] = tmp;
		//}

		//while (pos1 < N && pos2 < M) {
		//	if (a[pos1] == b[pos2]) {
		//		c[pos3++] = a[pos1++];
		//		pos2++;
		//	}
		//	else if (a[pos1] < b[pos2]) {
		//		pos1++;
		//	}
		//	else pos2++;		
		//}

		//for (i = 0;i < pos3;i++) {
		//	printf("%d ", c[i]);
		//}
		// ##############################################
		scanf("%d", &N);
		vector<int> a(N); // int* a = new int[N]();
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}
		sort(a.begin(), a.end()); // ��! �����ϴ� sort �Լ�!

		scanf("%d", &M);
		vector<int> b(M), c(N+M);
		for (i = 0;i < M;i++) {
			scanf("%d", &b[i]);
		}
		sort(b.begin(), b.end()); // ��! �����ϴ� sort �Լ�!

		while (pos1 < N && pos2 < M) {
			if (a[pos1] == b[pos2]) {
				c[pos3++] = a[pos1++];
				pos2++;
			}
			else if (a[pos1] < b[pos2]) {
				pos1++;
			}
			else pos2++;
		}

		for (i = 0;i < pos3;i++) {
			printf("%d ", c[i]);
		}

		// ##############################################
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}