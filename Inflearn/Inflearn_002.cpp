#include<iostream>
#include <algorithm>

using namespace std;

//2. 자연수의 합

// 자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요.

// 입력설명
// 첫 줄에 자연수 A, B가 공백을 사이에 두고 차례대로 입력된다. (1 <= A<B <= 100)

// 출력설명
// 첫 줄에 더하는 수식과 함께 합을 출력합니다.

// ex1)
// input
// 3 7

// output
// 3 + 4 + 5 + 6 + 7 = 25

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	
	int A;
	int B;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> A >> B;

		int sum = 0;
		
		for (int i = A; i < B; i++) {
			sum += i;

			printf("%d + ", i);
		}

		sum += B;
		printf("%d = %d\n", B, sum);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}