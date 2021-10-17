// 2104KB, 40ms

#include <cstdio>
#include <queue>

using namespace std;

// WSEN
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

int maps[503][503];
int n, xpos, ypos;

void spread(int x, int y, int dir) {

	int scurr = maps[x + dx[dir]][y + dy[dir]];
	int notmoved = scurr;

	if (dir == 0 || dir == 2) {

		maps[x + 1][y] += scurr / 100;
		maps[x - 1][y] += scurr / 100;
		notmoved -= scurr / 100;
		notmoved -= scurr / 100;
		
		maps[x + 1][y + dy[dir]] += scurr * 7 / 100;
		maps[x - 1][y + dy[dir]] += scurr * 7 / 100;
		notmoved -= scurr * 7 / 100;
		notmoved -= scurr * 7 / 100;

		maps[x + 2][y + dy[dir]] += scurr / 50;
		maps[x - 2][y + dy[dir]] += scurr / 50;
		notmoved -= scurr / 50;
		notmoved -= scurr / 50;

		maps[x + 1][y + dy[dir] * 2] += scurr / 10;
		maps[x - 1][y + dy[dir] * 2] += scurr / 10;
		notmoved -= scurr / 10;
		notmoved -= scurr / 10;

		maps[x][y + dy[dir] * 3] += scurr / 20;
		notmoved -= scurr / 20;

		maps[x][y + dy[dir] * 2] += notmoved;
	}

	if (dir == 1 || dir == 3) {

		maps[x][y + 1] += scurr / 100;
		maps[x][y - 1] += scurr / 100;
		notmoved -= scurr / 100;
		notmoved -= scurr / 100;

		maps[x + dx[dir]][y + 1] += scurr * 7 / 100;
		maps[x + dx[dir]][y - 1] += scurr * 7 / 100;
		notmoved -= scurr * 7 / 100;
		notmoved -= scurr * 7 / 100;

		maps[x + dx[dir]][y + 2] += scurr / 50;
		maps[x + dx[dir]][y - 2] += scurr / 50;
		notmoved -= scurr / 50;
		notmoved -= scurr / 50;

		maps[x + dx[dir] * 2][y + 1] += scurr / 10;
		maps[x + dx[dir] * 2][y - 1] += scurr / 10;
		notmoved -= scurr / 10;
		notmoved -= scurr / 10;

		maps[x + dx[dir] * 3][y] += scurr / 20;
		notmoved -= scurr / 20;

		maps[x + dx[dir] * 2][y] += notmoved;
	}

	maps[x + dx[dir]][y + dy[dir]] = 0;
	return;
}

void torn() {

	int len = 1;
	while (len < n) {

		int dir;
		for (dir = 0; dir < 2; dir++)
		{
			for (int i = 1; i <= len; i++)
			{
				spread(xpos, ypos, dir);
				xpos = xpos + dx[dir];
				ypos = ypos + dy[dir];
			}
		}
		len++;

		for (dir = 2; dir < 4; dir++)
		{
			for (int i = 1; i <= len; i++)
			{
				spread(xpos, ypos, dir);
				xpos = xpos + dx[dir];
				ypos = ypos + dy[dir];
			}
		}
		len++;
	}

	for (int i = 1; i < n; i++)
	{
		spread(xpos, ypos, 0);
		xpos = xpos + dx[0];
		ypos = ypos + dy[0];
	}

	return;
}

int sum() {
	int s = 0;
	int n2 = n + 2;
	int n4 = n + 4;

	for (int i = 0; i < n2; i++) {
		s += maps[0][i];
	}
	for (int i = 0; i < n2; i++) {
		s += maps[1][i];
	}
	for (int i = 0; i < n2; i++) {
		s += maps[i][n + 2];
	}
	for (int i = 0; i < n2; i++) {
		s += maps[i][n + 3];
	}
	for (int i = 2; i < n4; i++) {
		s += maps[i][0];
	}
	for (int i = 2; i < n4; i++) {
		s += maps[i][1];
	}
	for (int i = 2; i < n4; i++) {
		s += maps[n + 2][i];
	}
	for (int i = 2; i < n4; i++) {
		s += maps[n + 3][i];
	}

	return s;
}

int main() {

	int ans;

	scanf("%d", &n);

	for (int i = 2; i < n + 2; i++)
	{
		for (int j = 2; j < n + 2; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}

	xpos = ypos = (n / 2) + 2;

	torn();

	ans = sum();

	printf("%d", ans);

	return 0;
}
