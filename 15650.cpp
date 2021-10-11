// 1112KB, 0ms

#include <cstdio>

using namespace std;

void print(int* arr, int length) {
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i] + 1);
	printf("\n");
}

void combination(int* arr, int index, int n, int r, int target) {
	if (r == 0)
		print(arr, index);
	else if (target == n)
		return;
	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1);
		combination(arr, index, n, r, target + 1);
	}
}

int main() {

	int n, m;

	int arr[9];

	scanf("%d %d", &n, &m);

	combination(arr, 0, n, m, 0);

	return 0;
}
