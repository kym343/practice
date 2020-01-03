#include<iostream>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/2609

void calculate_GCD(int* A, int* B);

int A = 0; 
int B = 0;
int GCD = 1;

int main(int argc, char** argv) {
	//int test_case;
	//int T;

	 // input
	int result1; int result2; // output

	freopen("sample_input.txt", "r", stdin);
	cin >> A >> B;

	result1 = 0;
	result2 = 0;

	int previous_GCD;
	while (A != 1 || B != 1) {
		previous_GCD = GCD;
		calculate_GCD(&A, &B);	
		if (previous_GCD == GCD) {
			break;
		}
	}


	result1 = GCD;
	result2 = GCD * A * B;


	printf("%d\n%d", result1, result2);


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void calculate_GCD(int* A, int* B) {
	for (int i = 2; i <= min(*A, *B); i++) {
		if (*A % i == 0 && *B % i == 0) {
			GCD = GCD * i;
			*A = *A / i;
			*B = *B / i;
			break;
		}
	}
}