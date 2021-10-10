#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 66. ��� Ž��(DFS : ��������Ʈ ���) ver. Vector

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

// ###############################################################
// vector<int> c[3]; // c��� �̸��� ���� vector�� 3�� ����
// c[0].push_back(1);
// c[1].push_back(2);
// c[2].push_back(3);
// printf("%d\n", c[2][0]);
// 
// vector<pair<int, int> > graph[3];
// graph[1].push_back({3, 5});
// graph[1].push_back({2, 7});
// graph[1].push_back({1, 8});
// graph[2].push_back(make_pair(7, 7)); // make_pair(7, 7) = {7 , 7}
// printf("%d %d\n", graph[2][0].first, graph[2][0].second);
// ###############################################################

int N, M, ch[30], cnt = 0;
vector<int> map[30];

void DFS(int v) {
	int i;
	if (v == N) cnt++;
	else {
		for (i = 0;i < map[v].size();i++) {
			if (ch[map[v][i]]==0) {
				ch[map[v][i]] = 1;
				DFS(map[v][i]);
				ch[map[v][i]] = 0;
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
		scanf("%d %d", &N, &M);

		int i, a, b;

		for (i = 0;i < M;i++) {
			scanf("%d %d", &a, &b);
			map[a].push_back(b);
		}
		ch[1] = 1;
		DFS(1);
		printf("%d\n", cnt);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}