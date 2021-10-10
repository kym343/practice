#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 82. �������ϱ�(DFS : Depth First Search)

// �ڿ��� N�� R�� �־����� ���� �ٸ� N���� �ڿ��� �� R���� �̾� �Ϸķ� �����ϴ� ���α׷�
// �� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=15)�� R(0<=R<=15)�� �־�����. �� (N>=R)
// �� ��° �ٿ� N���� ���� �ٸ� �ڿ����� ������������ �־�����.

// ��¼���
// ������ �� ��츦 �Ʒ��� ���� ������������ ����Ѵ�. ������ �ٿ� �� ������ ����Ѵ�.

// ex1)
// input
// 4 3
// 1 3 6 7

// output
// 1 3 6
// 1 3 7
// 1 6 3
// 1 6 7
// 1 7 3
// 1 7 6
// 3 1 6
// 3 1 7
// 3 6 1
// 3 6 7
// 3 7 1
// 3 7 6
// 6 1 3
// 6 1 7
// 6 3 1
// 6 3 7
// 6 7 1
// 6 7 3
// 7 1 3
// 7 1 6
// 7 3 1
// 7 3 6
// 7 6 1
// 7 6 3
// 24

int ch[16], a[16], res[16];
int N, R, cnt;
vector<int> graph;

void DFS(int L) {
	if (L == R) {
		for (int i = 0; i < R;i++) {
			printf("%d ", res[i]);
		}
		puts("");
		cnt++;
	}
	else {
		for (int i = 1;i <= N;i++) {
			if (ch[i] == 0) {
				res[L] = a[i];
				ch[i] = 1;

				DFS(L + 1);
				ch[i] = 0;

			}
		}
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i;

		scanf("%d %d", &N, &R);

		for (i = 1;i <= N;i++) {
			scanf("%d", &a[i]);
		}
		cnt = 0;

		DFS(0);
		printf("%d\n", cnt);

	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}