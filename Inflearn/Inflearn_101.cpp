#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 101. ������ȹ���̶�? ��Ʈ��ũ �� �ڸ���(Bottom-Up)

// ������ ��Ʈ��ũ ���� 1m, 2m�� ���̸� ���� ������ �ڸ����� �մϴ�.
// ���� ��� 4m�� ��Ʈ��ũ ���� �־����ٸ�

// 1) 1m + 1m + 1m + 1m
// 2) 2m + 1m + 1m
// 3) 1m + 2m + 1m
// 4) 1m + 1m + 2m
// 5) 2m + 2m

// �� 5���� ����� ������ �� �ֽ��ϴ�. (2)�� (3)�� (4)�� ��� ������ �������� �ڸ��� ��ġ��
// �ٸ��� �ٸ� ���� �����Ѵ�.
// �׷��ٸ� ��Ʈ��ũ ���� ���̰� Nm��� �� ������ �ڸ��� ����� ������ �� �ֳ��� ?

// �Է¼���
// ù° ���� ��Ʈ��ũ ���� �� ������ �ڿ��� N(3��N��45)�� �־����ϴ�.

// ��¼���
// ù ��° �ٿ� �κ����������� �ִ� ���̸� ����Ѵ�.

// ex1)
// input
// 7

// output
// 21

int N, res;

int dy[50];

int DFS(int L) {
	if (dy[L] != 0) return dy[L];
	if (L == 1 || L == 2) return L;
	else return dy[L] = DFS(L - 2) + DFS(L - 1);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i, j;

		cin >> N;

		// ########## Bottom-Up ##########
		//dy[1] = 1;
		//dy[2] = 2;
		//for (i = 3;i<= N; i++) {
		//	dy[i] = dy[i - 2] + dy[i - 1];
		//}

		//cout << dy[N];

		// ###############################

		// ########## Top-Down ###########
		
		cout << DFS(N) << endl;

		// ###############################

	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}