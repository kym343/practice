#include <iostream>
#include <algorithm>

using namespace std;

// 8. �ùٸ� ��ȣ

// ��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� ��YES", �ùٸ��� ������ ��NO"�� ����մϴ�.
// (())() �̰��� ��ȣ�� ���� �ùٸ��� ��ġ�ϴ� ������, (()()))�� �ùٸ� ��ȣ�� �ƴϴ�.

// �Է¼���
// ù ��° �ٿ� ��ȣ ���ڿ��� �Էµ˴ϴ�. ���ڿ��� �ִ� ���̴� 30�̴�.

// ��¼���
// ù ��° �ٿ� YES, NO�� ����Ѵ�.

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


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}