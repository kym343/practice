#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 31. źȭ���� ����

// ź��(C)�� ����(H)�θ� �̷���� ȭ�չ��� źȭ���Ҷ�� �մϴ�.
// ź��(C) �� ���� ������ 12g, ����(H) �� ���� ������ 1g�Դϴ�.
// ��ƿ��(C2H4)�� ������ 12 * 2 + 1 * 4 = 28g�Դϴ�.
// ��ź(CH4)�� ������ 12 * 1 + 1 * 4 = 16g�Դϴ�.
// źȭ���ҽ��� �־����� �ش� ȭ�չ��� ������ ���ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� źȭ���ҽ��� �־����ϴ�. ���� ���´� CaHb �����̸� (1<=a, b<=100)�̴�.
// �� a �� b �� 1�̸� ���ڰ� �Ŀ� �Էµ��� �ʴ´�.��) CH4

// ��¼���
// ù �ٿ� źȭ������ ������ ����մϴ�.

// ex1)
// input
// C2H4

// output
// 28

// ex2)
// input
// CH4

// output
// 16

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// ##################################################
		//char N[10];
		//int cnt_c=0, cnt_h = 0, res = 0;

		//scanf("%s", &N); // C2H4
		//
		//char* C; char* H;
		//C = strtok(N, "H");
		////printf("%s %s\n", N, C); // C2 C2 

		//H = strtok(NULL, "H");
		////printf("%s %s %s\n", N, C, H); // C2 C2 4

		//C = strtok(C, "C");
		////printf("%s %s %s\n", N, C, H); // C2 2 4
		//if (C == NULL) {
		//	cnt_c = 1;
		//}
		//else cnt_c = atoi(C);

		//if (H == NULL) {
		//	cnt_h = 1;
		//}
		//else cnt_h = atoi(H);

		//res = cnt_c * 12 + cnt_h * 1;
		//printf("%d\n", res);
		// ##################################################
		char a[10];
		int c = 0, h = 0, i, pos;
		scanf("%s", &a);
		if (a[1] == 'H') {
			c = 1;
			pos = 1;
		}
		else {
			for (i = 1;a[i] != 'H';i++) {
				c = c * 10 + (a[i] - 48);
			}
			pos = i;
		}

		if (a[pos + 1] == '\0') h = 1;
		else {
			for (i = pos + 1;a[i] != '\0';i++) {
				h = h * 10 + (a[i] - 48);
			}
		}
		printf("%d\n", c * 12 + h);
		// ##################################################
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}