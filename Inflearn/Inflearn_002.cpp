#include<iostream>
#include <algorithm>

using namespace std;

//2. �ڿ����� ��

// �ڿ��� A, B�� �־����� A���� B������ ���� ���İ� �Բ� ����ϼ���.

// �Է¼���
// ù �ٿ� �ڿ��� A, B�� ������ ���̿� �ΰ� ���ʴ�� �Էµȴ�. (1 <= A<B <= 100)

// ��¼���
// ù �ٿ� ���ϴ� ���İ� �Բ� ���� ����մϴ�.

// ex1)
// input
// 3 7

// output
// 3 + 4 + 5 + 6 + 7 = 25

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	
	int A;
	int B;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> A >> B;

		int sum = 0;
		
		for (int i = A; i < B; i++) {
			sum += i;

			printf("%d + ", i);
		}

		sum += B;
		printf("%d = %d\n", B, sum);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}