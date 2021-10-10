#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 108. 최대점수 구하기(냅색 알고리즘)

// 이번 정보올림피아드대회에서 좋은 성적을 내기 위하여 현수는 선생님이 주신 N개의 문제를
// 풀려고 합니다.각 문제는 그것을 풀었을 때 얻는 점수와 푸는데 걸리는 시간이 주어지게 됩
// 니다.제한시간 M안에 N개의 문제 중 최대점수를 얻을 수 있도록 해야 합니다. (해당문제는
// 	해당시간이 걸리면 푸는 걸로 간주한다, 한 유형당 한개만 풀 수 있습니다.)

// 입력설명
// 첫 번째 줄에 문제의 개수N(1<=N<=100)과 제한 시간 M(10<=M<=1000)이 주어집니다.
// 두 번째 줄부터 N줄에 걸쳐 문제를 풀었을 때의 점수와 푸는데 걸리는 시간이 주어집니다.

// 출력설명
// 첫 번째 줄에 제한 시간안에 얻을 수 있는 최대 점수를 출력합니다.

// ex1)
// input
// 5 20
// 10 5
// 25 12
// 15 8
// 6 3
// 7 4

// output
// 41

//  // ============== struct 추가 ==============
//struct problem {
//	int s, t;
//	problem(int a, int b) {
//		s = a;
//		t = b;
//	}
//	bool operator<(const problem& b) const {
//		return t < b.t;
//	}
//};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, T, i, j, w, v;

		cin >> N >> T;

		vector<int> dy(T + 1, 0);

		// ===================== 1D 방법 =====================
		for (i = 1;i <= N;i++) {
			cin >> w >> v;
			for (j = T;j >= v;j--) { // 중복을 없애기 위해(1번씩만 문제를 풀기위해) 뒤에서부터!!
				if (j >= v) dy[j] = max(dy[j], dy[j - v] + w);
			}
		}

		// ===================== 2D 방법 =====================
		//vector<vector<int> > dy(N + 1, vector<int>(T + 1, 0));
		//vector<problem> prob;
		//for (i = 1;i <= N;i++) {
		//	cin >> w >> v;
		// 
		//  // ============== struct 추가 ==============
		//	//	prob.push_back(problem(w, v));
		//	//}
		//	//sort(prob.begin(), prob.end());

		//	//for (i = 1;i <= N;i++) {
		//	//	w = prob[i - 1].s;
		//	//	v = prob[i - 1].t;
		//	for (j = 1;j <= T;j--) {
		//		if (j >= v) dy[i][j] = max(dy[i - 1][j], dy[i - 1][j - v] + w);
		//		else dy[i][j] = dy[i - 1][j];
		//	}
		//}


		cout << dy[T] << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}