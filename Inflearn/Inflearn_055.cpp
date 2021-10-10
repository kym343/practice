#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 55. ��������(stack ����)

// A���ÿ��� ����� ������ B���÷� �����Ѵ�. �׷��� ���� �߰��� T���� �����ΰ� �־� �����
// ������ ���� ������ ������ �� �ִ�.

// �����ο����� ������ ���� �� ���� �۾��� �մϴ�.
// P(push)�۾� : A���ÿ��� ���� ������ �����ο� �ִ´�.
// O(out)�۾� : �����ο� ���� ���� �ֱ� ������ B���÷� ������.
// ���� 2 1 3 ���� ��ȣ ������ A���ÿ��� ����ϴ��� B���ÿ��� T�����θ� �̿��Ͽ� 1 2 3
// ������ �����ϰ� �� �� �ֽ��ϴ�.
// �� �۾� P, P, O, O, P, O������ �۾��� �ϸ� B���ÿ� 1, 2, 3 ������ �����մϴ�.
// 1���� N���� ��ȣ�� ���� ������ A���ÿ��� � ������ ����ϵ�, B���ÿ� ��ȣ������ ����
// �ϵ��� �ϴ� ������ �۾��� ����մϴ�.��� ������ �����ο� ���߸� B���÷� �� �� ��
// ���ϴ�.��ȣ������� ������ �Ұ����ϸ� impossible �̶�� ����մϴ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(3<=N<=30)�� �־�����.
// �� ��° �ٿ� A���ÿ��� ����ϴ� ������ȣ���� ���ʴ�� �Էµȴ�.

// ��¼���
// ������ �۾��� ������� P�� O�� ����Ѵ�.

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


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}