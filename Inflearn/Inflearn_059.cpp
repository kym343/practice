#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 59. 부분집합(DFS)

// 자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합을 모두 출력하는 프로그램
// 을 작성하세요.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=10)이 주어집니다.

// 출력설명
// 첫 번째 줄부터 각각의 부분집합을 출력합니다. 부분집합을 출력하는 순서는 출력예제에서 출
// 력한 순서와 같게 합니다.단 공집합은 출력하지 않습니다.

// ex1)
// input
// 3

// output
// 1 2 3
// 1 2
// 1 3
// 1
// 2 3
// 2
// 3

int N, ch[11], i;

void DFS(int L) {
	if (L == N + 1) {
		for (i = 1; i <= N; i++) {
			if(ch[i]==1) printf("%d ", i);
		}
		printf("\n");
	}
	else {
		ch[L] = 1;
		DFS(L + 1);
		ch[L] = 0;
		DFS(L + 1);
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d", &N);

		DFS(1);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}