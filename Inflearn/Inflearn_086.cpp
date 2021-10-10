#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 86. ���� ��� �Ÿ�(�Ｚ SW������ ���⹮�� : DFSȰ��)

// N��N ũ���� ���������� �ֽ��ϴ�. ���������� 1��1ũ���� ����ĭ���� �̷���� �ֽ��ϴ�. ��
// ����ĭ���� 0�� ��ĭ, 1�� ��, 2�� ���������� ǥ���˴ϴ�.�� ����ĭ�� ��ǥ(���ȣ, �� ��ȣ)
// �� ǥ���˴ϴ�.���ȣ�� 1������ N�������̰�, �� ��ȣ�� 1���� N�����Դϴ�.
// ���ÿ��� �� ������ �����ڹ�ްŸ����� �Ҵµ� �� ���� ���ڹ�ްŸ��� �ش� ���� ������ ����
// �ϴ� ����������� �Ÿ� �� �ּҰ��� �ش� ���� �����ڹ�ްŸ������ �Ѵ�.
// ���� �������� ���ڹ�ްŸ��� | x1 - x2 | +| y1 - y2 | �̴�.
// ���� ���, ������ ������ �Ʒ��� ���ٸ�

// 0 1 0 0
// 0 0 2 1
// 0 0 1 0
// 1 2 0 2

// (1, 2)�� �ִ� ���� (2, 3)�� �ִ� ���������� ���� ��� �Ÿ��� |1-2| + |2-3| = 2�� �ȴ�.
// �ֱ� ���ð� �Ұ�⿡ ������ �����׼� ����� ���������� �Ļ��ϰ� �ֽ��ϴ�.���� ������
// ���ÿ� �ִ� ������ �� M���� �츮�� �������� �������� �ְ� �����Ű���� �մϴ�.
// ������ �츮���� �ϴ� ������ M���� �����ϴ� �������� ������ ���ڹ�ްŸ��� �ּҰ� �Ǵ�
// M���� �������� �����Ϸ��� �մϴ�.
// ������ ���� ��� �Ÿ��� �� ������ ���� ��� �Ÿ��� ���� ���� ���մϴ�.

// �Է¼���
// ù° �ٿ� N(2 �� N �� 50)�� M(1 �� M �� 12)�� �־�����.
// ��° �ٺ��� ���� ������ �Էµȴ�.

// ��¼���
// ù° �ٿ� M���� �������� ���õǾ��� �� ������ �ּ� ���ڹ�ްŸ��� ����Ѵ�.

// ex1)
// input
// 4 4
// 0 1 2 0
// 1 0 2 1
// 0 2 1 2
// 2 0 1 2

// output
// 6

int N, M, minn, sum, res;
int ch[15];

vector<pair<int, int> > house;
vector<pair<int, int> > pizza;

void DFS(int L, int s) {
	if (L == M) {
		sum = 0;

		for (int i = 0; i < house.size(); i++) {
			int x1 = house[i].first;
			int y1 = house[i].second;

			minn = 2147000000;

			for (int j = 0; j < M; j++) {
				int x2 = pizza[ch[j]].first;
				int y2 = pizza[ch[j]].second;

				int dist = abs(x1 - x2) + abs(y1 - y2);
				if (minn > dist) minn = dist;
			}
			sum += minn;
		}
		if (res > sum) res = sum;
	}
	else {
		for (int i = s; i < pizza.size(); i++) {
			ch[L] = i;
			DFS(L + 1, i + 1);
		}
	}
}

int main(int argc, char** argv) {
	//ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i, j, tmp;

		scanf("%d %d", &N, &M);

		for (i = 1;i <= N;i++) {
			for (j = 1;j <= N;j++) {
				scanf("%d", &tmp);
				if (tmp == 1) house.push_back(make_pair(i, j));
				else if (tmp == 2) pizza.push_back(make_pair(i, j));
			}
		}
		printf("pizza.size(): %d\n", pizza.size());
		res = 2147000000;
		DFS(0, 0);
		
		printf("%d\n", res);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}