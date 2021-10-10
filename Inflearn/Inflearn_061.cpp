#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 61. Ư�� �� �����(DFS : MS ���ͺ�)

// N���� ���ҷ� ������ �ڿ��� ������ �־�����, ������ ���ҿ� ��+��, ��-�� ������ ����Ͽ� Ư��
// ���� M�� ����� ��찡 �� ���� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.�� ���Ҵ� ���꿡
// �� ���� ����մϴ�.
// ���� ���{ 2, 4, 6, 8 }�� �Էµǰ�, M = 12�̸�
// 2 + 4 + 6 = 12
// 4 + 8 = 12
// 6 + 8 - 2 = 12
// 2 - 4 + 6 + 8 = 12
// �� �� 4������ ��찡 �ֽ��ϴ�.��������� ��찡 �������� ������ - 1�� ����Ѵ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=10)�� M(1<=M<=100) �־����ϴ�.
// �� ��° �ٿ� ������ ���� N���� �־�����.�� ���Ҵ� �ߺ����� �ʴ´�.

// ��¼���
// Ư������ ����� ���� ����� ���� ����Ѵ�. ���� ��� -1�� ����Ѵ�.

// ex1)
// input
// 4 12
// 2 4 6 8

// output
// 4

int N, M, a[11], i, cnt, path[11];// path ���Ȯ��

void DFS(int L, int sum) {
	if (L == N + 1) {
		if (sum == M) {
			cnt++;
			//for (i = 1;i <= N; i++) {
			//	printf("%d ", path[i]);
			//}
			//puts("");
		}
	}
	else {
		path[L] = a[L];
		DFS(L + 1, sum + a[L]);

		path[L] = -a[L];
		DFS(L + 1, sum - a[L]);

		path[L] = 0;
		DFS(L + 1, sum);
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d %d", &N, &M);

		for (i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}

		cnt = 0;
		DFS(1, 0);
		if (cnt == 0) printf("-1\n");
		else printf("%d\n", cnt);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}