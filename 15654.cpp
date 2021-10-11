// 1116KB, 44ms

#include <cstdio>
#include <algorithm>

using namespace std;

void print(int* arr, int length) {
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int factorial(int n) {
	
	int ret = 1;

	for (int i = 2; i <= n; i++)
		ret *= i;

	return ret;
}

int main() {

	int n, m, fact;

	int arr[9];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	do {
		print(arr, m);

		fact = factorial(n - m) - 1;

		for (int i = 0; i < fact; i++)
			next_permutation(arr, arr + n);
	} while (next_permutation(arr, arr + n));

	return 0;
}
