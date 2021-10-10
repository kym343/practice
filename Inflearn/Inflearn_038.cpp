#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 38. Inversion Sequence

// 1���� n������ ���� �� ������ ����Ͽ� �̷���� ������ ���� ��, 1���� n���� ������ ��
// �տ� ���� �ִ� �ڽź��� ū ������ ������ ������ ǥ���� ���� Inversion Sequence�� �Ѵ�.
// ���� ��� ������ ���� ������ ���
// 4 8 6 2 5 1 3 7
//
// 1�տ� ���� 1���� ū ���� 4, 8, 6, 2, 5. �̷��� 5���̰�,
// 2�տ� ���� 2���� ū ���� 4, 8, 6. �̷��� 3��,
// 3�տ� ���� 3���� ū ���� 4, 8, 6, 5 �̷��� 4��......
//
// ���� 4 8 6 2 5 1 3 7�� inversion sequence�� 5 3 4 0 2 1 1 0 �� �ȴ�.
// n�� 1���� n������ ���� ����Ͽ� �̷���� ������ inversion sequence�� �־����� ��, ����
// �� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(3<=N<100)�� �־�����, �� ��° �ٿ��� inversion sequence�� ����
// ���̿� �� ĭ�� ������ �ΰ� �־�����.

// ��¼���
// ������������ ���ĵ� ������ ����մϴ�.

// ex1)
// input
// 8
// 5 3 4 0 2 1 1 0

// output
// 4 8 6 2 5 1 3 7

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);
		// ####################################################
		// ���� �ѹ��� �־���
		
		//int i, j, k, cnt=0, num;
		//int* a = new int[N]();
		//for (i = 0;i < N;i++) {
		//	a[i] = N;
		//}

		//for (i = 1;i < N;i++) {
		//	scanf("%d", &num); 

		//	if(num!=0){
		//		for (j = 0;j < N;j++) {
		//			if (a[j] > i) {
		//				num--;
		//			}
		//			if (num == 0) {
		//				for (k = j + 1;k < N;k++) {
		//					if (a[k] == N) {
		//						a[k] = i;
		//						break;
		//					}
		//				}
		//				break;
		//			}
		//		}
		//	}
		//	else {
		//		for (k = 0;k < N;k++) {
		//			if (a[k] == N) {
		//				a[k] = i;
		//				break;
		//			}
		//		}
		//	}
		//}
		//for (i = 0;i < N;i++) {
		//	printf("%d ", a[i]);
		//}
		// ####################################################
		// ū ���ں��� ó���� ��
		int i, j, pos;
		int* a = new int[N+1]();
		int* b = new int[N+1]();

		for (i = 1;i < N+1;i++) {
			scanf("%d", &a[i]);
		}

		for (i = N; i >= 1;i--) {
			pos = i;
			for (j = 1;j <= a[i];j++) {
				b[pos] = b[pos+1];
				pos++;
			}
			b[pos] = i;
		}

		for (i = 1;i < N+1;i++) {
			printf("%d ", b[i]);
		}
		// ####################################################
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}