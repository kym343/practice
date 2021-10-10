#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 16. Anagram(�Ƴ��׷� : ���� ���ͺ� ����)

// Anagram�̶� �� ���ڿ��� ���ĺ��� ���� ������ �ٸ����� �� ������ ��ġ�ϸ� �� �ܾ�� ��
// ���׷��̶�� �մϴ�.
// ���� ��� AbaAeCe �� baeeACA �� ���ĺ��� ���� ������ �ٸ����� �� ������ ���캸��
// A(2), a(1), b(1), C(1), e(2)�� ���ĺ��� �� ������ ��� ��ġ�մϴ�.�� ��� �� �ܾ ��
// �迭�ϸ� ����� �ܾ �� �� �ִ� ���� �Ƴ��׷��̶� �մϴ�.
// ���̰� ���� �� ���� �ܾ �־����� �� �ܾ �Ƴ��׷����� �Ǻ��ϴ� ���α׷��� �ۼ��ϼ�
// ��.�Ƴ��׷� �Ǻ��� ��ҹ��ڰ� ���е˴ϴ�.

// �Է¼���
// ù �ٿ� ù ��° �ܾ �Էµǰ�, �� ��° �ٿ� �� ��° �ܾ �Էµ˴ϴ�.
// �ܾ��� ���̴� 100�� ���� �ʽ��ϴ�.

// ��¼���
// �� �ܾ �Ƴ��׷��̸� ��YES"�� ����ϰ�, �ƴϸ� ��NO"�� ����մϴ�.

// ex1)
// input
// AbaAeCe
// baeeACA

// output
// YES

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char str1[100], str2[100];
		int cnt[58] = { 0 };
		// fill_n(cnt, sizeof(cnt), 0);

		scanf("%s", &str1);
		scanf("%s", &str2);

		if (strlen(str1) == strlen(str2)) {
			for (int i = 0; i < strlen(str1); i++) { // for(int i=0; str1[i]!='\0'; i++){
				cnt[str1[i] - 'A']++;
				cnt[str2[i] - 'A']--;
			}

			int flag = 0;
			for (int i = 0; i < 58; i++) {
				if (cnt[i] != 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				printf("NO\n");
			}
			else{
				printf("YES\n");
			}

		}
		else {
			printf("NO\n");
		}
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}