// 1124KB, 0ms

#include <cstdio>

using namespace std;

int costs[1003][3]; // R/G/B

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {

	int n, minval;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &costs[i][0], &costs[i][1], &costs[i][2]);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) {
				costs[i][j] += min(costs[i - 1][1], costs[i - 1][2]);
			}
			else if (j == 1) {
				costs[i][j] += min(costs[i - 1][0], costs[i - 1][2]);
			}
			else { // j == 2
				costs[i][j] += min(costs[i - 1][0], costs[i - 1][1]);
			}
		}
	}

	minval = min(costs[n - 1][0], costs[n - 1][1]);
	minval = min(minval, costs[n - 1][2]);

	printf("%d", minval);

	return 0;
}
