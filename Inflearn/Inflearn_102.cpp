#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 102. 최대 부분 증가수열(LIS : Longest Increasing Subsequence)

// N개의 자연수로 이루어진 수열이 주어졌을 때, 그 중에서 가장 길게 증가하는(작은 수에서 큰
// 수로) 원소들의 집합을 찾는 프로그램을 작성하라.예를 들어, 원소가 2, 7, 5, 8, 6, 4, 7,
// 12, 3 이면 가장 길게 증가하도록 원소들을 차례대로 뽑아내면 2, 5, 6, 7, 12를 뽑아내어 길
// 이가 5인 최대 부분 증가수열을 만들 수 있다.

// 입력설명
// 첫째 줄은 입력되는 데이터의 수 N(1≤N≤1,000, 자연수)를 의미하고,
// 둘째 줄은 N개의 입력데이터들이 주어진다.

// 출력설명
// 첫 번째 줄에 부분증가수열의 최대 길이를 출력한다.

// ex1)
// input
// 8
// 5 3 7 8 6 2 9 4

// output
// 4

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, res = -2147000000;

		cin >> N;

		vector<int> arr(N + 1), dy(N + 1); // dy[N]: arr[N]이 마지막 항이면서 가장 긴 수열의 길이

		for (i = 1;i <= N;i++) {
			cin >> arr[i];
		}

		dy[1] = 1;
		for (i = 2;i <= N;i++) {
			int maxx = 0;
			for (j = 1;j < i;j++) {
				if (arr[i] > arr[j] && maxx < dy[j]) maxx = dy[j];
			}
			dy[i] = maxx + 1;
			if (dy[i] > res) res = dy[i];
		}

		//for (i = 1;i <= N;i++) {
		//	cout <<"#" << i << " " <<arr[i] <<" : " << dy[i] << endl;
		//}
		cout << res << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}