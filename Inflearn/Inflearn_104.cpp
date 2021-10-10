#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 104. 가장 높은 탑 쌓기

// 밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다. 탑은 벽돌을 한 개씩 아래
// 에서 위로 쌓으면서 만들어 간다.아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프
// 로그램을 작성하시오.

// (조건1)벽돌은 회전시킬 수 없다.즉, 옆면을 밑면으로 사용할 수 없다.
// (조건2)밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
// (조건3)벽돌들의 높이는 같을 수도 있다.
// (조건4)탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
// (조건5)무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.

// 입력설명
// 입력 파일의 첫째 줄에는 입력될 벽돌의 수가 주어진다. 입력으로 주어지는 벽돌의 수는 최대
// 100개이다.둘째 줄부터는 각 줄에 한 개의 벽돌에 관한 정보인 벽돌 밑면의 넓이, 벽돌의 높
// 이 그리고 무게가 차례대로 양의 정수로 주어진다.각 벽돌은 입력되는 순서대로 1부터연속적
// 인 번호를 가진다.

// 출력설명
// 첫 번째 줄에 가장 높이 쌓을 수 있는 탑의 높이를 출력한다.

// ex1)
// input
// 5
// 25 3 4
// 4 4 6
// 9 2 3
// 16 2 5
// 1 5 2

// output
// 10

struct Block {
	int s, h, w;
	Block(int a, int b, int c) {
		s = a;
		h = b;
		w = c;
	}
	bool operator < (const Block & b) const {
		return s > b.s;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, a, b, c, maxx, res;

		cin >> N;

		vector<Block> blk;
		for (i = 0; i < N;i++) {
			cin >> a >> b >> c;
			blk.push_back(Block(a, b, c));
		}

		sort(blk.begin(), blk.end());

		vector<int> dy(N); 
		dy[0] = blk[0].h;
		res = -2147000000;
		for (i = 1;i < N;i++) {
			maxx = 0;
			for (j = i - 1; j >= 0;j--) {
				if (blk[i].w < blk[j].w && maxx < dy[j]) maxx = dy[j];
			}
			dy[i] = maxx + blk[i].h;
			if (res < dy[i]) res = dy[i];
		}
		cout << res << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}