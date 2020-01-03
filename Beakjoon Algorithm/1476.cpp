#include<iostream>
#include <algorithm>

using namespace std;

//https://www.acmicpc.net/problem/1476



int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int *ESM = new int[3]();// E <= 15, S <= 28 , M <= 19
		
		for (int i = 0; i < 3; i++) {
			scanf("%d", &ESM[i]);
		}

		if (ESM[0] == ESM[1] && ESM[1] == ESM[2]) {
			printf("%d\n", ESM[1]);
			continue;
		}
		else {
			int number = 16;

			while (1) {
				if (((number - 1) % 15 + 1) == ESM[0] && ((number - 1) % 28 + 1) == ESM[1] && ((number - 1) % 19 + 1) == ESM[2]) {
					printf("%d\n", number);
					break;
				}
				number++;
			}
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}