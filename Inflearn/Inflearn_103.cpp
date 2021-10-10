#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 103. 최대 선 연결하기 

// 왼쪽의 번호와 오른쪽의 번호가 있는 그림에서 같은 번호끼리 선으로 연결하려고 합니다.
// 왼쪽번호는 무조건 위에서부터 차례로 1부터 N까지 오름차순으로 나열되어 있습니다.
// 오른쪽의 번호 정보가 위부터 아래 순서로 주어지만 서로 선이 겹치지 않고 최대 몇 개의 선
// 을 연결할 수 있는 지 구하는 프로그램을 작성하세요.

// 위의 그림은 오른쪽 번호 정보가 4 1 2 3 9 7 5 6 10 8 로 입력되었을 때 선이 서로 겹치지
// 않고 연결할 수 있는 최대 선을 개수 6을 구한 경우입니다.

// 입력설명
// 첫 줄에 자연수 N(1<=N<=100)이 주어집니다.
// 두 번째 줄에 1부터 N까지의 자연수 N개의 오른쪽 번호 정보가 주어집니다.순서는 위쪽번호
// 부터 아래쪽번호 순으로입니다.

// 출력설명
// 첫 줄에 겹치지 않고 그을 수 있는 최대선의 개수를 출력합니다.

// ex1)
// input
// 10
// 4 1 2 3 9 7 5 6 10 8

// output
// 6

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, i, j, cnt, res=0, maxx;

		cin >> N;

		vector<int> arr(N + 1), dy(N + 1);

		for (i = 1;i <= N;i++) {
			cin >> arr[i];
		}
		
		dy[1] = 1;
		for (i = 2;i <= N;i++) {
			maxx = 0;
			for (j = i - 1;j >= 1;j--) {
				if (arr[i] > arr[j] && maxx < dy[j]) maxx = dy[j];
			}
			dy[i] = maxx + 1;
			if (res < dy[i]) res = dy[i];
		}

		cout<<res<<endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}