#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 36. 삽입정렬 

// N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
// 정렬하는 방법은 삽입정렬입니다.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
// 두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다.각 자연수는 정수형 범위 안에
// 있습니다.

// 출력설명
// 오름차순으로 정렬된 수열을 출력합니다.

// ex1)
// input
// 6
// 11 7 5 6 10 9

// output
// 5 6 7 9 10 11

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	 
	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		// ##################################################
		// 삽입 정렬이 숫자 받으면서 바로바로 정렬해주고 
		// 넣어주는줄 알았는데 아니네..
		//int i, j, num, idx;
		//int* a = new int[N]();

		//scanf("%d", &a[0]);
		//for (i = 1;i < N;i++) {// 기준
		//	scanf("%d", &num);
		//	idx = 0;

		//	for (j = 0;j < i;j++) {
		//		if (num > a[j]) {
		//			idx++;
		//		}
		//		else {
		//			for (int k = i;k > idx;k--) {
		//				a[k] = a[k-1];
		//			}
		//			break;
		//		}
		//	}
		//	a[idx] = num;
		//}
		//for (i = 0;i < N;i++){
		//	printf("%d ", a[i]);
		//}
		// ##################################################
		int* a = new int[N]();
		int i, j, tmp;
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}

		for (i = 1;i < N;i++) {
			tmp = a[i];
			for (j = i - 1;j >= 0;j--) {
				if (a[j] > tmp) {
					a[j + 1] = a[j];
				}
				else break;
			}
			a[j + 1] = tmp;
		}
		for (i = 0;i < N;i++) {
			printf("%d ", a[i]);
		}
		// ##################################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}