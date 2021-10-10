#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 64. ��� Ž��(DFS)

// ����׷����� �־����� 1�� �������� N�� �������� ���� ��� ����� ���� ���� ����ϴ� ��
// �α׷��� �ۼ��ϼ���.�Ʒ� �׷������� 1�� �������� 5�� �������� ���� ���� ����

// 1 2 3 4 5
// 1 2 5
// 1 3 4 2 5
// 1 3 4 5
// 1 4 2 5
// 1 4 5

// �� 6 �����Դϴ�.

// �Է¼���
// ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ��
// �������� �־�����.

// ��¼���
// �� �������� ����Ѵ�.

// ex1)
// input
// 5 9
// 1 2
// 1 3
// 1 4
// 2 1
// 2 3
// 2 5
// 3 4
// 4 2
// 4 5

// output
// 6
int N, M, cnt;
int a[21][21], ch[21];

void DFS(int v) {
	int i;
	if (v == N) {
		cnt++;
	}
	else {
		for (i = 1;i <= N;i++) {
			if (a[v][i] == 1 && ch[i]==0) {
				ch[i] = 1;
				DFS(i);
				ch[i] = 0; // �ٽ� �ݾ�����Ѵ�!
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
		int i, x ,y;

		scanf("%d %d", &N, &M);

		for (i = 1;i <= M;i++) {
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
		}
		
		cnt=0;
		ch[1] = 1;
		DFS(1);
		printf("%d\n", cnt);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}