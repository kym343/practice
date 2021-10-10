#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 107. ������ȯ

// ������ ���� ���� ������ �������� �־��� ������ �Ž������� ���� ���� ���� �������� ��ȯ
// ���ַ��� ��� �ָ� �Ǵ°� ? �� ������ ������ ������ �� �� �ִ�.

// �Է¼���
// ù ��° �ٿ��� ������ �������� N(1<=N<=12)�� �־�����. �� ��° �ٿ��� N���� ������ ��
// ���� �־�����, �� �����ٿ� �Ž��� �� �ݾ� M(1 <= M <= 500)�� �־�����.
// �� ������ ������ 100���� ���� �ʴ´�.

// ��¼���
// ù ��° �ٿ� �Ž��� �� ������ �ּҰ����� ����Ѵ�.

// ex1)
// input
// 3
// 1 2 5
// 15

// output
// 3

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j;

		cin >> N;
		vector<int> arr(N, 0);
		for (i = 0;i < N;i++) {
			cin >> arr[i];
		}

		cin >> M;
		vector<int> dy(M+1, 0);
		for (i = 1;i <= M;i++) {
			dy[i] = i;
		}


		for (i = 0;i < N;i++) {
			for (j = arr[i];j <= M;j++) {
				dy[j] = min(dy[j], dy[j - arr[i]] + 1);
			}
		}

		cout << dy[M] << endl;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}