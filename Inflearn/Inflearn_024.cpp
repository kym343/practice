#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 24. Jolly Jumpers 

// N개의 정수로 이루어진 수열에 대해 서로 인접해 있는 두 수의 차가 1에서 N-1까지의 값을
// 모두 가지면 그 수열을 유쾌한 점퍼(jolly jumper)라고 부른다.예를 들어 다음과 같은 수열에
// 서 1 4 2 3 앞 뒤에 있는 숫자 차의 절대 값이 각각 3, 2, 1이므로 이 수열은 유쾌한 점퍼가
// 된다.어떤 수열이 유쾌한 점퍼인지 판단할 수 있는 프로그램을 작성하라.

// 입력설명
// 첫 번째 줄에 자연수 N(3<=N<=100)이 주어진다.
// 그 다음 줄에 N개의 정수가 주어진다.정수의 크기는 int 형 범위안에 있습니다.

// 출력설명
// 유쾌한 점퍼이면 “YES"를 출력하고, 그렇지 않으면 ”NO"를 출력한다.

// ex1)
// input
// 5
// 1 4 2 3 7

// output
// YES

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;

		scanf("%d", &N);

		int* a = new int[N-1](); // vector<int> a(N);
		int pre, now, jumper, flag=0;
		scanf("%d", &pre); 

		for (int i = 0; i < N-1; i++) {
			scanf("%d", &now);

			jumper = abs(pre - now);
			if (jumper>0 && jumper<N && a[jumper - 1] == 0) {
				a[jumper - 1]++;
				pre = now;
			}
			else {
				flag = 1;
				// ##########################
				//printf("NO\n");
				//return 0;
				// ##########################
				break;
			}
		}
		if (flag == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}