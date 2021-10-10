#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 73. �ִ���(priority_queue : �켱���� ť)

// �ִ����� ��������Ʈ���� ������ �ڷᱸ���Դϴ�. �� ������ �θ� ��尪�� �����ڽİ� ����
// �� �ڽĳ���� ������ ũ�� Ʈ���� �����ϴ� ���Դϴ�.�׷��� �ϸ� Ʈ���� ��Ʈ(root)����
// �Էµ� ���� �� ���� ū ���� ����Ǿ� �ֽ��ϴ�.���� ��� 5 3 2 1 4 6 7������ �ԷµǸ�
// �ִ��� Ʈ���� �Ʒ��� ���� �����˴ϴ�.

//                7
//           4         6
//        1     3   2     5

// �ִ��� �ڷḦ �̿��Ͽ� ������ ���� ������ �ϴ� ���α׷��� �ۼ��ϼ���.
// 1) �ڿ����� �ԷµǸ� �ִ����� �Է��Ѵ�.
// 2) ���� 0 �� �ԷµǸ� �ִ������� �ִ��� ������ ����Ѵ�.
// (����� �ڷᰡ ������ - 1�� ����Ѵ�.)
// 3) - 1�� �ԷµǸ� ���α׷� �����Ѵ�.

// �Է¼���
// ù ��° �ٺ��� ���ڰ� �Էµȴ�. �ԷµǴ� ���ڴ� 100,000�� �����̸� �� ������ ũ��� ��
// ���� ������ �ִ�.

// ��¼���
// 2) ������ �� ����� �����ش�.

// ex1)
// input
// 5
// 3
// 6
// 0
// 5
// 0
// 2
// 4
// 0
// -1

// output
// 6
// 5
// 5

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int num;

		priority_queue<int> pQ;

		while (1) {
			scanf("%d", &num);

			if (num == -1) break;
			else if (num == 0) {
				if (pQ.empty()) printf("-1\n");
				else {
					printf("%d\n", pQ.top());
					pQ.pop();
				}
			}
			else {
				pQ.push(num);
			}
		}
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}