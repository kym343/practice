#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 52. Ugly Numbers

// � ���� ���μ����� ���� �� �� ���μ��� 2 �Ǵ� 3 �Ǵ� 5�θ� �̷���� ���� Ugly
// Number��� �θ��ϴ�.Ugly Number�� ���ʴ�� �����
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......�Դϴ�.���� 1�� Ugly Number�� ù ��° ���� ��
// �ϴ�.�ڿ��� N�� �־����� Ugly Number�� ���ʷ� ���� �� N��° Ugly Number�� ���ϴ�
// ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �ڿ��� N(3<=N<=1500)�� �־����ϴ�.

// ��¼���
// ù �ٿ� N��° Ugly Number�� ����ϼ���.

// ex1)
// input
// 10

// output
// 12

// ex2)
// input
// 1500

// output
// 859963392

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// =======================================================================
		int N, i, p2, p3, p5, minn=2147000000;
		int a[1501];

		scanf("%d", &N);

		a[1] = 1;
		p2 = p3 = p5 = 1;
		for (i = 2;i <= N;i++) {
			if (a[p2] * 2 < a[p3] * 3) minn = a[p2] * 2;
			else minn = a[p3] * 3;
			if (a[p5] * 5 < minn) minn = a[p5] * 5;
			
			if (a[p2] * 2 == minn) p2++;
			if (a[p3] * 3 == minn) p3++;
			if (a[p5] * 5 == minn) p5++;
			a[i] = minn;
		}
		printf("%d\n", a[N]);
		// =======================================================================
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}