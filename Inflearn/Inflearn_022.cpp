#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>

using namespace std;

// 22. 온도의 최대값

// 매일 아침 9시에 학교에서 측정한 온도가 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠
// 동안의 온도의 합이 가장 큰 값을 알아보고자 한다.
// 예를 들어, 다음과 같이 10일 간의 온도가 주어졌을 때, 3 - 2 - 4 - 9 0 3 7 13 8 - 3 모든
// 연속적인 이틀간의 온도의 합은 다음과 같다.

// 입력설명
// 첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로 주어진다. 첫 번째
// 정수 N은 온도를 측정한 전체 날짜의 수이다. N은 2 이상 100,000 이하이다.두 번째 정수 K
// 는 합을 구하기 위한 연속적인 날짜의 수이다. K는 1과 N 사이의 정수이다. 둘째 줄에는 매일
// 측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 - 100
// 이상 100 이하이다.

// 3 -2 -4 -9  0 3  7 13 8 -3
//  1 -6 -13 -9 3 10 20 21 5 

// 이때, 온도의 합이 가장 큰 값은 21이다.
// 매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰
// 값을 계산하는 프로그램을 작성하시오.

// 출력설명
// 첫째 줄에는 온도의 수열에서 연속적인 K일의 온도의 합이 최대가 되는 값을 출력한다.

// ex1)
// input
// 10 2
// 3 -2 -4 -9 0 3 7 13 8 -3

// output
// 21

int main(int argc, char** argv) {
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	
	cin >> T;
	
	for (test_case = 0; test_case < T; test_case++) {
		int N, K;
		scanf("%d %d", &N, &K);

		int max = -2147000000;
		int *a = new int[N](); // std::vector<int> a(N); // #include<vector>

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}

		int sum = 0;
		for (int i = 0; i < N-K+1; i++) {
			if(i==0){
				for (int j = 0; j < K; j++) {
					sum += a[i + j];
				}
			}
			else {
				sum = sum - a[i - 1] + a[i + K - 1];
			}
			

			if (sum > max) {
				max = sum;
			}
		}

		printf("%d\n", max);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}