#include<iostream>
#include <algorithm>
#include <string>
// #include<stdio.h>

using namespace std;

// 5. ���̰��


// �ֹε������ ��ȣ�� �־����� �ֹε���� ������ ���̿� ������ �Ǵ��Ͽ� ����ϴ� ���α׷�
// �� �ۼ��ϼ���.�ֹε������ ��ȣ�� - �� �������� ���ڸ��� ���ڸ��� ���еȴ�.
// ���ڸ��� ù ��° ���� 1�̸� 1900���� �����̰�, 2�̸� 1900���� ����, 3�̸� 2000���
// �� ����, 4�̸� 2000���� �����̴�.
// ���ش� 2019���Դϴ�.�ش� �ֹε���� ������ ���̿� ������ ����ϼ���.

// �Է¼���
// ù �ٿ� �ֹε���� ��ȣ�� �Էµ˴ϴ�.

// ��¼���
// ù �ٿ� ���̿� ������ ������ �������� ����ϼ���. ������ ���ڴ� M(man), ���ڴ� W(Woman)�� ����Ѵ�.

// ex1)
// input
// 780316-2376152

// output
// 42 W

// ex2)
// input
// 061102-3575393

// output
// 14 M

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char number[15];
		scanf("%s", &number);

		char YY[] = "";
		YY[0] = number[0];
		YY[1] = number[1];
		YY[2] = '\0';

		string text = "";

		if (int(number[7])-'0' < 3) {					// if(number[7]=='1' || number[7]=='2')
			text.append(to_string(119 - atoi(YY) + 1)); //	int age = 119 - (number[0] - '0') *10 + number[1] - '0'
		}
		else {
			text.append(to_string(19 - atoi(YY) + 1));
		}
														// printf("%d ", age)

		if (int(number[7]) % 2 == 1) {					// if(number[7]=='1' || number[7]=='3')
			text += " M";                               //	printf("M\n");
		}												// else printf("W\n);
		else {
			text += " W";
		}

		printf("%s\n", text.c_str());
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}