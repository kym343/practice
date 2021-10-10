#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 30. 3의 개수는?(large)

// 자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개
// 있는지 구하려고 합니다.
// 예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
// 3의 개수는 2개입니다.
// 자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는
// 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 자연수의 개수 N(3<=N<=1,000,000,000)이 주어집니다.

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
		// #######################################################
		//int cnt = 0, num = 1, tmp=0, org_N;
		//org_N = N;
		//cnt += N / 10;
		//if (N % 10 >= 3) {
		//	cnt++;
		//}
		//N /= 10;
		//while (N!=0) {
		//	if (N % 10 > 3) {// 3보다 크다
		//		tmp = 1;
		//	}
		//	else tmp = 0; // 3보다 작거나 같다

		//	cnt += (N / 10 + tmp) * 10 * num;
		//	
		//	if (N % 10 == 3) { // 3과 같다
		//		cnt += org_N % (num * 10)+1;
		//	}
		//	num *= 10;
		//	N /= 10;
		//}

		//printf("%d\n", cnt);
		// #######################################################
		// left - currunt - right
		int lt=1, cur, rt, k=1, num=3, res=0;
		
		while (lt != 0) {
			lt = N / (k*10);
			cur = (N / k) % 10;
			rt = N % k;

			if (cur > num) {
				res += (lt + 1) * k;
			}
			else if (cur < num) {
				res += lt * k;
			}
			else res += (lt * k) + (rt + 1);

			k *= 10;
		}
		printf("%d\n", res);
		// #######################################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}