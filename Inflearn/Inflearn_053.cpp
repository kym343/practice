#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 53. K���� ���

// 10���� N�� �ԷµǸ� K������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. ���� �ڷᱸ���� ��
// ���Ͻñ� �ٶ��ϴ�.

// �Է¼���
// ù ��° �ٿ� 10���� N(10<=N<=1,000)�� K(2, 5, 8, 16)�� �־�����.

// ��¼���
// K������ ����Ѵ�.

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


// int stack[100], top = -1  // ž�� �׻� ���� �ڷḦ ����Ŵ
// 
//void push(int x) {
//	stack[++top] = x; // top�� �����ϰ� �� ���� x ����
//}
//
//void pop() {
//	return stack[top--]; // ž�� ���� ��ȯ�ϰ� top ����
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
		// stack ����
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


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

