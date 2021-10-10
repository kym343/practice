#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 54. �ùٸ� ��ȣ(stack)

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


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}