#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 50. 영지(territory) 선택 :(large)

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
// 첫 줄에 H(세로길이)와 W(가로길이)가 입력된다. (1<=H, W<=700) 그 다음 H줄에 걸쳐 각 사
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
		int H, W, i, j, h, w, maxx=-2147000000, tmp;

		scanf("%d %d", &H, &W);

		// #######################################################################
		//int** a = new int* [H];
		//for (i = 0; i < H; i++) {
		//	a[i] = new int[W]; 
		//}

		//for (i = 0; i < H; i++) {
		//	for (j = 0; j < W; j++) {
		//		scanf("%d", &a[i][j]);
		//	}
		//}

		//scanf("%d %d", &h, &w);

		//int** b = new int* [H];
		//for (i = 0; i < H; i++) {
		//	b[i] = new int[W];
		//}

		//b[0][0] = a[0][0];
		//for (j = 1; j < W; j++) {
		//	b[0][j] = b[0][j - 1] + a[0][j];
		//}

		//for (i = 1; i < H; i++) {
		//	b[i][0] = b[i-1][0] + a[i][0];
		//}

		//
		//for (i = 0; i < H; i++) {
		//	for (j = 0; j < W ; j++) {
		//		if (i == 0 && j == 0) {
		//			b[i][j] = a[i][j];
		//		}
		//		else if (i == 0) {
		//			b[0][j] = b[0][j - 1] + a[0][j];
		//		}
		//		else if (j == 0) {
		//			b[i][0] = b[i - 1][0] + a[i][0];
		//		}
		//		else {
		//			b[i][j] = b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1] + a[i][j];
		//		}
		//	}
		//}

		//for (i = h-1; i < H; i++) {
		//	for (j = w-1; j < W; j++) {
		//		if (i == h - 1 && j == w - 1) {
		//			tmp = b[i][j];
		//		}
		//		else if (i == h - 1) {
		//			tmp = b[i][j] - b[i][j - w];
		//		}
		//		else if (j == w - 1) {
		//			tmp = b[i][j] - b[i - h][j];
		//		}
		//		else {
		//			tmp = b[i][j] - b[i - h][j] - b[i][j - w] + b[i - h][j - w];
		//		}
		//		
		//		if (tmp > maxx) {
		//			maxx = tmp;
		//		}
		//	}
		//}

		// #######################################################################
		int** a = new int* [H + 1];
		for (i = 0; i < H + 1; i++) {
			a[i] = new int[W + 1]{};
		}

		int** b = new int* [H + 1];
		for (i = 0; i < H + 1; i++) {
			b[i] = new int[W + 1]{};
		}

		for (i = 1; i <= H; i++) {
			for (j = 1; j <= W; j++) {
				scanf("%d", &a[i][j]);
				b[i][j] = b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1] + a[i][j];
			}
		}

		scanf("%d %d", &h, &w);

		for (i = h; i <= H; i++) {
			for (j = w; j <= W; j++) {
				tmp = b[i][j] - b[i - h][j] - b[i][j - w] + b[i - h][j - w];
				if (tmp > maxx) maxx = tmp;
			}
		}

		// #######################################################################
		delete a;
		delete b;
		printf("%d\n", maxx);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}