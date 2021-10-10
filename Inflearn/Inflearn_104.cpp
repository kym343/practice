#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 104. ���� ���� ž �ױ�

// �ظ��� ���簢���� ������ü �������� ����Ͽ� ž�� �װ��� �Ѵ�. ž�� ������ �� ���� �Ʒ�
// ���� ���� �����鼭 ����� ����.�Ʒ��� ������ �����ϸ鼭 ���� ���� ž�� ���� �� �ִ� ��
// �α׷��� �ۼ��Ͻÿ�.

// (����1)������ ȸ����ų �� ����.��, ������ �ظ����� ����� �� ����.
// (����2)�ظ��� ���̰� ���� ������ ������, ���� ���԰� ���� ������ ����.
// (����3)�������� ���̴� ���� ���� �ִ�.
// (����4)ž�� ���� �� �ظ��� ���� ���� ���� �ظ��� ���� ������ ���� �� ����.
// (����5)���԰� ���ſ� ������ ���԰� ������ ���� ���� ���� �� ����.

// �Է¼���
// �Է� ������ ù° �ٿ��� �Էµ� ������ ���� �־�����. �Է����� �־����� ������ ���� �ִ�
// 100���̴�.��° �ٺ��ʹ� �� �ٿ� �� ���� ������ ���� ������ ���� �ظ��� ����, ������ ��
// �� �׸��� ���԰� ���ʴ�� ���� ������ �־�����.�� ������ �ԷµǴ� ������� 1���Ϳ�����
// �� ��ȣ�� ������.

// ��¼���
// ù ��° �ٿ� ���� ���� ���� �� �ִ� ž�� ���̸� ����Ѵ�.

// ex1)
// input
// 5
// 25 3 4
// 4 4 6
// 9 2 3
// 16 2 5
// 1 5 2

// output
// 10

struct Block {
	int s, h, w;
	Block(int a, int b, int c) {
		s = a;
		h = b;
		w = c;
	}
	bool operator < (const Block & b) const {
		return s > b.s;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, a, b, c, maxx, res;

		cin >> N;

		vector<Block> blk;
		for (i = 0; i < N;i++) {
			cin >> a >> b >> c;
			blk.push_back(Block(a, b, c));
		}

		sort(blk.begin(), blk.end());

		vector<int> dy(N); 
		dy[0] = blk[0].h;
		res = -2147000000;
		for (i = 1;i < N;i++) {
			maxx = 0;
			for (j = i - 1; j >= 0;j--) {
				if (blk[i].w < blk[j].w && maxx < dy[j]) maxx = dy[j];
			}
			dy[i] = maxx + blk[i].h;
			if (res < dy[i]) res = dy[i];
		}
		cout << res << endl;
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}