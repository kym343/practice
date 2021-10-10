#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 75. �ִ� ���� ������(priority_queue ���빮��)

// ������ ������ �������̴�. N���� ������� ���� ��û�� �ؿԴ�. �� ����� D�� �ȿ� �ͼ� ��
// ���� �� �ָ� M��ŭ�� �����Ḧ �ֱ�� �ߴ�.
// �� ����� ��û�� D�� M�� �������� ���� ���� ���� �� �� �ֵ��� ���� �������� ¥�� �Ѵ�.
// �� ������ Ư���� ������ �Ϸ翡 �ϳ��� ��������� ������ �� �� �ִ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=10,000)�� �־�����, ���� N���� �ٿ� M(1<=M<=10,000)��
// D(1 <= D <= 10,000)�� ���ʷ� �־�����.

// ��¼���
// ù ��° �ٿ� �ִ�� �� �� �ִ� ������ ����Ѵ�.

// ex1)
// input
// 6
// 50 2
// 20 1
// 40 2
// 60 3
// 30 3
// 30 1

// output
// 150

struct Data {
	int money;
	int day;

	Data(int x, int y) {
		money = x;
		day = y;
	}

	bool operator<(const Data& b)const {
		return day > b.day;
	}
};

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, M, D, maxx=-2147000000, sum=0;

		scanf("%d", &N);

		vector<Data> a;
		priority_queue<int> pQ;

		for (i = 0;i < N;i++) {
			scanf("%d %d", &M, &D);
			if (maxx < D) maxx = D;
			a.push_back(Data(M, D));
		}

		sort(a.begin(), a.end());

		j = 0;
		for (i = maxx; i >= 1;i--) {
			for ( ; j < N;j++) {
				if (a[j].day < i) break;
				pQ.push(a[j].money);
			}

			if (!pQ.empty()) {
				sum += pQ.top();
				pQ.pop();
			}
		}

		printf("%d\n", sum);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}