#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 111. 위상정렬(그래프 정렬)

// 위상정렬은 어떤 일을 하는 순서를 찾는 알고리즘입니다.
// 각각의 일의 선후관계가 복잡하게 얽혀있을 때 각각 일의 선후관계를 유지하면서 전체 일의
// 순서를 짜는 알고리즘입니다.
// 만약 아래와 같은 일의 순서를 각각 지키면서 전체 일의 순서를 정한다면
// 1 4 //1번일을 하고 난 후 4번일을 해야한다.
// 5 4
// 4 3
// 2 5
// 2 3
// 6 2

// 전체 일의 순서는 1, 6, 2, 5, 4, 3과 같이 정할 수 있다.전체 일의 순서는 여러 가지가 있습
// 니다 그 중에 하나입니다.


// 입력설명
// 첫 번째 줄에 전체 일의 개수 N과 일의 순서 정보의 개수 M이 주어집니다.
// 두 번째 줄부터 M개의 정보가 주어집니다.

// 출력설명
// 전체 일의 순서를 출력합니다.

// ex1)
// input
// 6 6
// 1 4
// 5 4
// 4 3
// 2 5
// 2 3
// 6 2

// output
// 1 6 2 5 4 3


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, k, a, b;

		cin >> N >> M;

		vector<int> dy(N + 1, 0);
		vector<int> graph[100];
		queue<int> Q;

		for (i = 1;i <= M;i++) {
			cin >> a >> b;
			dy[b]++;
			graph[a].push_back(b);
		}

		for (i = 1;i <= N;i++) {
			if (dy[i] == 0) Q.push(i);
		}

		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			cout << now << " ";
			for (i = 0;i < graph[now].size();i++) {
				int next = graph[now][i];
				dy[next]--;
				if (dy[next] == 0) Q.push(next);
			}
		}
		cout << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}