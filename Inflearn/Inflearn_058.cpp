#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 58. ����Ʈ�� ���̿켱Ž��(DFS)

// �Ʒ� �׸��� ���� ����Ʈ���� ������ȸ�� ������ȸ�� �����غ�����.
//                  1
//              2        3
//            4   5    6   7

// ������ȸ ��� : 1 2 4 5 3 6 7
// ������ȸ ��� : 4 2 5 1 6 3 7
// ������ȸ ��� : 4 5 2 6 7 3 1

void DFS(int L) {
	if (L > 7) return;
	else {

		// ������ȸ ��� : 1 2 4 5 3 6 7
		//printf("%d ", L);

		DFS(L * 2);

		// ������ȸ ��� : 4 2 5 1 6 3 7
		//printf("%d ", L);

		DFS(L * 2 + 1);

		// ������ȸ ��� : 4 5 2 6 7 3 1
		printf("%d ", L);
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		DFS(1);
		printf("\n");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}