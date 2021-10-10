#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 80. ���ͽ�Ʈ�� �˰���

// �Ʒ��� ����ġ ����׷������� 1�� �������� ��� ���������� �ּ� �Ÿ������ ����ϴ� ����
// �׷��� �ۼ��ϼ���. (��ΰ� ������ Impossible�� ����Ѵ�)

// �Է¼���
// ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ��
// �������� �Ÿ������ �־�����.

// ��¼���
// 1�� �������� �� �������� ���� �ּ� ����� 2�� �������� ���ʴ�� ����ϼ���.

// ex1)
// input
// 6 9
// 1 2 12
// 1 3 4
// 2 1 2
// 2 3 5
// 2 5 5
// 3 4 5
// 4 2 2
// 4 5 5
// 6 4 5

// output
// 2 : 11
// 3 : 4
// 4 : 9
// 5 : 14
// 6 : impossible

struct Edge {
	int vex;
	int dis;

	Edge(int a, int b) {
		vex = a;
		dis = b;
	}

	bool operator<(const Edge& b) const{
		return dis > b.dis;
	}
};

// ���ͽ�Ʈ�� -> �������� ����� ����!

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, a, b, c, sum;

		scanf("%d %d", &N, &M);

		priority_queue<Edge> pQ; // priority_queue<Edge, vector<Edge>, greater<Edge> > pQ;
		vector<pair<int, int> > graph[30];
		vector<int>  dist(N + 1, 2147000000); // dist[i] : 1�� �������� i �������� ���� �ּ� ���
		
		for (i = 0;i < M;i++) {
			scanf("%d %d %d", &a, &b, &c);

			// �ܹ��� ����ġ ���� ����Ʈ
			graph[a].push_back(make_pair(b, c));
		}

		pQ.push(Edge(1, 0));
		dist[1] = 0;
		while (!pQ.empty()) {
			int now = pQ.top().vex;  // ���� ����
			int cost = pQ.top().dis; // ���� ������ ���
			pQ.pop();

			if (cost > dist[now]) continue; // �̹� �ּҰ��� ����Ǿ������� pQ�� �ִ� �� �׳� pop�ϱ� ���ؼ�
			                                // top�� (2, 12) �϶� �̹� 2���� 11�� ����� �����Ƿ� �Ÿ���
			for (i = 0;i < graph[now].size();i++) {
				int next = graph[now][i].first;
				int nextDis = cost + graph[now][i].second;

				if (dist[next] > nextDis) { // ����� ������ ������ ����!
					dist[next] = nextDis;
					pQ.push(Edge(next, nextDis)); // ���ŵ� �Ÿ� ���� ������ ���ɼ� �����Ƿ� pQ�� �ִ´� 
				}
			}

		}

		for (i = 2; i <= N; i++) {
			if (dist[i] != 2147000000) printf("%d : %d\n", i, dist[i]);
			else printf("%d : impossible\n");
		}
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}