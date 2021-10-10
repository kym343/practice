#include <iostream>
#include <algorithm>

using namespace std;

// 12. ������ �� ����(large)

// �ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���ڴ� �� �� ���������?
// ���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5����
// �� 21���� �������� �� �� �ֽ��ϴ�.
// �ڿ��� N�� �ԷµǸ� 1���� N���� �� ���ڴ� �� ���� ���Ǿ������� ���ϴ� ���α׷��� ��
// ���ϼ���.

// �Է¼���
// ù ��° �ٿ��� �ڿ��� N(3<=N<=100,000,000)�� �־�����.

// ��¼���
// ù ��° �ٿ� ������ �Ѱ����� ����Ѵ�.

// ex1)
// input
// 15

// output
// 21

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int temp = N;
		int a[10] = { 0 };// 10�� i ������ ���� �ڸ��� ����
						 // a[0] : 1 ~ 9 -> �ִ� 9
						 // a[1] : 10~99 -> �ִ� 90
		int b = -1;
		int c = 1;
		int cnt = 0;
									// res=0; c= 1; d=9;
		while (temp > 0) {			// while(sum+d < N){
			b++;					//	 res = res+(c*d);
									//	 sum = sum + d;
			if (temp >= 10) {		//	 c++;
				a[b] = 9 * c;		//	 d *= 10;
				c *= 10;			// }
			}						// res=res+((n-sum)*c)
			else {
				a[b] = N - c + 1;
			}
			temp /= 10;
		}

		int sum = 0;
		int i = 0;

		while (a[i] != 0) {
			sum += (i + 1)*a[i];
			i++;
		}
		printf("%d\n", sum);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}