#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 36. �������� 

// N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
// �����ϴ� ����� ���������Դϴ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
// �� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�.�� �ڿ����� ������ ���� �ȿ�
// �ֽ��ϴ�.

// ��¼���
// ������������ ���ĵ� ������ ����մϴ�.

// ex1)
// input
// 6
// 11 7 5 6 10 9

// output
// 5 6 7 9 10 11

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	 
	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		// ##################################################
		// ���� ������ ���� �����鼭 �ٷιٷ� �������ְ� 
		// �־��ִ��� �˾Ҵµ� �ƴϳ�..
		//int i, j, num, idx;
		//int* a = new int[N]();

		//scanf("%d", &a[0]);
		//for (i = 1;i < N;i++) {// ����
		//	scanf("%d", &num);
		//	idx = 0;

		//	for (j = 0;j < i;j++) {
		//		if (num > a[j]) {
		//			idx++;
		//		}
		//		else {
		//			for (int k = i;k > idx;k--) {
		//				a[k] = a[k-1];
		//			}
		//			break;
		//		}
		//	}
		//	a[idx] = num;
		//}
		//for (i = 0;i < N;i++){
		//	printf("%d ", a[i]);
		//}
		// ##################################################
		int* a = new int[N]();
		int i, j, tmp;
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}

		for (i = 1;i < N;i++) {
			tmp = a[i];
			for (j = i - 1;j >= 0;j--) {
				if (a[j] > tmp) {
					a[j + 1] = a[j];
				}
				else break;
			}
			a[j + 1] = tmp;
		}
		for (i = 0;i < N;i++) {
			printf("%d ", a[i]);
		}
		// ##################################################
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}