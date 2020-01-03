/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = &apos;b&apos;;
// char var[256] = &quot;ABCDEFG&quot;;
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << &quot; &quot; << c;               // float 변수 2개 출력하는 예제
// cout << d << &quot; &quot; << e << &quot; &quot; << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

int partition(int *(&a), int left, int right);
void quick_sort(int *(&a), int left, int right);

int main(int argc, char** argv){
	int test_case;
	int T;
	/*
	아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	//여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case) {
		int P;
		
		//printf("%d\n", test_case);

		scanf("%d", &P);
		//printf("%d\n", P);

		int *arr = new int[P]();

		for (int i = 0; i < P; i++){
			scanf("%d", &arr[i]);
			//printf("%d\n", arr[i]);
		}
		

		// Sort
		// 1이면 제곱
		// 2이면 둘이 곱
		// 3이면 1,3 곱 or 가운데 제곱
		// 4이상 최소 * 최대

		// Order of n 
		// quick sort가 O( n*log(n) )
		int result = 0;
		printf("#%d ", test_case);
		if (P == 1) {
			// 1개 제곱
			result = arr[0] * arr[0];
			printf("%d\n", result);
		}
		else if (P == 2) {
			// 두개 곱
			result = arr[0] * arr[1];
			printf("%d\n", result);
		}
		else if (P == 3) {
			// sort 후 가운데 제곱
			int end = P - 1;

			quick_sort(arr, 0, end);
			result = arr[1] * arr[1];
			printf("%d\n", result);
		}
		else {
			// sort 후 처음과 마지막 곱
			int end = P - 1;

			quick_sort(arr, 0, end);
			result = arr[0] * arr[end];
			printf("%d\n", result);
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int partition(int *(&a), int left, int right) {
	int pivot = right;
	int i = left - 1;
	int j = left;
	int tmp;

	if (left < right) {
		while (j < right) {
			if (a[j] < a[pivot]) {
				tmp = a[j];
				a[j] = a[i + 1];
				a[i + 1] = tmp;
				i++;
			}
			j++;
		}
		tmp = a[pivot];
		a[pivot] = a[i + 1];
		a[i + 1] = tmp;
	}
	pivot = i + 1;

	return pivot;
}

void quick_sort(int *(&a), int left, int right) {
	if (left < right) {
		int pivot = partition(a, left, right);
		quick_sort(a, left, pivot - 1);
		quick_sort(a, pivot + 1, right);
	}
}