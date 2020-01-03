#include<iostream>
#include <algorithm>

using namespace std;

//https://www.acmicpc.net/problem/1934

int A = 0;
int B = 0;
int GCD = 1;

void calculate_GCD(int* A, int* B);

int main(int argc, char** argv) {
	int test_case;
	int T;
	int result = 1;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		GCD = 1;

		cin >> A >> B;

		int previous_GCD = 0;
		while (A != 1 || B != 1) {
			previous_GCD = GCD;
			calculate_GCD(&A, &B);
			if (previous_GCD == GCD) {
				break;
			}		
		}
		
		result = GCD * A * B;


		printf("%d\n", result);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void calculate_GCD(int* A, int* B) {
	for (int i = 2; i <= min(*A, *B); i++) {
		if (*A % i == 0 && *B % i == 0) {
			*A = *A / i;
			*B = *B / i;
			GCD = GCD * i;
			break;
		}	
	}
}

