#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 57. 재귀함수 이진수 출력

// 10진수 N이 입력되면 2진수로 변환하여 출력하는 프로그램을 작성하세요. 단 재귀함수를 이용
// 해서 출력해야 합니다.

// 입력설명
// 첫 번째 줄에 10진수 N(1<=N<=1,000)이 주어집니다.

// 출력설명
// 첫 번째 줄에 이진수를 출력하세요.

// ex1)
// input
// 11

// output
// 1011

void D(int x);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		D(N);
		printf("\n");
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void D(int x) {
	//if (x >= 2) {
	//	D(x / 2);
	//	printf("%d", x % 2);
	//}
	//else {
	//	printf("%d", x);
	//}
	// #####################
	 if (x == 0) return;
	 else {
		 D(x/2);
		 printf("%d", x%2);
	 }
	// #####################
}