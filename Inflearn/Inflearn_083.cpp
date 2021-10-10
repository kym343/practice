#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 83. ����� SEND+MORE=MONEY (MS���ͺ�)

// SEND+MORE=MONEY ��� ������ ������� �ֽ��ϴ�. �� ������� ���ϴ� ���α׷��� �ۼ�
// �ϼ���.

// �������
//   9 5 6 7
// + 1 0 8 5
// ---------
// 1 0 6 5 2
int a[8]; // 0 1 2 3 4 5 6 7
          // D E M N O R S Y
int ch[10];

int send() {
	return 1000 * a[6] + 100 * a[1] + 10 * a[3] + a[0];
}

int more() {
	return 1000 * a[2] + 100 * a[4] + 10 * a[5] + a[1];
}

int money() {
	return 10000 * a[2] + 1000 * a[4] + 100 * a[3] + 10 * a[1] + a[7];
}

void DFS(int L) {
	if (L == 8) {
		if (send() + more() == money()) {
			if (a[6] == 0 || a[2] == 0) return;
			printf("  %d %d %d %d\n", a[6], a[1], a[3], a[0]);
			printf("+ %d %d %d %d\n", a[2], a[4], a[5], a[1]);
			printf("---------\n");
			printf("%d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if (ch[i] == 0) {
				a[L] = i;
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
		DFS(0);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}