#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 52. Ugly Numbers

// 어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly
// Number라고 부릅니다.Ugly Number를 차례대로 적어보면
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다.숫자 1은 Ugly Number의 첫 번째 수로 합
// 니다.자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는
// 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 자연수 N(3<=N<=1500)이 주어집니다.

// 출력설명
// 첫 줄에 N번째 Ugly Number를 출력하세요.

// ex1)
// input
// 10

// output
// 12

// ex2)
// input
// 1500

// output
// 859963392

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// =======================================================================
		int N, i, p2, p3, p5, minn=2147000000;
		int a[1501];

		scanf("%d", &N);

		a[1] = 1;
		p2 = p3 = p5 = 1;
		for (i = 2;i <= N;i++) {
			if (a[p2] * 2 < a[p3] * 3) minn = a[p2] * 2;
			else minn = a[p3] * 3;
			if (a[p5] * 5 < minn) minn = a[p5] * 5;
			
			if (a[p2] * 2 == minn) p2++;
			if (a[p3] * 3 == minn) p3++;
			if (a[p5] * 5 == minn) p5++;
			a[i] = minn;
		}
		printf("%d\n", a[N]);
		// =======================================================================
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}