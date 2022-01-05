#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 45. ���� ���ϱ�(�����۽�)

// ���� �ձ��� �̿� ���� �ܵ��� ���ְ� ������ �������� ���������ϴ�.
// ���� �ձ����� ���ڰ� N���� �ִµ� ���� ���ָ� ���Ϸ� ���ڴٰ� �մϴ�.�����ձ��� ����
// ������ ���� ������� ���ָ� ���Ϸ� �� ���ڸ� �����ϱ�� �߽��ϴ�.
// ���� ���ڵ��� ���� ������ 1������ N������ ���ʷ� ��ȣ�� �ű��.�׸��� 1�� ���ں��� N
// �� ���ڱ��� ������� �ð� �������� ���ư��� ���׶��� �ɰ� �Ѵ�.�׸��� 1�� ���ں��� ��
// ��������� ���ư��� 1���� �����Ͽ� ��ȣ�� ��ġ�� �Ѵ�.�� ���ڰ� K(Ư������)�� ��ġ�� ��
// ���ڴ� ���ָ� ���Ϸ� ���µ��� ���ܵǰ� �� ������ ������ �ȴ�.�׸��� ���� ���ں��� �ٽ�
// 1���� �����Ͽ� ��ȣ�� ��ģ��.
// �̷��� �ؼ� ���������� ���� ���ڰ� ���ָ� ���Ϸ� �� �� �ִ�.

// ���� ��� �� 8���� ���ڰ� �ְ�, 3�� ��ģ ���ڰ� ���ܵȴٰ� ����.ó������ 3�� ���ڰ� 3
// �� ���� ���ܵȴ�.�̾� 6, 1, 5, 2, 8, 4�� ���ڰ� ���ʴ�� ���ܵǰ� ���������� ���� �� 7
// �� ���ڿ��� ���ָ� ���Ϸ����ϴ�.
// N�� K�� �־��� �� ���ָ� ���Ϸ� �� ������ ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է¼���
// ù �ٿ� �ڿ��� N(5<=N<=1,000)�� K(2<=K<=9)�� �־�����.

// ��¼���
// ù �ٿ� ������ ���� ������ ��ȣ�� ����մϴ�.

// ex1)
// input
// 8 3

// output
// 7

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, K, i, cnt, idx, tmp;

		scanf("%d %d", &N, &K);

		int* a = new int[N];
		for (i = 0; i < N; i++) {
			a[i] = i + 1;
		}

		cnt = N;
		idx = 0;
		tmp = K;

		while (1 < cnt) {
			if (a[idx] != 0) {
				tmp--;
				if (tmp == 0) {
					a[idx] = 0;
					cnt--;
					tmp = K;
				}
			}
			idx++;
			if (idx == N) {
				idx -= N;
			}
		}
		sort(a, a + N);

		printf("%d\n", a[N - 1]);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}