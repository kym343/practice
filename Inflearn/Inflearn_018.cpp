#include <iostream>
#include <algorithm>

using namespace std;

// 18. 층간소음

// T편한 세상 아파트는 층간소음 발생 시 윗집의 발뺌을 방지하기 위해 애초 아파트를 지을 때
// 바닥에 진동센서를 설치했습니다.이 센서는 각 세대의 층간 진동소음 측정치를 초단위로 아
// 파트 관리실에 실시간으로 전송합니다.그리고 한 세대의 측정치가 M값을 넘으면 세대호수와
// 작은 경보음이 관리실 모니터에서 울립니다.한 세대의 N초 동안의 실시간 측정치가 주어지면
// 최대 연속으로 경보음이 울린 시간을 구하세요.경보음이 없으면 - 1를 출력합니다.

// 입력설명
// 첫 줄에 자연수 N(10<=N<=100)과 M이 주어집니다.
// 두 번째 줄에 N개의 측정값(1000이하 자연수)이 초 순서대로 입력된다.

// 출력설명
// 최대 연속 경보음이 울린 시간(초)를 출력하세요.

// ex1)
// input
// 10 90
// 23 17 120 34 112 136 123 23 25 113

// output
// 3

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, M;

		scanf("%d %d", &N, &M);

		int max = 0;
		int cnt = 0;
		int num;
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);

			if (num > M) {
				cnt++;
				if (cnt > max) {
					max = cnt;
				}
			}
			else {
				cnt = 0;
			}
		}
		if (max == 0) { max = -1;}
		printf("%d\n", max);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}