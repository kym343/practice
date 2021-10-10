#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 48. �� ���� ��հ� ���� ����� ��

// <�׸� 1>�� ���� 9 �� 9 �����ǿ� ������ 81���� �ڿ����� �־��� ��, �� ���� ����� ���ϰ�,
// �� ��հ� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.����� �Ҽ��� ù ° �ڸ����� ��
// �ø��մϴ�.��հ� ����� ���� �� ���̸� �� �� ū ���� ����ϼ���.

// �Է¼���
// ù ° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� ��ȩ ���� �ڿ����� �־�����. �־����� �ڿ����� 100��
// �� �۴�.

// ��¼���
// ù° �ٿ� ù ��° �ٺ��� �� �ٿ� ������ ��հ� �� �࿡�� ��հ� ���� ����� ���� ����Ѵ�.

// ex1)
// input
// 3 23 85 34 17 74 25 52 65
// 10 7 39 42 88 52 14 72 63
// 87 42 18 78 53 45 18 84 53
// 34 28 64 85 12 16 75 36 55
// 21 77 45 35 28 75 90 76 1
// 25 87 65 15 28 11 37 28 74
// 65 27 75 41 7 89 78 64 39
// 47 47 70 45 23 65 3 41 44
// 87 13 82 38 50 12 48 29 80

// output
// 42 34
// 43 42
// 53 53
// 45 36
// 50 45
// 41 37
// 54 64
// 43 44
// 49 50

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, sum, cnt = 0, minn, pos;

		int* a = new int[9]; //vector< vector<int> > a(9, vector<int>(9,0));
		int* avg = new int[9];
		int* res = new int[9];

		for (i = 0; i < 9; i++) {
			sum = 0;
			for (j = 0; j < 9; j++) {
				scanf("%d", &a[j]);
				sum += a[j];
			}

			avg[i] = round((sum / 9.0)); // int((sum / 9.0) + 0.5)
			minn = 2147000000;
			pos = 0;
			for (j = 0; j < 9; j++) {
				if (minn >= abs(a[j] - avg[i])) {
					if (minn == abs(a[j] - avg[i]) && a[pos] > a[j]) {
						continue;
					}
					minn = abs(a[j] - avg[i]);
					pos = j;
					res[i] = a[pos];
				}
			}
		}

		for (i = 0; i < 9; i++) {
			printf("%d %d\n", avg[i], res[i]);
		}

		delete a;
		delete avg;
		delete res;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}