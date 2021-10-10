#include <iostream>
#include <algorithm>

using namespace std;

// 10. 자릿수의 합

// N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력
// 하는 프로그램을 작성하세요. 각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를
// 꼭 작성해서 프로그래밍 하세요.

// 입력설명
// N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력
// 하는 프로그램을 작성하세요.각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를
// 꼭 작성해서 프로그래밍 하세요.

// 출력설명
// 자릿수의 합이 최대인 자연수를 출력한다. 자리수의 합이 최대인 자연수가 여러개인 경우 그
// 중 값이 가장 큰 값을 출력합니다.

// ex1)
// input
// 5
// 125 15232 79 1325 97

// output
// 97
int digit_sum(int x);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N];
		int* b = new int[N] {0};
		
		int max = -1;
		int sol = -1;

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);

			b[i] = digit_sum(a[i]);
			
			if (max < b[i]) {
				sol = a[i];
				max = b[i];
			}
			else if (max == b[i]) {
				if (sol < a[i]) {
					sol = a[i];
				}
			}
		}

		printf("%d\n", sol);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int digit_sum(int x) {

	int sum = 0;
	int c = x;

	while (c > 0) {
		sum += c % 10;
		c /= 10;//(c - (c % 10)) / 10;
	}
	
	return sum;
}