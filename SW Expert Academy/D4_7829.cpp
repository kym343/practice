/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = &apos;b&apos;;
// char var[256] = &quot;ABCDEFG&quot;;
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << &quot; &quot; << c;               // float ���� 2�� ����ϴ� ����
// cout << d << &quot; &quot; << e << &quot; &quot; << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

int partition(int *(&a), int left, int right);
void quick_sort(int *(&a), int left, int right);

int main(int argc, char** argv){
	int test_case;
	int T;
	/*
	�Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	//�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
		// 1�̸� ����
		// 2�̸� ���� ��
		// 3�̸� 1,3 �� or ��� ����
		// 4�̻� �ּ� * �ִ�

		// Order of n 
		// quick sort�� O( n*log(n) )
		int result = 0;
		printf("#%d ", test_case);
		if (P == 1) {
			// 1�� ����
			result = arr[0] * arr[0];
			printf("%d\n", result);
		}
		else if (P == 2) {
			// �ΰ� ��
			result = arr[0] * arr[1];
			printf("%d\n", result);
		}
		else if (P == 3) {
			// sort �� ��� ����
			int end = P - 1;

			quick_sort(arr, 0, end);
			result = arr[1] * arr[1];
			printf("%d\n", result);
		}
		else {
			// sort �� ó���� ������ ��
			int end = P - 1;

			quick_sort(arr, 0, end);
			result = arr[0] * arr[end];
			printf("%d\n", result);
		}

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
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