#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 56. ����Լ� �м�

// �ڿ��� N�� �־����� �Ʒ��� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. ����Լ��� �̿��ؼ� ��
// ���ؾ� �մϴ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=20)�� �־����ϴ�.

// ��¼���
// ù ��° �ٿ� ����Լ��� �̿��ؼ� ����ϼ���.

// ex1)
// input
// 3

// output
// 1 2 3

void recursive(int num);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		recursive(N);
		printf("\n");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void recursive(int num) {
	if (num > 0) {
		recursive(num - 1);
		printf("%d ", num);
	}
	// #####################
	// if (num == 0) return;
	// else {
	//	 recursive(num - 1);
	//	 printf("%d ", num);
	// }
	// #####################
}