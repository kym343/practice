#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 34. ��������

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
// 13 23 11 7 5 15

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
		int i, j, tmp;
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}

		for (i = N-1; i>0;i--) {
			for (j = 0;j < i;j++) {
				if (a[j] > a[j+1]) {
					tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
		}

		for (i = 0;i < N;i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}