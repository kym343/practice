#include <iostream>
#include <algorithm>
#include <string>


#pragma warning(disable: 4996)

using namespace std;

// 13. ���� ���� ���� �ڸ���

// N�ڸ��� �ڿ����� �ԷµǸ� �Էµ� �ڿ����� �ڸ��� �� ���� ���� ���� ���ڸ� ����ϴ� ��
// �α׷��� �ۼ��ϼ���.
// ���� ��� 1230565625��� �ڿ����� �ԷµǸ� 5�� 3�� ���Ǿ� ���� ���� ���� �����Դ�
// ��.���� ���� ���� ��� �� �� ���� ū ���� ����ϼ���.

// �Է¼���
// ù �ٿ� �ڿ����� �Էµ˴ϴ�. �ڿ����� ���̴� 100�� ���� �ʽ��ϴ�.

// ��¼���
// ���� ���� ���� ���� ����մϴ�.

// ex1)
// input
// 1230565625

// output
// 5

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char N[101];

		scanf("%s", &N);
		/*printf("%s\n", N);*/

		int i = 0;

		int idx = strlen(N) - 1;
		/*printf("%d\n", idx);*/
		int a[10] = { 0 };
		int cnt = 0;
		int num = -1;

		int number = 0;

		while (idx >= 0) {									// for(i = 0; N[i]!='\0';i++){
			number = int(N[idx]) - '0'; // '0'�� 48�̴�.	//		number = int(N[idx]) - '0';
			a[number]++;									//		a[number]++;
			if (a[number] > cnt) {							// }
				cnt = a[number];							// for(i = 0; i<=9; i++){}
				num = number;								//		if(a[i]>=cnt){
			}												//			cnt = a[i];
			else if (a[number] == cnt && number > num) {	//			rex=i;
				num = number;								// }
			}
			idx--;
		}

		printf("%d\n", num);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}