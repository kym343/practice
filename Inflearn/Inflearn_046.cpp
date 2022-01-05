#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 46. ��Ƽ�½�ŷ(īī�� �Թ� ���� ����)

// ������ ��ǻ�ʹ� ��Ƽ�½�ŷ�� �����ϴ�. ó���ؾ� �� �۾��� N�� ������ ������ ��ǻ�ʹ�
// �۾��� 1���� N������ ��ȣ�� �ο��ϰ� ó���� ������ ���� �Ѵ�.
// 1) ��ǻ�ʹ� 1�� �۾����� ������� 1�ʾ� �۾��� �Ѵ�.�� �� �۾��� 1�ʸ� �۾��ϰ� ����
// �۾��� �ϴ� ���̴�.
// 2) ������ ��ȣ�� �۾��� 1�� ������ �ٽ� 1�� �۾����� ���� �ٽ� 1�ʾ� �ļ� ó���� �Ѵ�.
// 3) ó���� ���� �۾��� �۾� �����쿡�� ������� ���ο� �۾��� ������ �ʴ´�.
// �׷��� ������ ��ǻ�Ͱ� ���� ������ �� K�� �Ŀ� ������ �Ǿ� ��ǻ�Ͱ� �Ͻ������� ���߾�
// ��.���Ⱑ ������ ���� ������ ��ǻ�Ͱ� �� �� �۾����� �ٽ� �����ؾ� �ϴ��� �˾Ƴ���
// ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù ��° �ٿ� �۾��� ���� N(1<=N<=2,000)�� �־����� �� ���� N�ٿ� ���� �� �۾���
// ó���ϴµ� �ɸ��� �ð��� �ʴ����� �־�����.�� �۾��� ó���ϴµ� �ʿ��� �ð��� 1, 000��
// ���� �ʴ´�.
// ������ �ٿ� ������ �߻��� �ð� K(1 <= K <= 2,000,000)�� �־�����.

// ��¼���
// ù ��° �ٿ� �� �� �۾����� �ٽ� �����ؾ� �ϴ��� �۾� ��ȣ�� ����Ѵ�.
// ���� �� �̻� ó���� �۾��� ���ٸ� - 1�� ����Ѵ�.

// ex1)
// input
// 3
// 1
// 2
// 3
// 5

// output
// 3

// <����� ����>
// 0~1�� ���ȿ� 1�� �۾��� ó���Ѵ�.���� �ð���[0, 2, 3] �̴�.
// 1~2�� ���� 2�� �۾��� ó���Ѵ�.���� �ð���[0, 1, 3] �̴�.
// 2~3�� ���� 3�� �۾��� ó���Ѵ�.���� �ð���[0, 1, 2] �̴�.
// 3~4�� ���� 2�� �۾��� ó���Ѵ�(1�� �۾��� �� ó���ߴ�).���� �ð���[0, 0, 2] �̴�.
// 4~5�� ���� 3�� �۾��� ó���Ѵ�.���� �ð���[0, 0, 1] �̴�.
// 5�� �� ������ ���������Ƿ� 3�� �۾��� �ؾ� �� �� �ߴܵǾ����Ƿ�, ���Ⱑ ���ƿ� �ķδ�
//  3�� �۾����� �����ϸ� �ȴ�.

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, K, i, pos = 0, sum = 0, res;

		scanf("%d", &N);
		int* a = new int[N];

		for (i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}

		scanf("%d", &K);

		if (sum <= K) {
			printf("-1\n");
		}
		else {
			while (0 < K) {
				if (a[pos] != 0) {
					a[pos]--;
					K--;
				}

				pos++;
				if (pos == N)	pos -= N;
				while (a[pos] == 0) {
					pos++;
					if (pos == N)	pos -= N;
				}
			}
			printf("%d\n", pos + 1);
		}
		delete a;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}