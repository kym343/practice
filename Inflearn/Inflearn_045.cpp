#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 45. 공주 구하기(조세퍼스)

// 정보 왕국의 이웃 나라 외동딸 공주가 숲속의 괴물에게 잡혀갔습니다.
// 정보 왕국에는 왕자가 N명이 있는데 서로 공주를 구하러 가겠다고 합니다.정보왕국의 왕은
// 다음과 같은 방법으로 공주를 구하러 갈 왕자를 결정하기로 했습니다.
// 왕은 왕자들을 나이 순으로 1번부터 N번까지 차례로 번호를 매긴다.그리고 1번 왕자부터 N
// 번 왕자까지 순서대로 시계 방향으로 돌아가며 동그랗게 앉게 한다.그리고 1번 왕자부터 시
// 계방향으로 돌아가며 1부터 시작하여 번호를 외치게 한다.한 왕자가 K(특정숫자)를 외치면 그
// 왕자는 공주를 구하러 가는데서 제외되고 원 밖으로 나오게 된다.그리고 다음 왕자부터 다시
// 1부터 시작하여 번호를 외친다.
// 이렇게 해서 마지막까지 남은 왕자가 공주를 구하러 갈 수 있다.

// 예를 들어 총 8명의 왕자가 있고, 3을 외친 왕자가 제외된다고 하자.처음에는 3번 왕자가 3
// 을 외쳐 제외된다.이어 6, 1, 5, 2, 8, 4번 왕자가 차례대로 제외되고 마지막까지 남게 된 7
// 번 왕자에게 공주를 구하러갑니다.
// N과 K가 주어질 때 공주를 구하러 갈 왕자의 번호를 출력하는 프로그램을 작성하시오.

// 입력설명
// 첫 줄에 자연수 N(5<=N<=1,000)과 K(2<=K<=9)가 주어진다.

// 출력설명
// 첫 줄에 마지막 남은 왕자의 번호를 출력합니다.

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


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}