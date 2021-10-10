#include<iostream>
#include <algorithm>

using namespace std;

// 1. 1부터 N까지 M의 배수합

// 자연수 N이 입력되면 1부터 N까지의 수 중 M의 배수합을 출력하는 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 자연수 N과 M이 차례대로 입력됩니다.(3 <= M<N <= 1000)

// 출력설명
// 첫 줄에 M의 배수합을 출력한다.

// ex1)
// input
// 15 3

// output
// 45

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	int N;
	int M;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;

		int sum = 0;

		for (int i = M; i <= N; i = i + M) {
			sum += i;
		}

		printf("%d\n", sum);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}