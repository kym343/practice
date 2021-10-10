#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 31. 탄화수소 질량

// 탄소(C)와 수소(H)로만 이루어진 화합물을 탄화수소라고 합니다.
// 탄소(C) 한 개의 질량은 12g, 수소(H) 한 개의 질량은 1g입니다.
// 에틸렌(C2H4)의 질량은 12 * 2 + 1 * 4 = 28g입니다.
// 메탄(CH4)의 질량은 12 * 1 + 1 * 4 = 16g입니다.
// 탄화수소식이 주어지면 해당 화합물의 질량을 구하는 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 탄화수소식이 주어집니다. 식의 형태는 CaHb 형태이며 (1<=a, b<=100)이다.
// 단 a 나 b 가 1이면 숫자가 식에 입력되지 않는다.예) CH4

// 출력설명
// 첫 줄에 탄화수소의 질량을 출력합니다.

// ex1)
// input
// C2H4

// output
// 28

// ex2)
// input
// CH4

// output
// 16

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// ##################################################
		//char N[10];
		//int cnt_c=0, cnt_h = 0, res = 0;

		//scanf("%s", &N); // C2H4
		//
		//char* C; char* H;
		//C = strtok(N, "H");
		////printf("%s %s\n", N, C); // C2 C2 

		//H = strtok(NULL, "H");
		////printf("%s %s %s\n", N, C, H); // C2 C2 4

		//C = strtok(C, "C");
		////printf("%s %s %s\n", N, C, H); // C2 2 4
		//if (C == NULL) {
		//	cnt_c = 1;
		//}
		//else cnt_c = atoi(C);

		//if (H == NULL) {
		//	cnt_h = 1;
		//}
		//else cnt_h = atoi(H);

		//res = cnt_c * 12 + cnt_h * 1;
		//printf("%d\n", res);
		// ##################################################
		char a[10];
		int c = 0, h = 0, i, pos;
		scanf("%s", &a);
		if (a[1] == 'H') {
			c = 1;
			pos = 1;
		}
		else {
			for (i = 1;a[i] != 'H';i++) {
				c = c * 10 + (a[i] - 48);
			}
			pos = i;
		}

		if (a[pos + 1] == '\0') h = 1;
		else {
			for (i = pos + 1;a[i] != '\0';i++) {
				h = h * 10 + (a[i] - 48);
			}
		}
		printf("%d\n", c * 12 + h);
		// ##################################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}