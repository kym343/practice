#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 6. 숫자만 추출

// 문자와 숫자가 섞여있는 문자열이 주어지면 그 중 숫자만 추출하여 그 순서대로 자연수를 만
// 듭니다.만들어진 자연수와 그 자연수의 약수 개수를 출력합니다.
// 만약 “t0e0a1c2her”에서 숫자만 추출하면 0, 0, 1, 2이고 이것을 자연수를 만들면 12가 됩니
// 다.즉 첫 자리 0은 자연수화 할 때 무시합니다.출력은 12를 출력하고, 다음 줄에 12의 약
// 수의 개수를 출력하면 됩니다.
// 추출하여 만들어지는 자연수는 100, 000, 000을 넘지 않습니다.


// 입력설명
// 첫 줄에 숫자가 썩인 문자열이 주어집니다. 문자열의 길이는 50을 넘지 않습니다.

// 출력설명
// 첫 줄에 자연수를 출력하고, 두 번째 줄에 약수의 개수를 출력합니다.

// ex1)
// input
// g0en2Ts8eSoft

// output
// 28
// 6

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char a[100];

		scanf("%s", &a);

		int total = 0;

		for (int i = 0; a[i] != '\0'; i++) {// for (int i = 0; i < strlen(a); i++) {
			if (isdigit(a[i])) {
				total = total * 10 + a[i] - '0';
			}
		}
		
		printf("%d\n", total);

		int factor = 0;
		for (int i = 1; i <= total; i++) {
			if (total % i == 0) {
				factor++;
			}
		}

		printf("%d\n", factor);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}