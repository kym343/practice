#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 106. ���湮��(���� �˰���)

// �ְ� 17kg�� ���Ը� ������ �� �ִ� ������ �ִ�. �׸��� ���� 3kg, 4kg, 7kg, 8kg, 9kg��
// ���Ը� ���� 5������ ������ �ִ�.�� �������� ��ġ�� ���� 4, 5, 10, 11, 13�̴�.
// �� ������ ���濡 ��µ� 17kg�� ���� �����鼭 �ִ��� ��ġ�� �ǵ��� �Ϸ��� ��� ��ƾ�
// �ұ�� ? �� ������ ������ ������ ������ ����.�� ������ ������ ���� �� ���濡 ���� �� ��
// �ٴ� ���Դϴ�.

// �Է¼���
// ù ��° ���� ���� ������ ������ ���濡 ���� �� �ִ� ������ �Ѱ谪�� �־�����.
// �� ��° �ٺ��� �� ������ ���Կ� ��ġ�� �־�����.
// ������ ���幫�Դ� 1000kg�� ���� �ʴ´�.������ ������ 30�� �̳��̴�.

// ��¼���
// ù ��° �ٿ� ���濡 ���� �� �ִ� ������ �ִ밡ġ�� ����Ѵ�.

// ex1)
// input
// 4 11
// 5 12
// 3 8
// 6 14
// 4 8

// output
// 28

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, w, v;

		cin >> N >> M;

		vector<int> dy(M + 1, 0);
		for (i = 1;i <= N;i++) {
			cin >> w >> v;
			for (j = w;j <= M;j++) {
				dy[j] = max(dy[j], dy[j - w] + v);
			}
		}

		cout << dy[M] << endl;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}