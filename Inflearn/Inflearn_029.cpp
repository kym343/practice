#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 29. 3의 개수는?(small)

// 자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개
// 있는지 구하려고 합니다.
// 예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
// 3의 개수는 2개입니다.
// 자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는
// 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 자연수의 개수 N(3<=N<=100,000)이 주어집니다.

// 출력설명
// 3의 개수를 출력하세요.

// ex1)
// input
// 15

// output
// 2

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int num, cnt = 0;
		for (int i = 3;i < N;i++) {
			num = i;
			while (num > 0) {
				if (num % 10 == 3) {
					cnt++;
				}
				num /= 10;
			}
		}
		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}