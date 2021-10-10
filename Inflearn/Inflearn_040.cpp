#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 40. 교집합(투포인터 알고리즘)

// 두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하세요.

// 입력설명
// 첫 번째 줄에 집합 A의 크기 N(1<=N<=30,000)이 주어집니다.
// 두 번째 줄에 N개의 원소가 주어집니다.원소가 중복되어 주어지지 않습니다.
// 세 번째 줄에 집합 B의 크기 M(1 <= M <= 30, 000)이 주어집니다.
// 네 번째 줄에 M개의 원소가 주어집니다.원소가 중복되어 주어지지 않습니다.
// 각 집합의 원소는 int형 변수의 크기를 넘지 않습니다.

// 출력설명
// 두 집합의 교집합을 오름차순 정렬하여 출력합니다.

// ex1)
// input
// 5
// 2 7 10 5 3
// 5
// 3 10 5 17 12

// output
// 3 5 10

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M, i, j, pos1=0, pos2=0, pos3=0, tmp;
		// ##############################################
		//scanf("%d", &N);
		//
		//int* a = new int[N]();
		//for (i = 0;i < N;i++) {
		//	scanf("%d", &a[i]);
		//}

		//scanf("%d", &M);
		//int* b = new int[M]();
		//for (i = 0;i < M;i++) {
		//	scanf("%d", &b[i]);
		//}

		//int* c;
		//if (N <= M) {
		//	c = new int[N]();
		//}
		//else {
		//	c = new int[M]();
		//}

		//for (i = 1;i < N;i++) {
		//	tmp = a[i];
		//	for (j = i - 1;j >= 0;j--) {
		//		if (a[j] > tmp) {
		//			a[j + 1] = a[j];
		//		}
		//		else break;
		//	}
		//	a[j + 1] = tmp;
		//}

		//for (i = 1;i < M;i++) {
		//	tmp = b[i];
		//	for (j = i - 1;j >= 0;j--) {
		//		if (b[j] > tmp) {
		//			b[j + 1] = b[j];
		//		}
		//		else break;
		//	}
		//	b[j + 1] = tmp;
		//}

		//while (pos1 < N && pos2 < M) {
		//	if (a[pos1] == b[pos2]) {
		//		c[pos3++] = a[pos1++];
		//		pos2++;
		//	}
		//	else if (a[pos1] < b[pos2]) {
		//		pos1++;
		//	}
		//	else pos2++;		
		//}

		//for (i = 0;i < pos3;i++) {
		//	printf("%d ", c[i]);
		//}
		// ##############################################
		scanf("%d", &N);
		vector<int> a(N); // int* a = new int[N]();
		for (i = 0;i < N;i++) {
			scanf("%d", &a[i]);
		}
		sort(a.begin(), a.end()); // 와! 제공하는 sort 함수!

		scanf("%d", &M);
		vector<int> b(M), c(N+M);
		for (i = 0;i < M;i++) {
			scanf("%d", &b[i]);
		}
		sort(b.begin(), b.end()); // 와! 제공하는 sort 함수!

		while (pos1 < N && pos2 < M) {
			if (a[pos1] == b[pos2]) {
				c[pos3++] = a[pos1++];
				pos2++;
			}
			else if (a[pos1] < b[pos2]) {
				pos1++;
			}
			else pos2++;
		}

		for (i = 0;i < pos3;i++) {
			printf("%d ", c[i]);
		}

		// ##############################################
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}