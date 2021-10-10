#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 68. �ּҺ��(DFS : ����ġ ����׷��� ��������Ʈ)

// ����ġ ����׷����� �־����� 1�� �������� N�� �������� ���� �ּҺ���� ����ϴ� ���α�
// ���� �ۼ��ϼ���.

// �Է¼���
// ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ��
// �������� �־�����.

// ��¼���
// �� �������� ����Ѵ�.

// ex1)
// input
// 5 8
// 1 2 12
// 1 3 6
// 1 4 10
// 2 3 2
// 2 5 2
// 3 4 3
// 4 2 2
// 4 5 5

// output
// 13

int N, M, ch[21], minn=2147000000;
vector<pair<int, int> > a[21];

void DFS(int v, int sum) {
	int i;
	if (v == N) {
		if (sum < minn) minn = sum;
	}
	else {
		for (i = 0;i < a[v].size(); i++) {
			if (ch[a[v][i].first] == 0) {
				ch[a[v][i].first] = 1;
				DFS(a[v][i].first, sum + a[v][i].second);
				ch[a[v][i].first] = 0;
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
		int i, x, y, tmp;
		scanf("%d %d", &N, &M);

		for (i = 0;i < M;i++) {
			scanf("%d %d %d", &x, &y, &tmp);
			a[x].push_back({ y, tmp }); // = a[x].push_back(make_pair( y, tmp ));
		}
		ch[1] = 1;
		DFS(1, 0);
		printf("%d\n", minn);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}