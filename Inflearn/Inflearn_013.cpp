#include <iostream>
#include <algorithm>
#include <string>


#pragma warning(disable: 4996)

using namespace std;

// 13. 가장 많이 사용된 자릿수

// N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프
// 로그램을 작성하세요.
// 예를 들어 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니
// 다.답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요.

// 입력설명
// 첫 줄에 자연수가 입력됩니다. 자연수의 길이는 100을 넘지 않습니다.

// 출력설명
// 가장 많이 사용된 수를 출력합니다.

// ex1)
// input
// 1230565625

// output
// 5

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char N[101];

		scanf("%s", &N);
		/*printf("%s\n", N);*/

		int i = 0;

		int idx = strlen(N) - 1;
		/*printf("%d\n", idx);*/
		int a[10] = { 0 };
		int cnt = 0;
		int num = -1;

		int number = 0;

		while (idx >= 0) {									// for(i = 0; N[i]!='\0';i++){
			number = int(N[idx]) - '0'; // '0'는 48이다.	//		number = int(N[idx]) - '0';
			a[number]++;									//		a[number]++;
			if (a[number] > cnt) {							// }
				cnt = a[number];							// for(i = 0; i<=9; i++){}
				num = number;								//		if(a[i]>=cnt){
			}												//			cnt = a[i];
			else if (a[number] == cnt && number > num) {	//			rex=i;
				num = number;								// }
			}
			idx--;
		}

		printf("%d\n", num);
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}