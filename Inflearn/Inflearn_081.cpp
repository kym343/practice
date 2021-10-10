#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 81. ����-���� �˰���

// N���� ���ð� �־�����, �� ���õ��� �����ϴ� ���ο� �ش� ���θ� �����ϴ� ����� �־���
// �� �� ���ÿ��� �ٸ� ���÷� �̵��ϴµ� ���̴� ����� �ּҰ��� ���ϴ� ���α׷��� �ۼ��ϼ�
// ��.

// �Է¼���
// ù ��° �ٿ��� ������ ��N(N<=100)�� ���μ� M(M<=200)�� �־�����, M�ٿ� ���� ��������
// �� ����� �־�����.���� 1�� ���ÿ� 2�����ð� ����ǰ� �� ����� 13�̸� ��1 2 13������
// �־�����.�� ���� ������ �ٿ� ��ߵ��ÿ� �������ð� �־�����.

// ��¼���
// ��ߵ��ÿ��� �������ñ��� ���µ� �ɸ��� �ּҺ���� ����Ѵ�. ���� ����Ŭ�� ������ ���
// -1�� ����Ѵ�.

// ex1)
// input
// 5 7
// 1 2 5
// 1 3 4
// 2 3 -3
// 2 5 13
// 3 4 5
// 4 2 3
// 4 5 7
// 1 5

// output
// 14

struct Edge {
	int s;
	int e;
	int val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
};

int dist[101];

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, a, b, c, i, j;

		scanf("%d %d", &N, &M);

		vector<Edge> Ed;

		for (i = 1; i <= N; i++) {
			dist[i] = 2147000000;
		}

		for (i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);

			Ed.push_back(Edge(a, b, c));
		}

		scanf("%d %d", &a, &b);

		dist[a] = 0;
		for (i = 1; i < N;i++) {// �ּ� 1, �ִ� N-1�� ����Ŭ
			for (j = 0;j < Ed.size();j++) { // ��� ���� ����
				int u = Ed[j].s;
				int v = Ed[j].e;
				int w = Ed[j].val;
				if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
				}
			}
		}
		for (j = 0;j < Ed.size();j++) { // N��° ���� ����
			int u = Ed[j].s;
			int v = Ed[j].e;
			int w = Ed[j].val;
			if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
				printf("-1\n");
				exit(0);
			}
		}

		printf("%d\n", dist[b]);
	}
	
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}