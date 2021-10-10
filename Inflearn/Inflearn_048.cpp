#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 48. 각 행의 평균과 가장 가까운 값

// <그림 1>과 같이 9 × 9 격자판에 쓰여진 81개의 자연수가 주어질 때, 각 행의 평균을 구하고,
// 그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요.평균은 소수점 첫 째 자리에서 반
// 올림합니다.평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.

// 입력설명
// 첫 째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다. 주어지는 자연수는 100보
// 다 작다.

// 출력설명
// 첫째 줄에 첫 번째 줄부터 각 줄에 각행의 평균과 그 행에서 평균과 가장 가까운 수를 출력한다.

// ex1)
// input
// 3 23 85 34 17 74 25 52 65
// 10 7 39 42 88 52 14 72 63
// 87 42 18 78 53 45 18 84 53
// 34 28 64 85 12 16 75 36 55
// 21 77 45 35 28 75 90 76 1
// 25 87 65 15 28 11 37 28 74
// 65 27 75 41 7 89 78 64 39
// 47 47 70 45 23 65 3 41 44
// 87 13 82 38 50 12 48 29 80

// output
// 42 34
// 43 42
// 53 53
// 45 36
// 50 45
// 41 37
// 54 64
// 43 44
// 49 50

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, sum, cnt = 0, minn, pos;

		int* a = new int[9]; //vector< vector<int> > a(9, vector<int>(9,0));
		int* avg = new int[9];
		int* res = new int[9];

		for (i = 0; i < 9; i++) {
			sum = 0;
			for (j = 0; j < 9; j++) {
				scanf("%d", &a[j]);
				sum += a[j];
			}

			avg[i] = round((sum / 9.0)); // int((sum / 9.0) + 0.5)
			minn = 2147000000;
			pos = 0;
			for (j = 0; j < 9; j++) {
				if (minn >= abs(a[j] - avg[i])) {
					if (minn == abs(a[j] - avg[i]) && a[pos] > a[j]) {
						continue;
					}
					minn = abs(a[j] - avg[i]);
					pos = j;
					res[i] = a[pos];
				}
			}
		}

		for (i = 0; i < 9; i++) {
			printf("%d %d\n", avg[i], res[i]);
		}

		delete a;
		delete avg;
		delete res;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}