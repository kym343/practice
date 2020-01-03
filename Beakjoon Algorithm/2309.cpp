#include<iostream>
#include <algorithm>

using namespace std;

//https://www.acmicpc.net/problem/2309

#define num_of_people 9

int partition(int *(&a), int left, int right);
void quick_sort(int *(&a), int left, int right);

int main(int argc, char** argv) {
	freopen("sample_input.txt", "r", stdin);

	int *arr = new int[num_of_people]();
	bool* true_man = new bool[num_of_people]();

	int total_sum = 0;

	for (int i = 0; i < num_of_people; i++) {
		scanf("%d", &arr[i]);
		true_man[i] = true;
		total_sum += arr[i];
	}

	int end = num_of_people - 1;
	quick_sort(arr, 0, end);

	int sub = total_sum - 100;

	int i = 0;
	int j = 1;
	while (i < num_of_people) {
		if (sub == (arr[i] + arr[j])) {
			true_man[i] = false;
			true_man[j] = false;
			break;
		}
		else {
			j++;
			if (j % num_of_people == 0) {
				j = 0;
				i++;
			}
		}		
	}

	for (int i = 0; i < num_of_people; i++) {
		if (true_man[i]) {
			printf("%d\n", arr[i]);
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