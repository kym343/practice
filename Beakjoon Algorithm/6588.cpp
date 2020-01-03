#include<iostream>
#include <algorithm>

using namespace std;

//https://www.acmicpc.net/problem/6588

bool* PrimeArray;
void Eratos(int n);

int main(int argc, char** argv) {
	freopen("sample_input.txt", "r", stdin);
	Eratos(1000000);

	while (1) {
		int num;
		int flag = 0;
		scanf("%d", &num);

		if (num == 0) {
			break;
		}
		else {
			for(int i = 3;i < num-1; i +=2){
				if(PrimeArray[i]){
					if (PrimeArray[num - i]) {
						printf("%d = %d + %d\n", num, i, num-i);
						flag++;
						break;
					}
					else {
						continue;
					}
				}
				else {
					continue;
				}
			}
			if (flag == 0) {
				printf("Goldbach's conjecture is wrong.\n");
			}
		}
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void Eratos(int n) {
	if (n <= 1) return;
	
	PrimeArray = new bool[n + 1];

	for (int i = 2; i <= n; i++) {
		PrimeArray[i] = true;
	}

	for (int i = 2; i*i <= n; i++) {
		if (PrimeArray[i]) {
			for (int j = i * i; j <= n; j += i) {
				PrimeArray[j] = false;
			}
		}
	}
}
