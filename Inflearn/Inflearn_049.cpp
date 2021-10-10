#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 49. 블록의 최댓값

// 현수는 블록놀이를 좋아합니다. 현수에게 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주
// 고 최대 블록개수를 사용하여 정면과 오른쪽 측면에서 본 모습으로 블록을 쌓으라 했습니다.
// 현수가 블록을 쌓는데 사용해야 할 최대 개수를 출력하는 프로그램을 작성하세요.

// 위에서 봤을 때 각 칸의 블록의 개수입니다. 정면에서의 높이 정보와 오른쪽 측면에서의 높이
// 정보가 주어지면 사용할 수 있는 블록의 쵀대 개수를 출력하세요

// 입력설명
// 첫 줄에 블록의 크기 N(3<=N<=10)이 주어집니다. 블록이 크기는 정사각형 N*N입니다.
// 두 번째 줄에 N개의 정면에서의 높이 정보가 왼쪽 정보부터 주어집니다.
// 세 번째 줄에 N개의 오른쪽 측면 높이 정보가 앞쪽부터 주어집니다.
// 블록의 높이는 10 미만입니다.

// 출력설명
// 첫 줄에 블록의 최대 개수를 출력합니다.

// ex1)
// input
// 4
// 2 0 3 1
// 1 1 2 3

// output
// 17

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, tmp, sum = 0;

		scanf("%d", &N);

		int** a = new int* [N];   // vector< vector<int> > a(N, vector<int>(N, 0));
		for (i = 0; i < N; i++) {
			a[i] = new int[N];
		}

		for (j = 0; j < N; j++) {
			scanf("%d", &tmp);
			for (i = 0; i < N; i++) {
				a[i][j] = tmp;
			}
		}

		for (i = N - 1; i >= 0; i--) {
			scanf("%d", &tmp);
			for (j = 0; j < N; j++) {
				if (tmp < a[i][j]) {
					a[i][j] = tmp;
				}
			}
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				sum += a[i][j];
			}
		}
		delete a;
		printf("%d\n", sum);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}