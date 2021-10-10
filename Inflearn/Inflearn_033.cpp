#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 33. 3등의 성적은?

// N명의 수학성적이 주어지면 그 중 3등을 한 수학성적을 출력하는 프로그램을 작성하세요.
// 만약 학생의 점수가 100점이 3명, 99점이 2명, 98점이 5명, 97점이 3명 이런식으로 점수가
// 분포되면 1등은 3명이며, 2등은 2명이며 3등은 5명이 되어 98점이 3등을 한 점수가 됩니다.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
// 두 번째 줄에 N개의 수학성적 점수가 공백을 사이에 두고 입력됩니다.수학성적 점수는 100점
// 만점 기준으로 입력됩니다.

// 출력설명
// 3등을 한 점수를 출력합니다.

// ex1)
// input
// 7
// 80 96 75 82 96 92 100

// output
// 92

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);
		// ######################################
		int* a = new int[3]();
		int i, num, idx;
		for (i = 0;i < N;i++) {
			scanf("%d", &num);

			idx = 0;
			while (idx<3) {
				if (num > a[idx]) {
					for (int j = 1;j >= idx; j--) {
						a[j + 1] = a[j];
					}
					a[idx] = num;
					break;
				}
				else if (num == a[idx]) break;
				idx++;
			}
		}
		printf("%d\n", a[2]);

		// ######################################
		// 문제 의도)
		// 내림차순으로 선택 정렬 -> 같은거 빼고 3번째로 큰거 채택
		//       (cnt는 앞뒤 다를때마다 +1, 2일때 출력)
		// 
		// ######################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}