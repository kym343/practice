#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 44. 마구간 정하기(이분검색 응용)

// N개의 마구간이 1차원 수직선상에 있습니다. 각 마구간은 x1, x2, x3, ......, xN의 좌표를 가
// 지며, 마구간간에 좌표가 중복되는 일은 없습니다.
// 현수는 C마리의 말을 가지고 있는데, 이 말들은 서로 가까이 있는 것을 좋아하지 않습니다.
// 각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을
// 마구간에 배치하고 싶습니다.
// C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 최대가 되는 그 최대
// 값을 출력하는 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 자연수 N(3<=N<=200,000)과 C(2<=C<=N)이 공백을 사이에 두고 주어집니다.
// 둘째 줄부터 N개의 줄에 걸쳐 마구간의 좌표 xi(0 <= xi <= 1,000,000,000)가 한 줄에 하나씩
// 주어집니다.

// 출력설명
// 첫 줄에 가장 가까운 두 말의 최대 거리를 출력하세요.

// ex1)
// input
// 5 3
// 1
// 2
// 8
// 4
// 9

// output
// 3

int N;
bool Counter(vector<int> a, int d, int c) {
	int i, pre = 0, cnt = 0;

	for (i = 1; i < N; i++) {
		if (a[i] - a[pre] >= d) {
			pre = i;
			cnt++;
		}
		if (cnt == c) {
			return true;
		}
	}
	return false;
}
// 답을 정하고 좁혀나갈 때 유용 -> 이분검색 

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int C, i, res = 0, left = 1, right, mid;
		int maxx = 0, minn = 1000000000;
		scanf("%d %d", &N, &C);

		vector<int> a(N);
		for (i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			if (a[i] > maxx) {
				maxx = a[i];
			}
			if (a[i] < minn) {
				minn = a[i];
			}
		}

		sort(a.begin(), a.end());

		right = maxx - minn;

		while (left <= right) {
			mid = (left + right) / 2;
			if (Counter(a, mid, C - 1) == true) {
				res = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		printf("%d\n", res);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}