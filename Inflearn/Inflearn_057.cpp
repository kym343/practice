#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 57. ����Լ� ������ ���

// 10���� N�� �ԷµǸ� 2������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. �� ����Լ��� �̿�
// �ؼ� ����ؾ� �մϴ�.

// �Է¼���
// ù ��° �ٿ� 10���� N(1<=N<=1,000)�� �־����ϴ�.

// ��¼���
// ù ��° �ٿ� �������� ����ϼ���.

// ex1)
// input
// 11

// output
// 1011

void D(int x);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		D(N);
		printf("\n");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void D(int x) {
	//if (x >= 2) {
	//	D(x / 2);
	//	printf("%d", x % 2);
	//}
	//else {
	//	printf("%d", x);
	//}
	// #####################
	 if (x == 0) return;
	 else {
		 D(x/2);
		 printf("%d", x%2);
	 }
	// #####################
}