#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 111. ��������(�׷��� ����)

// ���������� � ���� �ϴ� ������ ã�� �˰����Դϴ�.
// ������ ���� ���İ��谡 �����ϰ� �������� �� ���� ���� ���İ��踦 �����ϸ鼭 ��ü ����
// ������ ¥�� �˰����Դϴ�.
// ���� �Ʒ��� ���� ���� ������ ���� ��Ű�鼭 ��ü ���� ������ ���Ѵٸ�
// 1 4 //1������ �ϰ� �� �� 4������ �ؾ��Ѵ�.
// 5 4
// 4 3
// 2 5
// 2 3
// 6 2

// ��ü ���� ������ 1, 6, 2, 5, 4, 3�� ���� ���� �� �ִ�.��ü ���� ������ ���� ������ �ֽ�
// �ϴ� �� �߿� �ϳ��Դϴ�.


// �Է¼���
// ù ��° �ٿ� ��ü ���� ���� N�� ���� ���� ������ ���� M�� �־����ϴ�.
// �� ��° �ٺ��� M���� ������ �־����ϴ�.

// ��¼���
// ��ü ���� ������ ����մϴ�.

// ex1)
// input
// 6 6
// 1 4
// 5 4
// 4 3
// 2 5
// 2 3
// 6 2

// output
// 1 6 2 5 4 3


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, k, a, b;

		cin >> N >> M;

		vector<int> dy(N + 1, 0);
		vector<int> graph[100];
		queue<int> Q;

		for (i = 1;i <= M;i++) {
			cin >> a >> b;
			dy[b]++;
			graph[a].push_back(b);
		}

		for (i = 1;i <= N;i++) {
			if (dy[i] == 0) Q.push(i);
		}

		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			cout << now << " ";
			for (i = 0;i < graph[now].size();i++) {
				int next = graph[now][i];
				dy[next]--;
				if (dy[next] == 0) Q.push(next);
			}
		}
		cout << endl;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}