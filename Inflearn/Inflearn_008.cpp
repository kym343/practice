#include <iostream>
#include <algorithm>

using namespace std;

// 8. 올바른 괄호

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

		scanf("%s", &a);

		string buf;
		buf.clear();

		string::iterator it;
		it = buf.end();
		for (int i = 0; i < strlen(a); i++) {
			/*printf("%c\n", a[i]);
			printf("buf : %s \n", buf.c_str());*/

			if (buf.empty()) {
				/*printf("%d : %c \n", i, a[i]);*/
				buf += a[i];

				if (a[i] == ')') {
					break;
				}
			}
			else if (*it == a[i]) {
				buf += a[i];
			}
			else {
				buf.erase(buf.end()-1);
			}
			/*printf("buf : %s \n", buf.c_str());*/
		}

		if (buf.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}