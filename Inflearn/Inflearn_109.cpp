#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 109. �÷��̵� ���� �˰���

// N���� ���ð� �־�����, �� ���õ��� �����ϴ� ���ο� �ش� ���θ� �����ϴ� ����� �־���
// �� ��� ���ÿ��� ��� ���÷� �̵��ϴµ� ���̴� ����� �ּҰ��� ���ϴ� ���α׷��� �ۼ���
// ����.

// �Է¼���
// ù ��° �ٿ��� ������ ��N(N<=100)�� ���μ� M(M<=200)�� �־�����, M�ٿ� ���� ��������
// �� ���(20 ������ �ڿ���)�� �־�����.���� 1�� ���ÿ� 2�����ð� ����ǰ� �� ����� 13��
// �� ��1 2 13������ �־�����.

// ��¼���
// ��� ���ÿ��� ��� ���÷� �̵��ϴµ� ��� �ּ� ����� �Ʒ��� ���� ����Ѵ�.
// �ڱ��ڽ����� ���� ����� 0�Դϴ�.i�� �������� j�� �������� �� �� ���� ���� ����� ��M"��
// �� ����մϴ�.

// ex1)
// input
// 8
// 1 2 6
// 1 3 3
// 3 2 2
// 2 4 1
// 2 5 13
// 3 4 5
// 4 2 3
// 4 5 7

// output
// 0 5 3 6 13		//1�� �������� 2���������� 5, 1���� 3�� �������� 3, 1���� 4�� �������� 6......
// M 0 M 1 8		//2�� �������� 1�� �������δ� ���� �����Ƿ� ��M", .......
// M 2 0 3 10
// M 3 M 0 7
// M M M M 0

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, k, a, b, c;

		cin >> N >> M;

		vector<vector<int> > dy(N + 1, vector<int>(N + 1, 5000));
		for (i = 1;i <= M;i++) {
			cin >> a >> b >> c;
			dy[a][b] = c;
		}

		for (i = 1;i <= N;i++) dy[i][i] = 0;
		for (k = 1;k <= N; k++) {
			for (i = 1;i <= N;i++) {
				for (j = 1;j <= N;j++) {
					dy[i][j] = min(dy[i][j], dy[i][k] + dy[k][j]);
				}
			}
		}

		for (i = 1;i <= N;i++) {
			for (j = 1;j <= N;j++) {
				if (dy[i][j] == 5000) cout << "M ";
				else cout << dy[i][j] <<" ";
			}
			cout << endl;
		}
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}