#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 60. ���� ���� �κ�����(DFS : �Ƹ��� ���ͺ�)

// N���� ���ҷ� ������ �ڿ��� ������ �־�����, �� ������ �� ���� �κ��������� �������� ��
// �� �κ������� ������ ���� ���� ���� ��찡 �����ϸ� ��YES"�� ����ϰ�, �׷��� ������
// ��NO"�� ����ϴ� ���α׷��� �ۼ��ϼ���.
// ���� ���{ 1, 3, 5, 6, 7, 10 }�� �ԷµǸ�{ 1, 3, 5, 7 } = { 6, 10 } ���� �� �κ������� ����
// 16���� ���� ��찡 �����ϴ� ���� �� �� �ִ�.

// �Է¼���
// ù ��° �ٿ� �ڿ��� N(1<=N<=10)�� �־����ϴ�.
// �� ��° �ٿ� ������ ���� N���� �־�����.�� ���Ҵ� �ߺ����� �ʴ´�.

// ��¼���
// ù ��° �ٿ� ��YES" �Ǵ� ��NO"�� ����Ѵ�.

// ex1)
// input
// 6
// 1 3 5 6 7 10

// output
// YES

int N, a[11], i, total;
bool flag = false;

void DFS(int L, int sum) {
	if (sum > (total / 2)) return;
	if (flag) return;
	if (L == N + 1) {
		if (sum == total - sum) flag = true;
	}
	else {
		DFS(L + 1, sum + a[L]);
		DFS(L + 1, sum);
	}

}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d", &N);

		total = 0;
		for (i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
			total += a[i];
		}

		DFS(1, 0);

		if (flag) printf("YES\n");
		else printf("NO\n");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}