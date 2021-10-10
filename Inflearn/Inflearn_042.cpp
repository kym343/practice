#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 42. 이분검색

// 임의의 N개의 숫자가 입력으로 주어집니다. N개의 수를 오름차순으로 정렬한 다음 N개의 수
// 중 한 개의 수인 M이 주어지면 이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하는
// 프로그램을 작성하세요.

// 입력설명
// 첫 줄에 한 줄에 자연수 N(3<=N<=1,000,000)과 M이 주어집니다.
// 두 번째 줄에 N개의 수가 공백을 사이에 두고 주어집니다.

// 출력설명
// 첫 줄에 정렬 후 M의 값의 위치 번호를 출력한다.

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


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}