#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 28. N!에서 0의 개수

// 자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 ‘0’이 몇 개 있는지 구하는 프로그
// 램을 작성하세요.
// 만약 5!= 5 × 4 × 3 × 2 × 1 = 120으로 일의자리부터 연속적된 ‘0’의 개수는 1입니다.
// 만약 12!= 479001600으로 일의자리부터 연속적된 ‘0’의 개수는 2입니다.

// 입력설명
// 첫 줄에 자연수 N(10<=N<=1,000)이 입력된다.

// 출력설명
// 일의 자리부터 연속된 0의 개수를 출력합니다.

// ex1)
// input
// 12

// output
// 5

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);
		
		int cnt = 0, num = 5;

		while (num<=N) {
			cnt += N / num;
			num *= 5;
		}

		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}