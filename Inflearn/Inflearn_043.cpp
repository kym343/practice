#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 43. 뮤직비디오(이분검색 응용)

// 지니레코드에서는 불세출의 가수 조영필의 라이브 동영상을 DVD로 만들어 판매하려 한다.
// DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 라이브에서의 순서가 그대로 유지
// 되어야 한다.순서가 바뀌는 것을 우리의 가수 조영필씨가 매우 싫어한다.즉, 1번 노래와 5번
// 노래를 같은 DVD에 녹화하기 위해서는 1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야
// 한다.
// 지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에 이 사업에 낭비되는
// DVD를 가급적 줄이려고 한다.고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기
// 로 하였다.이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다.그리고 M개의 DVD는
// 모두 같은 크기여야 제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.

// 입력설명
// 첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다. 다음 줄에는 조영필이 라이브에서
// 부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다.부른 곡의 길이는 10,000분을
// 넘지 않는다고 가정하자.

// 출력설명
// 첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.

// ex1)
// input
// 9 3
// 1 2 3 4 5 6 7 8 9

// output
// 17

int N;
int a[1001];
int Count(int s) {
	int i, cnt = 1, sum = 0;
	for (i = 1; i <= N; i++) {
		if (sum + a[i] > s) {
			cnt++;
			sum = a[i];
		}
		else {
			sum += a[i];
		}
	}
	return cnt;
}

// 답을 정하고 좁혀나갈 때 유용 -> 이분검색 

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// =======================================================
		int M, i, left = 1, right = 0, mid, res, maxx = -2147000000;
		scanf("%d %d", &N, &M);

		//vector<int> a(N);

		for (i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
			right += a[i];
			if (a[i] > maxx) {
				maxx = a[i];
			}
		}

		while (left <= right) {
			mid = (left + right) / 2;
			if (mid >= maxx && Count(mid) <= M) {
				res = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		printf("%d\n", res);

		// =======================================================
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}