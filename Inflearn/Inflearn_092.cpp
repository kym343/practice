#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// [�������] STL map �ڷᱸ�� Ȱ��

// map�� �̿��ؼ� ���� ���ĺ� �� �� ���

// ex1)
// input
// abcdeaabbcccc

// output
// a : 3
// b : 3
// c : 5
// d : 1
// e : 1

// map�� �̿��ؼ� ���� ���� �ܾ� �� �� ���

// ex1)
// input
// 7
// book
// dog
// cat
// dog
// cat
// book
// cat

// output
// a : 3
// b : 3
// c : 5
// d : 1
// e : 1

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		// =================== 1 ========================
		//char a[100];

		//scanf("%s", &a);

		//map<char, int> ch;
		//map<char, int>::iterator it;

		//for (int i = 0; a[i] != '\0'; i++) ch[a[i]]++;
		//for (it = ch.begin(); it != ch.end(); it++) {
		//	printf("%c : %d\n", it->first, it->second);
		//}
		// ==============================================

		// =================== 2 ========================
		char a[100];
		map<string, int> ch;
		map<string, int>::iterator it;

		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%s", &a);
			ch[a]++;
		}
		
		for (it = ch.begin(); it != ch.end(); it++) {
			cout << it->first << " : " << it->second << "\n";

			// cin/cout�� char*�� C++ string �� �� ó���� �� �ִ� �ݸ�
			// scanf/printf�δ� C++ string�� ó���� �� ����!
			
			//printf("%s : %d\n", it->first, it->second); 
		// ==============================================
	}


	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}