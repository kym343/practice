#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 54. 올바른 괄호(stack)

// 괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
// (())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.

// 입력설명
// 첫 번째 줄에 괄호 문자열이 입력됩니다. 문자열의 최대 길이는 30이다.

// 출력설명
// 첫 번째 줄에 YES, NO를 출력한다.

// ex1)
// input
// (()(()))(()

// output
// NO

// ex2)
// input
// ()()(()())

// output
// YES

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char a[30];
		int idx=0, flag=0;

		scanf("%s", &a);

		stack<int> s;

		while (a[idx] != '\0') {
			if (a[idx] == '(') {
				s.push(1);
			}
			else {
				if (s.empty()) {
					flag++;
					break;
				}
				s.pop();
			}
			idx++;
		}
		if (s.empty() && flag==0) {
			printf("YES\n");
		}
		else printf("NO\n");
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}