// 1112KB, 0ms

#include <cstdio>

char maps[51][51];

int main() {

	int n, m, count, min = 2501;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", maps[i]);

	for (int x = 0; x <= n - 8; x++)
		for (int y = 0; y <= m - 8; y++) {

			count = 0;
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++) {
					
					//left up == W
					if ((i + j) % 2 == 0)
						if (maps[i + x][j + y] == 'B')
							count++;

					if ((i + j) % 2 == 1)
						if (maps[i + x][j + y] == 'W')
							count++;
				}

			if (min > count)
				min = count;

			count = 0;
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++) {

					//left up == B
					if ((i + j) % 2 == 0)
						if (maps[i + x][j + y] == 'W')
							count++;

					if ((i + j) % 2 == 1)
						if (maps[i + x][j + y] == 'B')
							count++;
				}

			if (min > count)
				min = count;
		}

	printf("%d", min);

	return 0;
}
