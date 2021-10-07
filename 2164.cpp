// 3244KB, 4ms

#include <cstdio>
#include <queue>

using namespace std;

queue<int> myq;

int main() {

	int n, curr;

	scanf("%d", &n);

	if (n == 1) {
		printf("%d", 1);
		return 0;
	}

	if (n == 2) {
		printf("%d", 2);
		return 0;
	}

	for (int i = 1; i <= n; i++) 
		myq.push(i);

	for (int i = 0; i < n - 3; i++) {
		myq.pop();
		curr = myq.front();

		myq.pop();
		myq.push(curr);
	}

	myq.pop();
	printf("%d", myq.front());

	return 0;

}
