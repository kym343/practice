#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 79. ��������(Prim MST �˰��� : priority_queue Ȱ��)

// �������忡 ������ �����. ���������� �� ���θ� ���������ϴ� ������ �ٴڳ� ���̴�.
// ��������� ��� ���ø� ���� �����ϸ鼭 �ּ��� ��������� �鵵�� ���θ� �����ϰ� ������
// ���δ� ����Ϸ��� �Ѵ�.� ���δ� ���θ� ���������ϸ� ������ ������ �Ǵ� ���ε� ����
// �Ѵ�.������ ������ �Ǵ� ���δ� ����� ������ ǥ���ߴ�.
// �Ʒ��� �׸��� �� �� ���� �����ϴ� �׸��̴�.

// ���� ������ �� ���ð� 1���� 9�� ǥ���Ǿ���, ������ �������� �ּҺ�� 196���� ��� ����
// �� �����ϴ� ����� ã�Ƴ� ���̴�.

// �Է¼���
// ù° �ٿ� ������ ���� V(1��V��100)�� ������ ���� E(1��E��1,000)�� �־�����. ���� E����
// �ٿ��� �� ���ο� ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����.�̴� A�� ���ÿ� B��
// ���ð� ��������� C�� ���η� ����Ǿ� �ִٴ� �ǹ��̴�.C�� ������ ���� ������, ������
// 1, 000, 000�� ���� �ʴ´�.

// ��¼���
// ��� ���ø� �����ϸ鼭 ��� �ּҺ���� ����Ѵ�.

// ex1)
// input
// 9 12
// 1 2 12
// 1 9 25
// 2 3 10
// 2 8 17
// 2 9 8
// 3 4 18
// 3 7 55
// 4 5 44
// 5 6 60
// 5 7 38
// 7 8 35
// 8 9 15

// output
// 196

int ch[1001];

struct Edge {
	int e;
	int val;
	Edge(int a, int b) { // ���ù�ȣ/����ġ
		e = a;
		val = b;
	}
	bool operator<(const Edge &b) const {
		return val > b.val;
	}
};

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int V, E, i, res=0, A, B, C;

		scanf("%d %d", &V, &E);

		priority_queue<Edge> pQ; // priority_queue<Edge, vector<Edge>, greater<Edge> pQ;
		vector<pair<int, int> > map[30];

		for (i = 0;i < E;i++) {
			scanf("%d %d %d", &A, &B, &C);
			
			// ������ ����ġ ���� ����Ʈ
			map[A].push_back(make_pair(B, C)); // A���� B�� �� �� �ִ�
			map[B].push_back(make_pair(A, C)); // B���� A�� �� �� �ִ�
		}

		pQ.push(Edge(1, 0));
		while (!pQ.empty()) {
			Edge tmp = pQ.top();
			pQ.pop();

			int v = tmp.e;
			int cost = tmp.val;

			if (ch[v] == 0) {
				res += cost;
				ch[v] = 1;
				for (i = 0; i < map[v].size();i++) {
					pQ.push(Edge(map[v][i].first, map[v][i].second));// first�� make_pair�ȿ� �տ���
				}
			}
		}
		printf("%d\n", res);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}