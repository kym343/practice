#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 56. 재귀함수 분석

// 자연수 N이 주어지면 아래와 같이 출력하는 프로그램을 작성하세요. 재귀함수를 이용해서 출
// 력해야 합니다.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.

// 출력설명
// 첫 번째 줄에 재귀함수를 이용해서 출력하세요.

// ex1)
// input
// 3

// output
// 1 2 3

void recursive(int num);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		recursive(N);
		printf("\n");
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void recursive(int num) {
	if (num > 0) {
		recursive(num - 1);
		printf("%d ", num);
	}
	// #####################
	// if (num == 0) return;
	// else {
	//	 recursive(num - 1);
	//	 printf("%d ", num);
	// }
	// #####################
}