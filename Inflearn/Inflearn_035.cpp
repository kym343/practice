#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 35. Special Sort(구글 인터뷰)

// N개의 정수가 입력되면 당신은 입력된 값을 정렬해야 한다.
// 음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다.또한 양의정수와 음의정수의 순서에는
// 변함이 없어야 한다.

// 입력설명
// 첫 번째 줄에 정수 N(5<=N<=100)이 주어지고, 그 다음 줄부터 음수를 포함한 정수가 주어진
// 다.숫자 0은 입력되지 않는다.

// 출력설명
// 정렬된 결과를 출력한다.

// ex1)
// input
// 8
// 1 2 3 -3 -2 5 6 -6

// output
// -3 -2 -6 1 2 3 5 6

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);
		// ###############################################
		int i, idx=0, num;
		int* a = new int[N]();// 양수
		int* b = new int[N]();// 음수 -> 최종답

		for (i = 0;i < N;i++) {
			scanf("%d", &num);

			if (num > 0) {
				a[i - idx] = num;
			}
			else {
				b[idx] = num;
				idx++;
			}
		}

		for (i = idx;i < N;i++) {
			b[i] = a[i - idx];
		}

		for (i = 0;i < N;i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		// ###############################################
		// 버블정렬(앞이 양수고 뒤가 음수면 swap)
		//int i, j, tmp;
		//int* a = new int[N]();

		//for (i = 0;i < N;i++) {
		//	scanf("%d", &a[i]);
		//}
		//for (i = 0; i < N - 1; i++) {
		//	for (j = 0; j < N - i - 1;j++) {
		//		if (a[j] > 0 && a[j + 1] < 0) {
		//			tmp = a[j];
		//			a[j] = a[j + 1];
		//			a[j + 1] = tmp;
		//		}
		//	}
		//}

		//for (i = 0;i < N;i++) {
		//	printf("%d ", a[i]);
		//}
		//printf("\n");
		// ###############################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}