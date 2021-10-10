#include<iostream>
#include <algorithm>

using namespace std;

// 4. 나이 차이

// N(2 <= N <= 100)명의 나이가 입력됩니다.이 N명의 사람 중 가장 나이차이가 많이 나는 경우는
// 몇 살일까요 ? 최대 나이 차이를 출력하는 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 자연수 N(2 <= N <= 100)이 입력되고, 그 다음 줄에 N개의 나이가 입력된다.

// 출력설명
// 첫 줄에 최대 나이차이를 출력합니다.

// ex1)
// input
// 10
// 13 15 34 23 45 65 33 11 26 42


// output
// 54

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		cin >> N;

		int num;
		cin >> num;

		int max = num; // -2147000000
		int min = num; // 2147000000

		for (int i = 1; i < N; i++) {
			cin >> num;

			if(num > max){
				max = num;
			}
			else if (num < min) {
				min = num;
			}
		}

		printf("%d\n", max - min);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}