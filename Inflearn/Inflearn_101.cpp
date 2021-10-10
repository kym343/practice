#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 101. 동적계획법이란? 네트워크 선 자르기(Bottom-Up)

// 현수는 네트워크 선을 1m, 2m의 길이를 갖는 선으로 자르려고 합니다.
// 예를 들어 4m의 네트워크 선이 주어진다면

// 1) 1m + 1m + 1m + 1m
// 2) 2m + 1m + 1m
// 3) 1m + 2m + 1m
// 4) 1m + 1m + 2m
// 5) 2m + 2m

// 의 5가지 방법을 생각할 수 있습니다. (2)와 (3)과 (4)의 경우 왼쪽을 기준으로 자르는 위치가
// 다르면 다른 경우로 생각한다.
// 그렇다면 네트워크 선의 길이가 Nm라면 몇 가지의 자르는 방법을 생각할 수 있나요 ?

// 입력설명
// 첫째 줄은 네트워크 선의 총 길이인 자연수 N(3≤N≤45)이 주어집니다.

// 출력설명
// 첫 번째 줄에 부분증가수열의 최대 길이를 출력한다.

// ex1)
// input
// 7

// output
// 21

int N, res;

int dy[50];

int DFS(int L) {
	if (dy[L] != 0) return dy[L];
	if (L == 1 || L == 2) return L;
	else return dy[L] = DFS(L - 2) + DFS(L - 1);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int i, j;

		cin >> N;

		// ########## Bottom-Up ##########
		//dy[1] = 1;
		//dy[2] = 2;
		//for (i = 3;i<= N; i++) {
		//	dy[i] = dy[i - 2] + dy[i - 1];
		//}

		//cout << dy[N];

		// ###############################

		// ########## Top-Down ###########
		
		cout << DFS(N) << endl;

		// ###############################

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}