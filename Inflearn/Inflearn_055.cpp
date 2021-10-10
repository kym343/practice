#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 55. 기차운행(stack 응용)

// A도시에서 출발한 기차는 B도시로 도착한다. 그런데 도로 중간에 T자형 교차로가 있어 출발한
// 기차의 도착 순서를 조정할 수 있다.

// 교차로에서는 다음과 같은 두 개의 작업을 합니다.
// P(push)작업 : A도시에서 오는 기차를 교차로에 넣는다.
// O(out)작업 : 교차로에 들어온 가장 최근 기차를 B도시로 보낸다.
// 만약 2 1 3 기차 번호 순으로 A도시에서 출발하더라도 B도시에는 T교차로를 이용하여 1 2 3
// 순으로 도착하게 할 수 있습니다.
// 그 작업 P, P, O, O, P, O순으로 작업을 하면 B도시에 1, 2, 3 순으로 도착합니다.
// 1부터 N까지 번호를 가진 기차가 A도시에서 어떤 순으로 출발하든, B도시에 번호순으로 도착
// 하도록 하는 교차로 작업을 출력합니다.모든 기차는 교차로에 들어가야만 B도시로 갈 수 있
// 습니다.번호순서대로 도착이 불가능하면 impossible 이라고 출력합니다.

// 입력설명
// 첫 번째 줄에 자연수 N(3<=N<=30)가 주어진다.
// 두 번째 줄에 A도시에서 출발하는 기차번호순이 차례대로 입력된다.

// 출력설명
// 교차로 작업을 순서대로 P와 O로 출력한다.

// ex1)
// input
// 3
// 2 1 3

// output
// PPOOPO

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// ###################################################################
		int N, i, cur=1, num, idx=0, flag=1, cnt=0, flag_cnt=1;

		scanf("%d", &N);

		char* b = new char(2*N);
		stack<int> s;
		s.push(2147000000);

		while (cur<=N) {
			if (cnt < N && flag_cnt) {
				scanf("%d", &num); 
				cnt++;
			}

			if (num == cur) {
				b[idx++] = 'P';
				b[idx++] = 'O';
				cur++;
				flag_cnt = 1;
			}
			else if(s.top() == cur) {
				b[idx++] = 'O';
				s.pop();
				cur++;
				flag_cnt = 0;
			}
			else if (s.top() < num) {
				flag = 0;
				break;
			}
			else {
				s.push(num);
				b[idx++] = 'P';
				flag_cnt = 1;
			}
		}

		if (flag) {
			for (i = 0; i < idx;i++) {
				printf("%c", b[i]);
			}
			printf("\n");
		}
		else printf("impossible\n");
		delete b;
		// ###################################################################
		// stack<int> s;
		// int i, j=1, N, m;
		// scanf("%d", &N);
		// // vector<int> a(N+1);
		// // for(i=1;i<=N; i++){
		// //		a[i]=i;
		// // }
		// vector<char> str;
		// for(i=1; i<=n; i++){
		//		scanf("%d", &m);
		//		s.push(m);
		//		str.push_back('P');
		//		while(1){
		//			if(s.empty()) break;
		//			if(j==s.top()){
		//				s.pop();
		//				j++;
		//				str.push_back('O');
		//			}
		//			else break;
		//		}
		// }
		// if(!s.empty()) printf("impossible\n");
		// else{
		//		for(i=0; i<str.size();i++) printf("%c", str[i]);
		//		printf("\n");
		// }  
		// ###################################################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}