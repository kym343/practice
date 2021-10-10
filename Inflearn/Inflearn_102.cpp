#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 102. �ִ� �κ� ��������(LIS : Longest Increasing Subsequence)

// N���� �ڿ����� �̷���� ������ �־����� ��, �� �߿��� ���� ��� �����ϴ�(���� ������ ū
// ����) ���ҵ��� ������ ã�� ���α׷��� �ۼ��϶�.���� ���, ���Ұ� 2, 7, 5, 8, 6, 4, 7,
// 12, 3 �̸� ���� ��� �����ϵ��� ���ҵ��� ���ʴ�� �̾Ƴ��� 2, 5, 6, 7, 12�� �̾Ƴ��� ��
// �̰� 5�� �ִ� �κ� ���������� ���� �� �ִ�.

// �Է¼���
// ù° ���� �ԷµǴ� �������� �� N(1��N��1,000, �ڿ���)�� �ǹ��ϰ�,
// ��° ���� N���� �Էµ����͵��� �־�����.

// ��¼���
// ù ��° �ٿ� �κ����������� �ִ� ���̸� ����Ѵ�.

// ex1)
// input
// 8
// 5 3 7 8 6 2 9 4

// output
// 4

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, res = -2147000000;

		cin >> N;

		vector<int> arr(N + 1), dy(N + 1); // dy[N]: arr[N]�� ������ ���̸鼭 ���� �� ������ ����

		for (i = 1;i <= N;i++) {
			cin >> arr[i];
		}

		dy[1] = 1;
		for (i = 2;i <= N;i++) {
			int maxx = 0;
			for (j = 1;j < i;j++) {
				if (arr[i] > arr[j] && maxx < dy[j]) maxx = dy[j];
			}
			dy[i] = maxx + 1;
			if (dy[i] > res) res = dy[i];
		}

		//for (i = 1;i <= N;i++) {
		//	cout <<"#" << i << " " <<arr[i] <<" : " << dy[i] << endl;
		//}
		cout << res << endl;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}