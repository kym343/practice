#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 42. �̺а˻�

// ������ N���� ���ڰ� �Է����� �־����ϴ�. N���� ���� ������������ ������ ���� N���� ��
// �� �� ���� ���� M�� �־����� �̺а˻����� M�� ���ĵ� ���¿��� �� ��°�� �ִ��� ���ϴ�
// ���α׷��� �ۼ��ϼ���.

// �Է¼���
// ù �ٿ� �� �ٿ� �ڿ��� N(3<=N<=1,000,000)�� M�� �־����ϴ�.
// �� ��° �ٿ� N���� ���� ������ ���̿� �ΰ� �־����ϴ�.

// ��¼���
// ù �ٿ� ���� �� M�� ���� ��ġ ��ȣ�� ����Ѵ�.

// ex1)
// input
// 8 32
// 23 87 65 12 57 32 99 81

// output
// 3

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// ====================================
		//	int N, M, i;
		//	scanf("%d %d", &N, &M);
		//	
		//	vector<int> a(N);
		//	for(i=0;i<N;i++){
		//		scanf("%d", &a[i]);
		//	}
		//	
		//	
		//	sort(a.begin(), a.end());
		//	
		//	for(i=0;i<N;i++){
		//		if(a[i]==M){
		//			break;
		//		}
		//	}
		//	printf("%d\n",i+1);

		// ====================================
		int N, M, i, left, right, mid;
		scanf("%d %d", &N, &M);

		vector<int> a(N);
		for (i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}

		sort(a.begin(), a.end());

		left = 0;
		right = N - 1;

		while (left <= right) {
			mid = (left + right) / 2;
			if (a[mid] == M) {
				printf("%d\n", mid + 1);
				return 0;
			}
			else if (a[mid] > M) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		// ====================================
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}