#include <iostream>
#include <algorithm>

using namespace std;

// 9. 모두의 약수

// 자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램을 작성하
// 세요.만약 N이 8이 입력된다면 1(1개), 2(2개), 3(2개), 4(3개), 5(2개), 6(4개), 7(2개), 8(4	개) 와 같이 각 숫자의 약수의 개수가 구해집니다.
// 출력은 다음과 같이 1부터 차례대로 약수의 개수만 출력하면 됩니다.
// 1 2 2 3 2 4 2 4 와 같이 출력한다.

// 입력설명
// 첫 번째 줄에 자연수 N(5<=N<=50,000)가 주어진다.

// 출력설명
// 첫 번째 줄에 1부터 N까지 약수의 개수를 순서대로 출력한다.

// ex1)
// input
// 8

// output
// 1 2 2 3 2 4 2 4

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N + 1];
		fill_n(a, N+1, 1);

		for (int i=2; i <= N; i++) {
			for (int j = i; j <= N; j += i) {
				a[j]++;
			}
		}

		for (int i = 1; i <N; i++) {
			printf("%d ", a[i]);
		}
		printf("%d\n", a[N]);

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}