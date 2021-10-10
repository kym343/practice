#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>

using namespace std;

// 23. ���� �κ� �������� 

// N���� ���ڰ� ������ ������ �־����ϴ�. �� ���� �� ���������� �����ϴ� �κ� ������ �ִ�
// ���̸� ���Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
// ���� N = 9�̰�
// 5 7 3 3 12 12 13 10 11 �̸� ��3 3 12 12 13���κ��� �ִ� ���� ���������̹Ƿ� �� ������
// 5�� ����մϴ�.���� ���� ���� �����ϴ� �ɷ� �����մϴ�.

// �Է¼���
// ù �ٿ� �ڿ����� ���� N(5<=N<=100,000)�� �־����ϴ�.
// �� ��° �ٿ� N���� ���ڿ��� �־����ϴ�.�� ���ڴ� 100, 000������ �ڿ����Դϴ�.

// ��¼���
// �ִ� �κ� ���������� ���̸� ����ϼ���.

// ex1)
// input
// 9
// 5 7 3 3 12 12 13 10 11

// output
// 5

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;
		scanf("%d", &N);
		// ################################################################
		int* a = new int[N](); // std::vector<int> a(N);
		int count=1;
		int max = 1;

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);

			if (i != 0 && a[i] >= a[i - 1]) {
				count++;
			}
			else{
				if (max < count) {
					max = count;
				}
				count = 1;
			}
		}

		if (max < count) {// �Ǹ��������� üũ(��� Ŀ���� ��� ����)
			max = count;
		}
		// ################################################################
		//int pre, now, cnt, max = -1;
		//scanf("%d", &pre);
		//cnt = 1;
		//max = 1;
		//for (int i = 2; i < N; i++) {
		//	scanf("%d", &now);
		//	if (now >= pre) {
		//		cnt++;
		//		if (cnt > max) max = cnt;
		//	}
		//	else cnt = 1;
		//	pre = now;
		//}
		// ################################################################
		printf("%d\n", max);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}