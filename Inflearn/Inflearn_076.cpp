#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 76. ���װ��(�޸������̼�)

// ���װ���� N���� ���Ҹ� ������ ���տ��� R���� ���Ҹ� �̾� �κ������� ����� ����� ��
// �� �ǹ��Ѵ�. ������ nCr �� ǥ���ȴ�.
// N�� R�� �־����� ���װ���� ���ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=20)�� R(0<=R<=20)�� �־�����. �� (N>=R)

// ��¼���
// ù ��° �ٿ� ���װ�� ���� ����Ѵ�.

// ex1)
// input
// 5 3

// output
// 10

int dy[21][21];

// nCr = (n-1 C r-1) + (n-1 C r)
int DFS(int n, int r) {
	if (dy[n][r] > 0) return dy[n][r];						  // �޸������̼�
	if (n == r || r == 0) return 1;
	else return dy[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r); // �޸������̼� "dy[n][r]= "
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, R;

		scanf("%d %d", &N, &R);// 5C3 = 4C2 + 4C3 (5�� ���忡�� 5 ���� ��� + �� ���� ���)

		printf("%d\n", DFS(N, R));

		// =================================================
		//int N, R, a=1, b=1, small, i;

		//scanf("%d %d", &N, &R); // 5C3 = 5! / (3!)(2!) = 10
		//						  // a = 5!, b = 3! * 2!

		//if (N - R >= R) small = R;
		//else small = N - R;

		//for (i = 1;i <= small;i++) {
		//	a *= (N - i + 1);
		//	b *= i;
		//}

		//printf("%d\n", a / b);
		// =================================================
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}