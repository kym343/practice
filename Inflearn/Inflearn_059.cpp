#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 59. �κ�����(DFS)

// �ڿ��� N�� �־����� 1���� N������ ���Ҹ� ���� ������ �κ������� ��� ����ϴ� ���α׷�
// �� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=10)�� �־����ϴ�.

// ��¼���
// ù ��° �ٺ��� ������ �κ������� ����մϴ�. �κ������� ����ϴ� ������ ��¿������� ��
// ���� ������ ���� �մϴ�.�� �������� ������� �ʽ��ϴ�.

// ex1)
// input
// 3

// output
// 1 2 3
// 1 2
// 1 3
// 1
// 2 3
// 2
// 3

int N, ch[11], i;

void DFS(int L) {
	if (L == N + 1) {
		for (i = 1; i <= N; i++) {
			if(ch[i]==1) printf("%d ", i);
		}
		printf("\n");
	}
	else {
		ch[L] = 1;
		DFS(L + 1);
		ch[L] = 0;
		DFS(L + 1);
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d", &N);

		DFS(1);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}