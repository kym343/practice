#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 76. 이항계수(메모이제이션)

// 이항계수는 N개의 원소를 가지는 집합에서 R개의 원소를 뽑아 부분집합을 만드는 경우의 수
// 를 의미한다. 공식은 nCr 로 표현된다.
// N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=20)과 R(0<=R<=20)이 주어진다. 단 (N>=R)

// 출력설명
// 첫 번째 줄에 이항계수 값을 출력한다.

// ex1)
// input
// 5 3

// output
// 10

int dy[21][21];

// nCr = (n-1 C r-1) + (n-1 C r)
int DFS(int n, int r) {
	if (dy[n][r] > 0) return dy[n][r];						  // 메모이제이션
	if (n == r || r == 0) return 1;
	else return dy[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r); // 메모이제이션 "dy[n][r]= "
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, R;

		scanf("%d %d", &N, &R);// 5C3 = 4C2 + 4C3 (5의 입장에서 5 뽑은 경우 + 안 뽑은 경우)

		printf("%d\n", DFS(N, R));

		// =================================================
		//int N, R, a=1, b=1, small, i;

		//scanf("%d %d", &N, &R); // 5C3 = 5! / (3!)(2!) = 10
		//						  // a = 5!, b = 3! * 2!

		//if (N - R >= R) small = R;
		//else small = N - R;

		//for (i = 1;i <= small;i++) {
		//	a *= (N - i + 1);
		//	b *= i;
		//}

		//printf("%d\n", a / b);
		// =================================================
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}