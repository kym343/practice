#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 109. 플로이드 워샬 알고리즘

// N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 해당 도로를 통행하는 비용이 주어질
// 때 모든 도시에서 모든 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 프로그램을 작성하
// 세요.

// 입력설명
// 첫 번째 줄에는 도시의 수N(N<=100)과 도로수 M(M<=200)가 주어지고, M줄에 걸쳐 도로정보
// 와 비용(20 이하의 자연수)이 주어진다.만약 1번 도시와 2번도시가 연결되고 그 비용이 13이
// 면 “1 2 13”으로 주어진다.

// 출력설명
// 모든 도시에서 모든 도시로 이동하는데 드는 최소 비용을 아래와 같이 출력한다.
// 자기자신으로 가는 비용은 0입니다.i번 정점에서 j번 정점으로 갈 수 없을 때는 비용을 “M"으
// 로 출력합니다.

// ex1)
// input
// 8
// 1 2 6
// 1 3 3
// 3 2 2
// 2 4 1
// 2 5 13
// 3 4 5
// 4 2 3
// 4 5 7

// output
// 0 5 3 6 13		//1번 정점에서 2번정점으로 5, 1에서 3번 정점으로 3, 1에서 4번 정점으로 6......
// M 0 M 1 8		//2번 정점에서 1번 정점으로는 갈수 없으므로 “M", .......
// M 2 0 3 10
// M 3 M 0 7
// M M M M 0

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, k, a, b, c;

		cin >> N >> M;

		vector<vector<int> > dy(N + 1, vector<int>(N + 1, 5000));
		for (i = 1;i <= M;i++) {
			cin >> a >> b >> c;
			dy[a][b] = c;
		}

		for (i = 1;i <= N;i++) dy[i][i] = 0;
		for (k = 1;k <= N; k++) {
			for (i = 1;i <= N;i++) {
				for (j = 1;j <= N;j++) {
					dy[i][j] = min(dy[i][j], dy[i][k] + dy[k][j]);
				}
			}
		}

		for (i = 1;i <= N;i++) {
			for (j = 1;j <= N;j++) {
				if (dy[i][j] == 5000) cout << "M ";
				else cout << dy[i][j] <<" ";
			}
			cout << endl;
		}
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}