#include <iostream>
#include <algorithm>

using namespace std;

// 1. 14. ������ �Ҽ�

// N���� �ڿ����� �ԷµǸ� �� �ڿ����� ������ �� �� ������ ���� �Ҽ��̸� �� ���� ����ϴ�
// ���α׷��� �ۼ��ϼ���.���� ��� 32�� �������� 23�̰�, 23�� �Ҽ��̴�.�׷��� 23�� ���
// �Ѵ�.�� 910�� �������� 19�� ����ȭ �ؾ� �Ѵ�.ù �ڸ������� ���ӵ� 0�� �����Ѵ�.
// ������ �Լ��� int reverse(int x) �� �Ҽ������� Ȯ���ϴ� �Լ� bool isPrime(int x)�� �ݵ��
// �ۼ��Ͽ� ���α׷��� �Ѵ�.

// �Է¼���
// ù �ٿ� �ڿ����� ���� N(3<=N<=100)�� �־�����, �� ���� �ٿ� N���� �ڿ����� �־�����.
// �� �ڿ����� ũ��� 100, 000�� ���� �ʴ´�.

// ��¼���
// ù �ٿ� ������ �Ҽ��� ����մϴ�. ��¼����� �Էµ� ������� ����մϴ�.

// ex1)
// input
// 5
// 32 55 62 3700 250

// output
// 23 73

int reverse(int x);
bool isPrime(int x);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int a[101] = { 0 };
		int b[101] = { 0 };

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);

			int re_num = reverse(a[i]);

			if (isPrime(re_num)) {
				b[cnt] = re_num;
				cnt++;
			}
		}

		for (int j = 0; j < cnt-1; j++) {
			printf("%d ", b[j]);
		}
		printf("%d\n", b[cnt-1]);

	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

int reverse(int x) {
	char num[7];
	int cnt = 0;

	int temp = x;
	int last;

	while (temp != 0) {
		last = temp % 10;

		if (cnt == 0 && last == 0) {
			temp /= 10;
			continue;
		}
		num[cnt] = last + '0';
		//printf("%d\n", num[cnt]);
		cnt++;
		temp /= 10;
	}
	num[cnt] = '\0';

	return atoi(num);
}

//int revers(int x) { // �� ����
//	int res = 0;
//	int tmp;
//	while (x > 0) {
//		tmp = x % 10;
//		res = res * 10 + tmp;
//		x = x / 10;
//	}
//	return res;
//}

bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	else{
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}