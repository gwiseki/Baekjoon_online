// 1500KB, 20ms

#define MAX 100005
#include <cstdio>

using namespace std;

int myh[MAX], idx = 1;
int maxi = (1 << 31) - 1;

void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(int curr) {

	int curidx = idx;

	myh[idx++] = curr;

	while (curidx > 1)
		if (myh[curidx] < myh[curidx / 2]) {
			swap(&myh[curidx], &myh[curidx / 2]);
			curidx /= 2;
		}
		else
			break;

}

int pop() {

	if (idx == 1)
		return 0;

	int val = myh[1];
	int curidx = 1;

	myh[1] = maxi;
	swap(&myh[1], &myh[idx - 1]);

	while (curidx * 2 < idx) {
		if (myh[curidx] < myh[curidx * 2] && myh[curidx] < myh[curidx * 2 + 1])
			break;

		if (myh[curidx * 2] < myh[curidx * 2 + 1]) {
			swap(&myh[curidx * 2], &myh[curidx]);
			curidx = curidx * 2;
		}
		else {
			swap(&myh[curidx * 2 + 1], &myh[curidx]);
			curidx = curidx * 2 + 1;
		}

	}
	idx--;
	return val;
}

int main() {

	int n, curr;

	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
		myh[i] = maxi;

	for (int i = 0; i < n; i++){
		scanf("%d", &curr);

		if (!curr)
			printf("%d\n", pop());
		else
			push(curr);
	}

	return 0;
}
