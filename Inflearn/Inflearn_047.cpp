#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 47. 봉우리

// 지도 정보가 N*N 격자판에 주어집니다. 각 격자에는 그 지역의 높이가 쓰여있습니다. 각 격자
// 판의 숫자 중 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역입니다.봉우리 지역이 몇 개
// 있는 지 알아내는 프로그램을 작성하세요.
// 격자의 가장자리는 0으로 초기화 되었다고 가정한다.
// 만약 N = 5 이고, 격자판의 숫자가 다음과 같다면 봉우리의 개수는 10개입니다.

// 0  0  0  0  0  0  0
// 0 '5' 3 '7' 2  3  0
// 0  3 '7' 1 '6' 1  0
// 0 '7' 2  5  3 '4' 0
// 0  4  3 '6' 4  1  0
// 0 '8' 7  3 '5' 2  0
// 0  0  0  0  0  0  0

// 입력설명
// 첫 줄에 자연수 N이 주어진다.(1<=N<=50)
// 두 번째 줄부터 N줄에 걸쳐 각 줄에 N개의 자연수가 주어진다.각 자연수는 100을 넘지 않는
// 다.

// 출력설명
// 봉우리의 개수를 출력하세요.

// ex1)
// input
// 5
// 5 3 7 2 3
// 3 7 1 6 1
// 7 2 5 3 4
// 4 3 6 4 1
// 8 7 3 5 2

// output
// 10

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, cnt = 0;

		scanf("%d", &N);

		vector< vector<int> > a(N + 2, vector<int>(N + 2, 0));

		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		// ######################################################
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]) {
					cnt++;
				}
			}
		}
		// ######################################################
		//	int k, flag=0;
		//	int dx[4]={-1, 0, 1, 0};
		//	int dy[4]={0, 1, 0, -1};
		//	for(i=1; i<=N; i++){
		//		for(j=1; j<=N; j++){
		//			flag=0;
		//			for(k=0; k<4; k++){
		//				if(a[i][j]<=a[i+dx[k]][j+dy[k]]){
		//					flag=1;
		//					break;
		//				}		
		//			}
		//			if(flag==0) cnt++;
		//		}
		//	}
		// ######################################################
		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}