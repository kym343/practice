#include<iostream>
#include <algorithm>
#include <string>
// #include<stdio.h>

using namespace std;

// 5. 나이계산


// 주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하여 출력하는 프로그램
// 을 작성하세요.주민등록증의 번호는 - 를 기준으로 앞자리와 뒷자리로 구분된다.
// 뒷자리의 첫 번째 수가 1이면 1900년대생 남자이고, 2이면 1900년대생 여자, 3이면 2000년대
// 생 남자, 4이면 2000년대생 여자이다.
// 올해는 2019년입니다.해당 주민등록증 주인의 나이와 성별을 출력하세요.

// 입력설명
// 첫 줄에 주민등록증 번호가 입력됩니다.

// 출력설명
// 첫 줄에 나이와 성별을 공백을 구분으로 출력하세요. 성별은 남자는 M(man), 여자는 W(Woman)로 출력한다.

// ex1)
// input
// 780316-2376152

// output
// 42 W

// ex2)
// input
// 061102-3575393

// output
// 14 M

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		char number[15];
		scanf("%s", &number);

		char YY[] = "";
		YY[0] = number[0];
		YY[1] = number[1];
		YY[2] = '\0';

		string text = "";

		if (int(number[7])-'0' < 3) {					// if(number[7]=='1' || number[7]=='2')
			text.append(to_string(119 - atoi(YY) + 1)); //	int age = 119 - (number[0] - '0') *10 + number[1] - '0'
		}
		else {
			text.append(to_string(19 - atoi(YY) + 1));
		}
														// printf("%d ", age)

		if (int(number[7]) % 2 == 1) {					// if(number[7]=='1' || number[7]=='3')
			text += " M";                               //	printf("M\n");
		}												// else printf("W\n);
		else {
			text += " W";
		}

		printf("%s\n", text.c_str());
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}