#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 77. ģ���ΰ�? (Union&Find �ڷᱸ��)

// ������ �� �б� ���ο� �ݿ��� ó�� �����ϴ� ���̴�. ������ �� �л��� N���̴�. ������ ��
// �л����� ģ�����踦 �˰� �ʹ�.
// ��� �л��� 1���� N���� ��ȣ�� �ο��Ǿ� �ְ�, �������Դ� ���� �� ���� �л��� ģ�� ����
// �� ��ȣ�� ǥ���� ���ڽ��� �־�����.����(1, 2), (2, 3), (3, 4)�� ���ڽ��� �־����� 1�� ��
// ���� 2�� �л��� ģ���̰�, 2�� �л��� 3�� �л��� ģ��, 3�� �л��� 4�� �л��� ģ���̴�.
// �׸��� 1�� �л��� 4�� �л��� 2���� 3���� ���ؼ� ģ�����谡 �ȴ�.
// �л��� ģ�����踦 ��Ÿ���� ���ڽ��� �־����� Ư�� �� ���� ģ�������� �Ǻ��ϴ� ���α׷�
// �� �ۼ��ϼ���.�� �л��� ģ���̸� ��YES"�̰�, �ƴϸ� ��NO"�� ����Ѵ�.

// �Է¼���
// ù ��° �ٿ� �� �л����� �ڿ��� N(1<=N<=1,000)�� ���ڽ��� ������ M(1<=M<=3,000)��
// �־�����, ���� M���� �ٿ� ���� ���ڽ��� �־�����.
// ������ �ٿ��� �� �л��� ģ������ Ȯ���ϴ� ���ڽ��� �־�����.

// ��¼���
// ù ��° �ٿ� ��YES"�Ǵ� "NO"�� ����Ѵ�.

// ex1)
// input
// 9 7
// 1 2
// 2 3
// 3 4
// 4 5
// 6 7
// 7 8
// 8 9
// 3 8

// output
// NO

int unf[1001];

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v]=Find(unf[v]); // "unf[v]=" ��� ����!
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, a, b;
		
		scanf("%d %d", &N, &M);

		for (i = 1;i <= N;i++) {
			unf[i] = i;
		}

		for (i = 0;i < M;i++) {
			scanf("%d %d", &a, &b);

			Union(a, b);
		}

		scanf("%d %d", &a, &b);
		a = Find(a);
		b = Find(b);
		if (a == b) printf("YES\n");
		else printf("NO\n");
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}