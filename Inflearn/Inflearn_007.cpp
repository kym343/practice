#include <iostream>
#include <algorithm>
#include <string>

#pragma warning(disable: 4996)

using namespace std;

// 7. ����ܾ� ����

// ������ ��ǻ�Ͱ� ���̷����� �ɷ� ����ܾ �پ��� ��ҹ��ڰ� ȥ�յǾ� ǥ���ȴ�.
// ���� ��� �Ƹ��ٿ� �̶� ���� ������ �ִ� beautiful �ܾ ��bE au T I fu L�� �� ����
// ��ǻ�Ϳ� ǥ�õǰ� �ֽ��ϴ�.���� ���� ������ ǥ�õǴ� ����ܾ ������ ǥ����� ������
// �����ϰ� �ҹ���ȭ ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� ���̷����� �ɸ� ����ܾ �־�����. ���̷����� �ɸ� ����ܾ��� ����(��������)��
// 100�� ���� �ʴ´�.���ڻ����� ������ ���������� ������ �� �ֽ��ϴ�.�Է��� ���ĺ��� ��
// �鸸 �־����ϴ�.

// ��¼���
// ù �ٿ� �ҹ��ڷ� �� �������� ����ܾ ����Ѵ�.

// ex1)
// input
// bE au T I fu L

// output
// beautiful

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char a[100];

		scanf(" %[^\n]", &a);//gets(a);
		
		char text[100]="";

		char *token;
		token = strtok(a, " ");

		while (token != NULL){
			strcat(text, token);
			token = strtok(NULL, " ");
		}
		
		for (int i = 0; i < strlen(text); i++) {
			putchar(tolower(text[i]));
		}
		printf("\n");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}