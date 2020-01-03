#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int M; int N;

	freopen("sample_input.txt", "r", stdin);

	scanf("%d %d", &M, &N);

	int* prime = new int[max(M,N)-min(M,N)]();

	int pn = 0;

	bool* is_prime = new bool[max(M, N) + 1]();

	for (int i = 2; i <= max(M, N); i++) {
		is_prime[i] = true;
	}

	for (int i = 2; i <= max(M, N); i++) {
		if (is_prime[i] == true) {
			for (int j = i + i; j <= max(M, N); j += i) {
				is_prime[j] = false;
			}

			if (i >= min(M, N)) {
				prime[pn] = i;
				pn++;
			}
		}
	}

	for (int i = 0; i < pn; i++) {
		printf("%d\n", prime[i]);
	}


	return 0;
}