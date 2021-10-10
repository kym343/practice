#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 30. 3�� ������?(large)

// �ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���� �� 3�� ������ �� ��
// �ִ��� ���Ϸ��� �մϴ�.
// ���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5����
// 3�� ������ 2���Դϴ�.
// �ڿ��� N�� �ԷµǸ� 1���� N���� ���ڸ� ���� ��, 3�� ������ �� ������ ���Ͽ� ����ϴ�
// ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �ڿ����� ���� N(3<=N<=1,000,000,000)�� �־����ϴ�.

// ��¼���
// 3�� ������ ����ϼ���.

// ex1)
// input
// 15

// output
// 2

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);
		// #######################################################
		//int cnt = 0, num = 1, tmp=0, org_N;
		//org_N = N;
		//cnt += N / 10;
		//if (N % 10 >= 3) {
		//	cnt++;
		//}
		//N /= 10;
		//while (N!=0) {
		//	if (N % 10 > 3) {// 3���� ũ��
		//		tmp = 1;
		//	}
		//	else tmp = 0; // 3���� �۰ų� ����

		//	cnt += (N / 10 + tmp) * 10 * num;
		//	
		//	if (N % 10 == 3) { // 3�� ����
		//		cnt += org_N % (num * 10)+1;
		//	}
		//	num *= 10;
		//	N /= 10;
		//}

		//printf("%d\n", cnt);
		// #######################################################
		// left - currunt - right
		int lt=1, cur, rt, k=1, num=3, res=0;
		
		while (lt != 0) {
			lt = N / (k*10);
			cur = (N / k) % 10;
			rt = N % k;

			if (cur > num) {
				res += (lt + 1) * k;
			}
			else if (cur < num) {
				res += lt * k;
			}
			else res += (lt * k) + (rt + 1);

			k *= 10;
		}
		printf("%d\n", res);
		// #######################################################
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}