#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 44. ������ ���ϱ�(�̺а˻� ����)

// N���� �������� 1���� �������� �ֽ��ϴ�. �� �������� x1, x2, x3, ......, xN�� ��ǥ�� ��
// ����, ���������� ��ǥ�� �ߺ��Ǵ� ���� �����ϴ�.
// ������ C������ ���� ������ �ִµ�, �� ������ ���� ������ �ִ� ���� �������� �ʽ��ϴ�.
// �� ���������� �� ������ ���� ���� �� �ְ�, ���� ����� �� ���� �Ÿ��� �ִ밡 �ǰ� ����
// �������� ��ġ�ϰ� �ͽ��ϴ�.
// C������ ���� N���� �������� ��ġ���� �� ���� ����� �� ���� �Ÿ��� �ִ밡 �Ǵ� �� �ִ�
// ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �ڿ��� N(3<=N<=200,000)�� C(2<=C<=N)�� ������ ���̿� �ΰ� �־����ϴ�.
// ��° �ٺ��� N���� �ٿ� ���� �������� ��ǥ xi(0 <= xi <= 1,000,000,000)�� �� �ٿ� �ϳ���
// �־����ϴ�.

// ��¼���
// ù �ٿ� ���� ����� �� ���� �ִ� �Ÿ��� ����ϼ���.

// ex1)
// input
// 5 3
// 1
// 2
// 8
// 4
// 9

// output
// 3

int N;
bool Counter(vector<int> a, int d, int c) {
	int i, pre = 0, cnt = 0;

	for (i = 1; i < N; i++) {
		if (a[i] - a[pre] >= d) {
			pre = i;
			cnt++;
		}
		if (cnt == c) {
			return true;
		}
	}
	return false;
}
// ���� ���ϰ� �������� �� ���� -> �̺а˻� 

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int C, i, res = 0, left = 1, right, mid;
		int maxx = 0, minn = 1000000000;
		scanf("%d %d", &N, &C);

		vector<int> a(N);
		for (i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			if (a[i] > maxx) {
				maxx = a[i];
			}
			if (a[i] < minn) {
				minn = a[i];
			}
		}

		sort(a.begin(), a.end());

		right = maxx - minn;

		while (left <= right) {
			mid = (left + right) / 2;
			if (Counter(a, mid, C - 1) == true) {
				res = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		printf("%d\n", res);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}