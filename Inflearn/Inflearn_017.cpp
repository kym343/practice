#include <iostream>
#include <algorithm>

using namespace std;

// 17. 선생님 퀴즈

// 현수네 반은 학생이 N명 있습니다. 수업도중 선생님이 잠깐 자리를 비워야 하는데 그 동안 학
// 생들이 떠들거나 놀지 않도록 각 학생들에게 퀴즈를 냈습니다.
// 선생님은 각 학생들에게 숫자가 적힌 카드를 줬습니다.각 학생들은 1부터 자기 카드에 적힌
// 숫자까지의 합을 구하는 퀴즈입니다.
// 선생님이 돌아와서 각 학생들의 답이 맞았는지 확인을 하려고 하는데 너무 힘들어서 여러분에
// 게 자동으로 채점을 하는 프로그램을 부탁했습니다.여러분이 선생님을 도와주세요.

// 입력설명
// 첫 줄에 반 학생수인 자연수 N(1<=N<=10)이 주어집니다.
// 각 학생들은 1부터 N까지 번호가 부여되어 있다고 가정합니다.
// 두 번째 줄부터 1번 학생부터의 카드에 적힌 수와 학생이 구한 정답이 공백을 사이에 두고
// 입력된다.카드에 적힌 수는 1000을 넘지 않는다.

// 출력설명
// 첫 줄부터 1번 학생이 정답을 맞추면 “YES", 틀리면 ”NO"를 출력하세요.

// ex1)
// input
// 3
// 10 55
// 20 350
// 100 5050

// output
// YES
// NO
// YES

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N, ans;
		scanf("%d", &N);
		scanf("%d", &ans);

		int tmp = N*(N + 1) / 2;

		if(tmp == ans){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		

	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}