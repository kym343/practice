#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 108. �ִ����� ���ϱ�(���� �˰���)

// �̹� �����ø��ǾƵ��ȸ���� ���� ������ ���� ���Ͽ� ������ �������� �ֽ� N���� ������
// Ǯ���� �մϴ�.�� ������ �װ��� Ǯ���� �� ��� ������ Ǫ�µ� �ɸ��� �ð��� �־����� ��
// �ϴ�.���ѽð� M�ȿ� N���� ���� �� �ִ������� ���� �� �ֵ��� �ؾ� �մϴ�. (�ش繮����
// 	�ش�ð��� �ɸ��� Ǫ�� �ɷ� �����Ѵ�, �� ������ �Ѱ��� Ǯ �� �ֽ��ϴ�.)

// �Է¼���
// ù ��° �ٿ� ������ ����N(1<=N<=100)�� ���� �ð� M(10<=M<=1000)�� �־����ϴ�.
// �� ��° �ٺ��� N�ٿ� ���� ������ Ǯ���� ���� ������ Ǫ�µ� �ɸ��� �ð��� �־����ϴ�.

// ��¼���
// ù ��° �ٿ� ���� �ð��ȿ� ���� �� �ִ� �ִ� ������ ����մϴ�.

// ex1)
// input
// 5 20
// 10 5
// 25 12
// 15 8
// 6 3
// 7 4

// output
// 41

//  // ============== struct �߰� ==============
//struct problem {
//	int s, t;
//	problem(int a, int b) {
//		s = a;
//		t = b;
//	}
//	bool operator<(const problem& b) const {
//		return t < b.t;
//	}
//};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, T, i, j, w, v;

		cin >> N >> T;

		vector<int> dy(T + 1, 0);

		// ===================== 1D ��� =====================
		for (i = 1;i <= N;i++) {
			cin >> w >> v;
			for (j = T;j >= v;j--) { // �ߺ��� ���ֱ� ����(1������ ������ Ǯ������) �ڿ�������!!
				if (j >= v) dy[j] = max(dy[j], dy[j - v] + w);
			}
		}

		// ===================== 2D ��� =====================
		//vector<vector<int> > dy(N + 1, vector<int>(T + 1, 0));
		//vector<problem> prob;
		//for (i = 1;i <= N;i++) {
		//	cin >> w >> v;
		// 
		//  // ============== struct �߰� ==============
		//	//	prob.push_back(problem(w, v));
		//	//}
		//	//sort(prob.begin(), prob.end());

		//	//for (i = 1;i <= N;i++) {
		//	//	w = prob[i - 1].s;
		//	//	v = prob[i - 1].t;
		//	for (j = 1;j <= T;j--) {
		//		if (j >= v) dy[i][j] = max(dy[i - 1][j], dy[i - 1][j - v] + w);
		//		else dy[i][j] = dy[i - 1][j];
		//	}
		//}


		cout << dy[T] << endl;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}