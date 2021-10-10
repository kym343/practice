#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 78. ��������(Kruskal MST �˰��� : Union&Find Ȱ��)

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
// 1,000,000�� ���� �ʴ´�.

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

int unf[101];

struct Edge {
	int v1;
	int v2;
	int val;

	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}

	bool operator<(const Edge &b)const {
		return val < b.val;
	}
};

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int V, E, i, A, B, C, res = 0;

		vector<Edge> Ed;

		scanf("%d %d", &V ,&E);

		for (i = 1;i <= V; i++) {
			unf[i] = i;
		}


		for (i = 0;i < E; i++) {
			scanf("%d %d %d", &A, &B, &C); 
			Ed.push_back(Edge(A, B, C));
		}

		sort(Ed.begin(), Ed.end());

		for (i = 0; i < E; i++) {
			int fa = Find(Ed[i].v1);
			int fb = Find(Ed[i].v2);
			if (fa != fb) {
				res += Ed[i].val;
				Union(Ed[i].v1, Ed[i].v2);
			}
		}
		printf("%d\n", res);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}