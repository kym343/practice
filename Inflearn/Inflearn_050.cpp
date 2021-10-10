#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 50. 영지(territory) 선택 : (small)

// 세종대왕은 현수에게 현수가 다스릴 수 있는 영지를 하사하기로 했다. 전체 땅은 사각형으로 표
// 시된다.그 사각형의 땅 중에서 세종대왕이 현수가 다스릴 수 있는 땅의 크기(세로의 길이와 가
// 로의 길이)를 정해주면 전체 땅 중에서 그 크기의 땅의 위치를 현수가 정하면 되는 것이다.
// 전체 땅은 사각형의 모양의 격자로 되어 있으며, 그 사각형 땅 안에는 많은 오렌지 나무가 심
// 겨져 있다.현수는 오렌지를 무척 좋아하여 오렌지 나무가 가장 많이 포함되는 지역을 선택하
// 고 싶어 한다.현수가 얻을 수 있는 영지의 오렌지 나무 최대 개수를 출력하는 프로그램을 작
// 성하세요.다음과 같은 땅의 정보가 주어지고, 현수가 하사받을 크기가, 가로 2, 세로 3의 크
// 기이면 가장 많은 오렌지 나무가 있는 영지는 총 오렌지 나무의 개수가 16인 3행 4열부터 시
// 작하는 구역이다.

// 입력설명
// 첫 줄에 H(세로길이)와 W(가로길이)가 입력된다. (5<=H, W<=50) 그 다음 H줄에 걸쳐 각 사
// 각형 지역에 오렌지의 나무 개수(1~9개) 정보가 주어진다.
// 그 다음 영지의 크기인 세로길이(1~H)와 가로길이(1~W)가 차례로 입력된다.

// 출력설명
// 첫 줄에 현수가 얻을 수 있는 오렌지 나무의 최대 개수를 출력한다.

// ex1)
// input
// 6 7
// 3 5 1 3 1 3 2
// 1 2 1 3 1 1 2
// 1 3 1 5 1 3 4
// 5 1 1 3 1 3 2
// 3 1 1 3 1 1 2
// 1 3 1 3 1 2 2
// 2 3

// output
// 16

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int H, W, i, j, h, w, x, y, maxx = -2147000000, sum = 0;

		scanf("%d %d", &H, &W);

		int** a = new int* [H]; // vector< vector<int> > a(H, vector<int>(W, 0);
		for (i = 0; i < H; i++) {
			a[i] = new int[W];
		}

		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		scanf("%d %d", &h, &w);

		for (i = 0; i < H - h + 1; i++) {
			for (j = 0; j < W - w + 1; j++) {
				sum = 0;
				for (x = i; x < i + h; x++) {
					for (y = j; y < j + w; y++) {
						sum += a[x][y];
					}
				}
				if (maxx < sum) {
					maxx = sum;
				}
			}
		}

		printf("%d\n", maxx);
		delete a;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}