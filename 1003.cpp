#include <cstdio>

using namespace std;

int memo[40][2];

int main() {

	int n, T;

	scanf("%d", &T);

	memo[0][0] = 1;
	memo[0][1] = 0;
	memo[1][0] = 0;
	memo[1][1] = 1;
	memo[2][0] = 1;
	memo[2][1] = 1;

	for (int i = 3; i <= 40; i++) {
		memo[i][0] = memo[i - 1][0] + memo[i - 2][0];
		memo[i][1] = memo[i - 1][1] + memo[i - 2][1];
	}

	for (int tc = 0; tc < T; tc++){
		scanf("%d", &n);

		printf("%d %d\n", memo[n][0], memo[n][1]);
	}

	return 0;
}
