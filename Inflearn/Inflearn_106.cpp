#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 106. 가방문제(냅색 알고리즘)

// 최고 17kg의 무게를 저장할 수 있는 가방이 있다. 그리고 각각 3kg, 4kg, 7kg, 8kg, 9kg의
// 무게를 가진 5종류의 보석이 있다.이 보석들의 가치는 각각 4, 5, 10, 11, 13이다.
// 이 보석을 가방에 담는데 17kg를 넘지 않으면서 최대의 가치가 되도록 하려면 어떻게 담아야
// 할까요 ? 각 종류별 보석의 개수는 무한이 많다.한 종류의 보석을 여러 번 가방에 담을 수 있
// 다는 뜻입니다.

// 입력설명
// 첫 번째 줄은 보석 종류의 개수와 가방에 담을 수 있는 무게의 한계값이 주어진다.
// 두 번째 줄부터 각 보석의 무게와 가치가 주어진다.
// 가방의 저장무게는 1000kg을 넘지 않는다.보석의 개수는 30개 이내이다.

// 출력설명
// 첫 번째 줄에 가방에 담을 수 있는 보석의 최대가치를 출력한다.

// ex1)
// input
// 4 11
// 5 12
// 3 8
// 6 14
// 4 8

// output
// 28

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, w, v;

		cin >> N >> M;

		vector<int> dy(M + 1, 0);
		for (i = 1;i <= N;i++) {
			cin >> w >> v;
			for (j = w;j <= M;j++) {
				dy[j] = max(dy[j], dy[j - w] + v);
			}
		}

		cout << dy[M] << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}