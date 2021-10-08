// 1200KB, 12ms

#include <cstdio>
#include <vector>

using namespace std;

int maps[54][54];
int nexts[54][54];

int main() {
	vector<int> ventil;
	int r, c, t;
	int spr, x1, x2, total = 0;

	scanf("%d %d %d", &r, &c, &t);

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			scanf("%d", &maps[i][j]);
			
			if (maps[i][j] == -1)
				ventil.push_back(i);
		}

	x2 = ventil.back();
	ventil.pop_back();
	x1 = ventil.back();
	ventil.pop_back();

	for (int i = 0; i <= r + 1; i++) {
		maps[i][0] = -1;
		maps[i][c + 1] = -1;
	}
	for (int i = 0; i < c + 1; i++){
		maps[0][i] = -1;
		maps[r + 1][i] = -1;
	}

	for (int i = 0; i <= r + 1; i++)
		for (int j = 0; j <= c + 1; j++)
			nexts[i][j] = maps[i][j];

	for (int k = 0; k < t; k++){
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				spr = maps[i][j] / 5;

				if (maps[i][j] >= 5) {
					if (maps[i - 1][j] != -1) {
						nexts[i - 1][j] += spr;
						nexts[i][j] -= spr;
					}
					if (maps[i + 1][j] != -1) {
						nexts[i + 1][j] += spr;
						nexts[i][j] -= spr;
					}
					if (maps[i][j - 1] != -1) {
						nexts[i][j - 1] += spr;
						nexts[i][j] -= spr;
					}
					if (maps[i][j + 1] != -1) {
						nexts[i][j + 1] += spr;
						nexts[i][j] -= spr;
					}
				}
			}
		//circulate

		//upper
		for (int i = x1 - 1; i >= 1; i--)
			nexts[i][1] = nexts[i - 1][1];
		for (int i = 1; i <= c - 1; i++)
			nexts[1][i] = nexts[1][i + 1];
		for (int i = 1; i <= x1 - 1; i++)
			nexts[i][c] = nexts[i + 1][c];
		for (int i = c; i >= 3; i--)
			nexts[x1][i] = nexts[x1][i - 1];
		nexts[x1][2] = 0;

		//lower
		for (int i = x2 + 1; i <= r - 1; i++)
			nexts[i][1] = nexts[i + 1][1];
		for (int i = 1; i <= c - 1; i++)
			nexts[r][i] = nexts[r][i + 1];
		for (int i = r; i >= x1 + 1; i--)
			nexts[i][c] = nexts[i - 1][c];
		for (int i = c; i >= 3; i--)
			nexts[x2][i] = nexts[x2][i - 1];
		nexts[x2][2] = 0;

		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				maps[i][j] = nexts[i][j];
	}

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			total += maps[i][j];
	total += 2;
	printf("%d", total);

	return 0;
}
