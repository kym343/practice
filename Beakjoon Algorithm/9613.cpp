#include<iostream>
#include <algorithm>

using namespace std;

//https://www.acmicpc.net/problem/9613

int temp_GCD = 1;
long total_GCD = 0;

void calculate_GCD(int* intput1, int* intput2);
int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int P;

		scanf("%d", &P);

		int *arr = new int[P]();

		for (int i = 0; i < P; i++) {
			scanf("%d", &arr[i]);
		}

		total_GCD = 0;
		for (int i = 0; i < P-1;i++) {
			for (int j = i+1; j < P; j++) {
				calculate_GCD(&arr[i], &arr[j]);
				total_GCD = total_GCD + temp_GCD;
			}
		}
		printf("%ld\n", total_GCD);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void calculate_GCD(int* intput1, int* intput2) {
	int A = *intput1;
	int B = *intput2;
	temp_GCD = 1;
	while (A != 1 || B != 1) {
		int previous_GCD = temp_GCD;
		for (int i = 2; i <= min(A, B); i++) {
			if (A % i == 0 && B % i == 0) {
				A = A / i;
				B = B / i;
				temp_GCD = temp_GCD * i;
				break;
			}
		}

		if (previous_GCD == temp_GCD) {
			break;
		}
	}
}