#include<iostream>
using namespace std;

// https://www.acmicpc.net/problem/10430

int main(int argc, char** argv) {
	//int test_case;
	//int T;

	int A; int B; int C; // input
	int result1; int result2; int result3; int result4; // output

	freopen("sample_input.txt", "r", stdin);
	cin >> A >> B >> C;

	result1 = (A + B) % C;
	result2 = (A%C + B%C) % C;
	result3 = (A * B) % C;
	result4 = (A%C) * (B%C) % C;

	printf("%d\n%d\n%d\n%d", result1, result2, result3, result4);

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}