#include <iostream>
#include <algorithm>

using namespace std;

// 12. 숫자의 총 개수(large)

// 자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
// 예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
// 총 21개가 쓰였음을 알 수 있습니다.
// 자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작
// 성하세요.

// 입력설명
// 첫 번째 줄에는 자연수 N(3<=N<=100,000,000)이 주어진다.

// 출력설명
// 첫 번째 줄에 숫자의 총개수를 출력한다.

// ex1)
// input
// 15

// output
// 21

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int temp = N;
		int a[10] = { 0 };// 10의 i 제곱에 대한 자릿수 개수
						 // a[0] : 1 ~ 9 -> 최대 9
						 // a[1] : 10~99 -> 최대 90
		int b = -1;
		int c = 1;
		int cnt = 0;
									// res=0; c= 1; d=9;
		while (temp > 0) {			// while(sum+d < N){
			b++;					//	 res = res+(c*d);
									//	 sum = sum + d;
			if (temp >= 10) {		//	 c++;
				a[b] = 9 * c;		//	 d *= 10;
				c *= 10;			// }
			}						// res=res+((n-sum)*c)
			else {
				a[b] = N - c + 1;
			}
			temp /= 10;
		}

		int sum = 0;
		int i = 0;

		while (a[i] != 0) {
			sum += (i + 1)*a[i];
			i++;
		}
		printf("%d\n", sum);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}