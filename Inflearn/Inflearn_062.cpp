#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 62. ��������

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
// 8
// 7 6 3 1 5 2 4 8

// output
// 1 2 3 4 5 6 7 8

int N, a[10], tmp[10], i;

void divide(int lt, int rt) {
	int mid;
	int p1, p2, p3;
	if (lt < rt) {
		mid = (lt + rt) / 2;
		divide(lt, mid);
		divide(mid + 1, rt);

		p1 = lt;
		p2 = mid+1;
		p3 = lt;
		while (p1 <= mid && p2 <= rt) {
			if (a[p1] < a[p2]) tmp[p3++] = a[p1++];
			else tmp[p3++] = a[p2++];
		}
		while (p1 <= mid) tmp[p3++] = a[p1++];
		while (p2 <= rt) tmp[p3++] = a[p2++];

		for (i = lt; i <= rt; i++) {
			a[i] = tmp[i];
		}
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d", &N);

		for (i = 1;i <= N;i++) {
			scanf("%d", &a[i]);
		}

		divide(1, N);

		for (i = 1;i <= N;i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}