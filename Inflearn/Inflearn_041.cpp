#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void print_result(int a, int b, int total);

// 41. ���ӵ� �ڿ����� ��

// �Է����� ���� ���� N�� �ԷµǸ� 2�� �̻��� ���ӵ� �ڿ����� ������ ���� N�� ǥ���ϴ� ��
// �Թ��� �������� ����ϴ� ���α׷��� �ۼ��ϼ���.
// ���� N = 15�̸�
// 7 + 8 = 15
// 4 + 5 + 6 = 15
// 1 + 2 + 3 + 4 + 5 = 15
// �� ���� �� 3������ ��찡 �����Ѵ�.

// �Է¼���
// ù ��° �ٿ� ���� ���� N(7<=N<1000)�� �־�����.

// ��¼���
// ù�ٺ��� ������ ����� ���� ����Ѵ�.
// �� ������ �ٿ� �� ������ ����Ѵ�.

// ex1)
// input
// 15

// output
// 7 + 8 = 15
// 4 + 5 + 6 = 15
// 1 + 2 + 3 + 4 + 5 = 15
// 3

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// =======================================
		//	int N, i, num, cnt=0, sum;
		//	scanf("%d", &N);
		//	
		//	for(i=N/2+1;i>=1;i--){
		//		sum=0;
		//		num=i;
		//		while(sum<N){
		//			sum += num;
		//			
		//			if(sum==N){
		//				print_result(num,i,N);
		//				cnt++;
		//				break;
		//			}
		//			num--;
		//		}
		//	}
		// =======================================
		int a, b = 1, cnt = 0, tmp, i;
		scanf("%d", &a);
		tmp = a;
		a--;
		while (a > 0) {
			b++;
			a -= b;
			if (a % b == 0) {
				print_result(a / b + 1, a / b + b, tmp);
				cnt++;
			}
		}
		// =======================================
		printf("%d\n", cnt);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void print_result(int a, int b, int total) {
	int i;
	for (i = a;i < b;i++) {
		printf("%d + ", i);
	}
	printf("%d = %d\n", b, total);
}