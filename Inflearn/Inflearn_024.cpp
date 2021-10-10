#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 24. Jolly Jumpers 

// N���� ������ �̷���� ������ ���� ���� ������ �ִ� �� ���� ���� 1���� N-1������ ����
// ��� ������ �� ������ ������ ����(jolly jumper)��� �θ���.���� ��� ������ ���� ������
// �� 1 4 2 3 �� �ڿ� �ִ� ���� ���� ���� ���� ���� 3, 2, 1�̹Ƿ� �� ������ ������ ���۰�
// �ȴ�.� ������ ������ �������� �Ǵ��� �� �ִ� ���α׷��� �ۼ��϶�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(3<=N<=100)�� �־�����.
// �� ���� �ٿ� N���� ������ �־�����.������ ũ��� int �� �����ȿ� �ֽ��ϴ�.

// ��¼���
// ������ �����̸� ��YES"�� ����ϰ�, �׷��� ������ ��NO"�� ����Ѵ�.

// ex1)
// input
// 5
// 1 4 2 3 7

// output
// YES

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N-1](); // vector<int> a(N);
		int pre, now, jumper, flag=0;
		scanf("%d", &pre); 

		for (int i = 0; i < N-1; i++) {
			scanf("%d", &now);

			jumper = abs(pre - now);
			if (jumper>0 && jumper<N && a[jumper - 1] == 0) {
				a[jumper - 1]++;
				pre = now;
			}
			else {
				flag = 1;
				// ##########################
				//printf("NO\n");
				//return 0;
				// ##########################
				break;
			}
		}
		if (flag == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}