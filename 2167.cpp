#include <cstdio>

using namespace std;

int maps[302][302];

int main() {

	int n, m, k, x1, x2, y1, y2, sum;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &maps[i][j]);

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		sum = 0;
		for (int a = x1; a <= x2; a++)
			for (int b = y1; b <= y2; b++)
				sum += maps[a][b];

		printf("%d\n", sum);
	}

	return 0;
}
