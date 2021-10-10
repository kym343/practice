#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 27. N!의 표현법

// 임의의 N에 대하여 N!은 1부터 N까지의 곱을 의미한다. 이는 N이 커짐에 따라 급격하게 커진
// 다.이러한 큰 수를 표현하는 방법으로 소수들의 곱으로 표현하는 방법이 있다.먼저 소수는
// 2, 3, 5, 7, 11, 13...순으로 증가함을 알아야 한다.예를 들면 825는(0 1 2 0 1)로 표현이
// 가능한데, 이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다. 101보
// 다 작은 임의의 N에 대하여 N 팩토리얼을 이와 같은 표기법으로 변환하는 프로그램을 작성해
// 보자.출력은 아래 예제와 같이 하도록 한다.

// 입력설명
// 첫 줄에 자연수 N(3<=N<=1000)이 입력된다.

// 출력설명
// 소수의 곱으로 표현한다.

// ex1)
// input
// 5

// output
// 5! = 3 1 1

// ex2)
// input
// 53

// output2
// 53! = 49 23 12 8 4 4 3 2 2 1 1 1 1 1 1 1

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N+1]();
		// ##############################################################
		for (int i = 2;i < N+1;i++) { // 아리스토텔레스의 체
			if (a[i] == 0) {
				a[i] = 1;
				for (int j = 2*i;j < N + 1;j = j + i) {
					a[j] = -1;
				}
			}
		}

		for (int i = 2;i < N + 1;i++) {
			if (a[i] < 0 ) {// 소수가 아니면
				int num = i;
				while(num != 1){
					for (int j = 2; j < num+1;j++) {
						if (num % j == 0) {
							num /= j;
							a[j]++;
							break;
						}
					}
				}
			}
		}

		printf("%d! = ", N);
		for (int i = 2; i < N + 1; i++) {
			if (a[i] > 0) {
				printf("%d ", a[i]);
			}
		}
		printf("\n");
		// ##############################################################
		//int j, tmp;
		//for (int i = 2; i <= N; i++) {
		//	tmp = i;
		//	j = 2;
		//	while (1) {
		//		if (tmp % j == 0) {
		//			tmp /= j;
		//			a[j]++;
		//		}
		//		else j++;
		//		if (tmp == 1) break;
		//	}		
		//}
		//printf("%d! = ", N);
		//for (int i = 2; i <= N; i++) {
		//	if (a[i] != 0) printf("%d ", a[i]);
		//}
		// ##############################################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
