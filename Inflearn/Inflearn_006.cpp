#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 6. ���ڸ� ����

// ���ڿ� ���ڰ� �����ִ� ���ڿ��� �־����� �� �� ���ڸ� �����Ͽ� �� ������� �ڿ����� ��
// ��ϴ�.������� �ڿ����� �� �ڿ����� ��� ������ ����մϴ�.
// ���� ��t0e0a1c2her������ ���ڸ� �����ϸ� 0, 0, 1, 2�̰� �̰��� �ڿ����� ����� 12�� �˴�
// ��.�� ù �ڸ� 0�� �ڿ���ȭ �� �� �����մϴ�.����� 12�� ����ϰ�, ���� �ٿ� 12�� ��
// ���� ������ ����ϸ� �˴ϴ�.
// �����Ͽ� ��������� �ڿ����� 100, 000, 000�� ���� �ʽ��ϴ�.


// �Է¼���
// ù �ٿ� ���ڰ� ���� ���ڿ��� �־����ϴ�. ���ڿ��� ���̴� 50�� ���� �ʽ��ϴ�.

// ��¼���
// ù �ٿ� �ڿ����� ����ϰ�, �� ��° �ٿ� ����� ������ ����մϴ�.

// ex1)
// input
// g0en2Ts8eSoft

// output
// 28
// 6

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char a[100];

		scanf("%s", &a);

		int total = 0;

		for (int i = 0; a[i] != '\0'; i++) {// for (int i = 0; i < strlen(a); i++) {
			if (isdigit(a[i])) {
				total = total * 10 + a[i] - '0';
			}
		}
		
		printf("%d\n", total);

		int factor = 0;
		for (int i = 1; i <= total; i++) {
			if (total % i == 0) {
				factor++;
			}
		}

		printf("%d\n", factor);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}