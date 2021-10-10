#include<iostream>
#include <algorithm>

using namespace std;

// 3. 진약수의 합

// 자연수 N이 주어지면 자연수 N의 진약수의 합을 수식과 함께 출력하는 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 자연수 N이 주어집니다. (3<N <= 100)

// 출력설명
// 첫 줄에 더하는 수식과 함께 합을 출력합니다.

// ex1)
// input
// 20

// output
// 1 + 2 + 4 + 5 + 10 = 22

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	int N;
	
	for (test_case = 0; test_case < T; test_case++) {
		cin >> N;

		int sum = 1;
		int another = N;

		printf("%d", 1);

		for (int i = 2; i < N; i++) {
			if (i > another) {
				break;
			}

			if (N % i == 0) {
				printf(" + %d", i);
				sum += i;

				if (another == N) {
					another = N / i;
				}
			}
		}
		printf(" = %d\n", sum);

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}