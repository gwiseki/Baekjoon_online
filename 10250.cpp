// 1112KB, 0ms

#include <cstdio>

using namespace std;

int main() {

	int T, h, w, n;
	int floor, number;

	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {

		scanf("%d %d %d", &h, &w, &n);

		if (n % h)
			floor = n % h;
		else
			floor = h;
		number = (n - 1) / h + 1;

			printf("%d\n", floor*100 + number);
	}

	return 0;
}
