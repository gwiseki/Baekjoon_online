// 19848KB, 488ms

#include <cstdio>
#include <string>

int paper[2190][2190];
int sum[3] = { 0, };

void search(int n, int x, int y) {
	int val = paper[x][y];

	if (n < 3) {
		if (val == -1)
			sum[0] ++;
		else if (val == 0)
			sum[1] ++;
		else // val == 1
			sum[2] ++;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (val != paper[x + i][y + j]) {
					int tn = n / 3;

					for (int a = 0; a < 3; a++)
					{
						for (int b = 0; b < 3; b++)
						{
							search(tn, x + tn * a, y + tn * b);
						}
					}
					return;
				}
			}
		}
		if (val == -1)
			sum[0] ++;
		else if (val == 0)
			sum[1] ++;
		else // val == 1
			sum[2] ++;
	}
	return;
}

int main() {

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}

	sum[0] = sum[1] = sum[2] = 0;

	search(n, 0, 0);

	printf("%d\n%d\n%d", sum[0], sum[1], sum[2]);

	return 0;
}
