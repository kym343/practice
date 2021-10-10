#include <iostream>
#include <algorithm>

using namespace std;

// 1. 14. 뒤집은 소수

// N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는
// 프로그램을 작성하세요.예를 들어 32를 뒤집으면 23이고, 23은 소수이다.그러면 23을 출력
// 한다.단 910를 뒤집으면 19로 숫자화 해야 한다.첫 자리부터의 연속된 0은 무시한다.
// 뒤집는 함수인 int reverse(int x) 와 소수인지를 확인하는 함수 bool isPrime(int x)를 반드시
// 작성하여 프로그래밍 한다.

// 입력설명
// 첫 줄에 자연수의 개수 N(3<=N<=100)이 주어지고, 그 다음 줄에 N개의 자연수가 주어진다.
// 각 자연수의 크기는 100, 000를 넘지 않는다.

// 출력설명
// 첫 줄에 뒤집은 소수를 출력합니다. 출력순서는 입력된 순서대로 출력합니다.

// ex1)
// input
// 5
// 32 55 62 3700 250

// output
// 23 73

int reverse(int x);
bool isPrime(int x);

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int a[101] = { 0 };
		int b[101] = { 0 };

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);

			int re_num = reverse(a[i]);

			if (isPrime(re_num)) {
				b[cnt] = re_num;
				cnt++;
			}
		}

		for (int j = 0; j < cnt-1; j++) {
			printf("%d ", b[j]);
		}
		printf("%d\n", b[cnt-1]);

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int reverse(int x) {
	char num[7];
	int cnt = 0;

	int temp = x;
	int last;

	while (temp != 0) {
		last = temp % 10;

		if (cnt == 0 && last == 0) {
			temp /= 10;
			continue;
		}
		num[cnt] = last + '0';
		//printf("%d\n", num[cnt]);
		cnt++;
		temp /= 10;
	}
	num[cnt] = '\0';

	return atoi(num);
}

//int revers(int x) { // 더 간단
//	int res = 0;
//	int tmp;
//	while (x > 0) {
//		tmp = x % 10;
//		res = res * 10 + tmp;
//		x = x / 10;
//	}
//	return res;
//}

bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	else{
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}