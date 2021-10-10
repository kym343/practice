#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 58. 이진트리 깊이우선탐색(DFS)

// 아래 그림과 같은 이진트리를 전위순회와 후위순회를 연습해보세요.
//                  1
//              2        3
//            4   5    6   7

// 전위순회 출력 : 1 2 4 5 3 6 7
// 중위순회 출력 : 4 2 5 1 6 3 7
// 후위순회 출력 : 4 5 2 6 7 3 1

void DFS(int L) {
	if (L > 7) return;
	else {

		// 전위순회 출력 : 1 2 4 5 3 6 7
		//printf("%d ", L);

		DFS(L * 2);

		// 중위순회 출력 : 4 2 5 1 6 3 7
		//printf("%d ", L);

		DFS(L * 2 + 1);

		// 후위순회 출력 : 4 5 2 6 7 3 1
		printf("%d ", L);
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		DFS(1);
		printf("\n");
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}