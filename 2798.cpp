// 1112KB, 0ms

#include <cstdio>

int main() {

	int n, m, sum, max = 0, cs[101];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &cs[i]);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++) {
				sum = cs[i] + cs[j] + cs[k];
				if (sum <= m && max < sum)
					max = sum;
			}

	printf("%d", max);

	return 0;
}
