#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// [선수지식] 조합구하기(DFS 활용)

// 0부터 N-1 까지인 N개의 숫자 중 R를 선택하는 조합 모두와 개수를 구하라

// 입력설명
// 갯수 N, 선택할 숫자 R

// 출력설명
// 0부터 N-1 까지인 N개의 숫자 중 R를 선택하는 조합 모두와 개수

// ex1)
// input
// 6 4

// output
// 0 1 2 3
// 0 1 2 4
// 0 1 2 5
// 0 1 3 4
// 0 1 3 5
// 0 1 4 3
// 0 1 4 5
// 0 2 3 4
// 0 2 3 5
// 0 2 4 3
// 0 2 4 5
// 0 3 2 4
// 0 3 2 5
// 0 3 4 5
// 1 2 3 4
// 1 2 3 5
// 1 2 4 3
// 1 2 4 5
// 1 3 2 4
// 1 3 2 5
// 1 3 4 5
// 2 1 3 4
// 2 1 3 5
// 2 1 4 3
// 2 1 4 5
// 2 3 4 5
// 26

int N, R, cnt=0;
int ch[20];
int res[20];

// ======================================================
//void DFS(int L) {
//	if (L == R) {
//		cnt++;
//		for (int i = 0;i < R; i++) {
//			printf("%d ", res[i]);
//		}
//		puts("");
//	}
//	else {
//		for (int i = L;i < N - R + L + 1;i++) {
//			if (L != 0 && res[L - 1] > i) continue;
//			if (ch[i] == 0) {
//				ch[i] = 1;
//				res[L] = i;
//				DFS(L + 1);
//
//				ch[i] = 0;
//			}
//		}
//	}
//}
// ======================================================
void DFS(int s, int L) {
	if(L==R){
		cnt++;
		for (int i = 0;i < R; i++) {
			printf("%d ", ch[i]);
		}
		puts("");
	}
	else {
		for (int i = s;i < N;i++) {
			ch[L] = i;
			DFS(i + 1, L + 1);
		}
	}
}
// ======================================================

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i;

		scanf("%d %d", &N, &R);

		//DFS(0);
		// ==============================================
		DFS(0, 0);
		// ==============================================

		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}