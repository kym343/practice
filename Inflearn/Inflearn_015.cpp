#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 15. �Ҽ��� ����

// �ڿ��� N�� �ԷµǸ� 1���� N������ �Ҽ��� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
// ���� 20�� �ԷµǸ� 1���� 20������ �Ҽ��� 2, 3, 5, 7, 11, 13, 17, 19�� �� 8���Դϴ�.
// ���ѽð��� 1���Դϴ�.

// �Է¼���
// ù �ٿ� �ڿ����� ���� N(2<=N<=200,000)�� �־����ϴ�.

// ��¼���
// ù �ٿ� �Ҽ��� ������ ����մϴ�.

// ex1)
// input
// 20

// output
// 8

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;
		scanf("%d", &N);

		// ==========================================================
		// �Ƹ������׳׽��� ü
		bool num[200001];
		memset(num, true, sizeof(num)); // #include <cstring>

		int temp;
		for (int i = 2; i < N; i++) {
			if (num[i]) {
				for (int j = i+i; j <= N; j=j+i) {
					if(num[j]){
						num[j] = false;
					}
				}
			}
		}

		int cnt = 0;
		for (int i = 2; i <= N; i++) {
			if (num[i]) {
				cnt++;
			}
		}
		// ==========================================================
		// int i, j, flag, cnt=0;
		// for(i=2; i<=n; i++){
		// 		flag = 1;
		// 		for(j=2; j*j<=i; j++){  // WOW �Ҽ�Ȯ��: ��Ʈ ���� ������ Ȯ��
		//			if(i%j==0){
		//				flag=0;
		//				break;
		//			}
		//		}
		// 		// if(flag==1) cnt++;
		// }
		// ==========================================================
		printf("%d\n", cnt);
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}