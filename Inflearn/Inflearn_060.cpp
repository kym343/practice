#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 60. 합이 같은 부분집합(DFS : 아마존 인터뷰)

// N개의 원소로 구성된 자연수 집합이 주어지면, 이 집합을 두 개의 부분집합으로 나누었을 때
// 두 부분집합의 원소의 합이 서로 같은 경우가 존재하면 “YES"를 출력하고, 그렇지 않으면
// ”NO"를 출력하는 프로그램을 작성하세요.
// 예를 들어{ 1, 3, 5, 6, 7, 10 }이 입력되면{ 1, 3, 5, 7 } = { 6, 10 } 으로 두 부분집합의 합이
// 16으로 같은 경우가 존재하는 것을 알 수 있다.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=10)이 주어집니다.
// 두 번째 줄에 집합의 원소 N개가 주어진다.각 원소는 중복되지 않는다.

// 출력설명
// 첫 번째 줄에 “YES" 또는 ”NO"를 출력한다.

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


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}