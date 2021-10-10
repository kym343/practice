#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 107. 동전교환

// 다음과 같이 여러 단위의 동전들이 주어져 있을때 거스름돈을 가장 적은 수의 동전으로 교환
// 해주려면 어떻게 주면 되는가 ? 각 단위의 동전은 무한정 쓸 수 있다.

// 입력설명
// 첫 번째 줄에는 동전의 종류개수 N(1<=N<=12)이 주어진다. 두 번째 줄에는 N개의 동전의 종
// 류가 주어지고, 그 다음줄에 거슬러 줄 금액 M(1 <= M <= 500)이 주어진다.
// 각 동전의 종류는 100원을 넘지 않는다.

// 출력설명
// 첫 번째 줄에 거슬러 줄 동전의 최소개수를 출력한다.

// ex1)
// input
// 3
// 1 2 5
// 15

// output
// 3

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j;

		cin >> N;
		vector<int> arr(N, 0);
		for (i = 0;i < N;i++) {
			cin >> arr[i];
		}

		cin >> M;
		vector<int> dy(M+1, 0);
		for (i = 1;i <= M;i++) {
			dy[i] = i;
		}


		for (i = 0;i < N;i++) {
			for (j = arr[i];j <= M;j++) {
				dy[j] = min(dy[j], dy[j - arr[i]] + 1);
			}
		}

		cout << dy[M] << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}