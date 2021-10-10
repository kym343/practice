#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 15. 소수의 개수

// 자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하는 프로그램을 작성하세요.
// 만약 20이 입력되면 1부터 20까지의 소수는 2, 3, 5, 7, 11, 13, 17, 19로 총 8개입니다.
// 제한시간은 1초입니다.

// 입력설명
// 첫 줄에 자연수의 개수 N(2<=N<=200,000)이 주어집니다.

// 출력설명
// 첫 줄에 소수의 개수를 출력합니다.

// ex1)
// input
// 20

// output
// 8

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;
		scanf("%d", &N);

		// ==========================================================
		// 아리스토테네스의 체
		bool num[200001];
		memset(num, true, sizeof(num)); // #include <cstring>

		int temp;
		for (int i = 2; i < N; i++) {
			if (num[i]) {
				for (int j = i+i; j <= N; j=j+i) {
					if(num[j]){
						num[j] = false;
					}
				}
			}
		}

		int cnt = 0;
		for (int i = 2; i <= N; i++) {
			if (num[i]) {
				cnt++;
			}
		}
		// ==========================================================
		// int i, j, flag, cnt=0;
		// for(i=2; i<=n; i++){
		// 		flag = 1;
		// 		for(j=2; j*j<=i; j++){  // WOW 소수확인: 루트 씌운 값까지 확인
		//			if(i%j==0){
		//				flag=0;
		//				break;
		//			}
		//		}
		// 		// if(flag==1) cnt++;
		// }
		// ==========================================================
		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}