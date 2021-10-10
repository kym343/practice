#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 75. 최대 수입 스케쥴(priority_queue 응용문제)

// 현수는 유명한 강연자이다. N개이 기업에서 강연 요청을 해왔다. 각 기업은 D일 안에 와서 강
// 연을 해 주면 M만큼의 강연료를 주기로 했다.
// 각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
// 단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.

// 입력설명
// 첫 번째 줄에 자연수 N(1<=N<=10,000)이 주어지고, 다음 N개의 줄에 M(1<=M<=10,000)과
// D(1 <= D <= 10,000)가 차례로 주어진다.

// 출력설명
// 첫 번째 줄에 최대로 벌 수 있는 수입을 출력한다.

// ex1)
// input
// 6
// 50 2
// 20 1
// 40 2
// 60 3
// 30 3
// 30 1

// output
// 150

struct Data {
	int money;
	int day;

	Data(int x, int y) {
		money = x;
		day = y;
	}

	bool operator<(const Data& b)const {
		return day > b.day;
	}
};

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, M, D, maxx=-2147000000, sum=0;

		scanf("%d", &N);

		vector<Data> a;
		priority_queue<int> pQ;

		for (i = 0;i < N;i++) {
			scanf("%d %d", &M, &D);
			if (maxx < D) maxx = D;
			a.push_back(Data(M, D));
		}

		sort(a.begin(), a.end());

		j = 0;
		for (i = maxx; i >= 1;i--) {
			for ( ; j < N;j++) {
				if (a[j].day < i) break;
				pQ.push(a[j].money);
			}

			if (!pQ.empty()) {
				sum += pQ.top();
				pQ.pop();
			}
		}

		printf("%d\n", sum);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}