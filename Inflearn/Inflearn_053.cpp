#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 53. K진수 출력

// 10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 스택 자료구조를 사
// 용하시기 바랍니다.

// 입력설명
// 첫 번째 줄에 10진수 N(10<=N<=1,000)과 K(2, 5, 8, 16)가 주어진다.

// 출력설명
// K진수를 출력한다.

// ex1)
// input
// 11 2

// output
// 1011

// ex2)
// input
// 31 16

// output
// 1F


// int stack[100], top = -1  // 탑은 항상 맨위 자료를 가리킴
// 
//void push(int x) {
//	stack[++top] = x; // top이 증가하고 그 곳에 x 저장
//}
//
//void pop() {
//	return stack[top--]; // 탑의 값을 반환하고 top 감소
//}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, K, r, q, i, s;

		scanf("%d %d", &N, &K);

		stack<int> a;

		// #######################################
		q = N;
		while (q / K != 0) {
			r = q % K;
			q = q / K;

			a.push(r);
		
			if (q / K == 0) {
				a.push(q);
			}
		}
		
		s = a.size();
		for (i = 0;i < s;i++) {
			if (a.top() >= 10) {
				printf("%c", (a.top() + 55));
			}
			else printf("%d", a.top());
			a.pop();
		}
		printf("\n");
		// #######################################
		// char str[20] = "0123456789ABCDEF";
		// 
		// while(N>0){
		//		push(N%k);
		//		N = N/K;
		// }
		//
		// while(top!=-1){
		//		printf("%c", str[pop()]);
		// }
		// #######################################
		// stack 사용시
		// char str[20] = "0123456789ABCDEF";
		// 
		// while(N>0){
		//		a.push(N%K);
		//		n=n/k;
		// }
		// while(!s.empty()){
		//		printf("%c", str[a.top()]);
		//		a.pop();
		// }
		// #######################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

