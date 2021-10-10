#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 103. �ִ� �� �����ϱ� 

// ������ ��ȣ�� �������� ��ȣ�� �ִ� �׸����� ���� ��ȣ���� ������ �����Ϸ��� �մϴ�.
// ���ʹ�ȣ�� ������ ���������� ���ʷ� 1���� N���� ������������ �����Ǿ� �ֽ��ϴ�.
// �������� ��ȣ ������ ������ �Ʒ� ������ �־����� ���� ���� ��ġ�� �ʰ� �ִ� �� ���� ��
// �� ������ �� �ִ� �� ���ϴ� ���α׷��� �ۼ��ϼ���.

// ���� �׸��� ������ ��ȣ ������ 4 1 2 3 9 7 5 6 10 8 �� �ԷµǾ��� �� ���� ���� ��ġ��
// �ʰ� ������ �� �ִ� �ִ� ���� ���� 6�� ���� ����Դϴ�.

// �Է¼���
// ù �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
// �� ��° �ٿ� 1���� N������ �ڿ��� N���� ������ ��ȣ ������ �־����ϴ�.������ ���ʹ�ȣ
// ���� �Ʒ��ʹ�ȣ �������Դϴ�.

// ��¼���
// ù �ٿ� ��ġ�� �ʰ� ���� �� �ִ� �ִ뼱�� ������ ����մϴ�.

// ex1)
// input
// 10
// 4 1 2 3 9 7 5 6 10 8

// output
// 6

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, cnt, res=0, maxx;

		cin >> N;

		vector<int> arr(N + 1), dy(N + 1);

		for (i = 1;i <= N;i++) {
			cin >> arr[i];
		}
		
		dy[1] = 1;
		for (i = 2;i <= N;i++) {
			maxx = 0;
			for (j = i - 1;j >= 1;j--) {
				if (arr[i] > arr[j] && maxx < dy[j]) maxx = dy[j];
			}
			dy[i] = maxx + 1;
			if (res < dy[i]) res = dy[i];
		}

		cout<<res<<endl;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}