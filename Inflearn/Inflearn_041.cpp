#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void print_result(int a, int b, int total);

// 41. 연속된 자연수의 합

// 입력으로 양의 정수 N이 입력되면 2개 이상의 연속된 자연수의 합으로 정수 N을 표현하는 방
// 입법의 가짓수를 출력하는 프로그램을 작성하세요.
// 만약 N = 15이면
// 7 + 8 = 15
// 4 + 5 + 6 = 15
// 1 + 2 + 3 + 4 + 5 = 15
// 와 같이 총 3가지의 경우가 존재한다.

// 입력설명
// 첫 번째 줄에 양의 정수 N(7<=N<1000)이 주어진다.

// 출력설명
// 첫줄부터 각각의 경우의 수를 출력한다.
// 맨 마지막 줄에 총 개수를 출력한다.

// ex1)
// input
// 15

// output
// 7 + 8 = 15
// 4 + 5 + 6 = 15
// 1 + 2 + 3 + 4 + 5 = 15
// 3

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// =======================================
		//	int N, i, num, cnt=0, sum;
		//	scanf("%d", &N);
		//	
		//	for(i=N/2+1;i>=1;i--){
		//		sum=0;
		//		num=i;
		//		while(sum<N){
		//			sum += num;
		//			
		//			if(sum==N){
		//				print_result(num,i,N);
		//				cnt++;
		//				break;
		//			}
		//			num--;
		//		}
		//	}
		// =======================================
		int a, b = 1, cnt = 0, tmp, i;
		scanf("%d", &a);
		tmp = a;
		a--;
		while (a > 0) {
			b++;
			a -= b;
			if (a % b == 0) {
				print_result(a / b + 1, a / b + b, tmp);
				cnt++;
			}
		}
		// =======================================
		printf("%d\n", cnt);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void print_result(int a, int b, int total) {
	int i;
	for (i = a;i < b;i++) {
		printf("%d + ", i);
	}
	printf("%d = %d\n", b, total);
}