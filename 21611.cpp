// 1156KB, 12ms
#include <cstdio>

using namespace std;

// NSWE
int dxb[5] = { 100, -1, 1, 0, 0 };
int dyb[5] = { 100, 0, 0, -1, 1 };

// loop -> WSEN
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int n, m, n2;
int maps[51][51], cpy[51][51], magics[101][2];
int ans[4] = { 0, };
int numbers[2500][2]; // 0 ~ n^2 - 1 (0:shark)

void numbering() {

	int len = 1;
	int xcurr, ycurr, number = 1;

	xcurr = ycurr = n / 2;

	while (len < n) {

		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= len; j++)
			{
				xcurr += dx[i];
				ycurr += dy[i];

				numbers[number][0] = xcurr;
				numbers[number++][1] = ycurr;
			}
		}
		len++;

		for (int i = 2; i < 4; i++)
		{
			for (int j = 1; j <= len; j++)
			{
				xcurr += dx[i];
				ycurr += dy[i];

				numbers[number][0] = xcurr;
				numbers[number++][1] = ycurr;
			}
		}
		len++;
	}

	for (int j = 1; j < len; j++)
	{
		ycurr += dy[0];

		numbers[number][0] = xcurr;
		numbers[number++][1] = ycurr;
	}

	return;
}

void pull() {

	bool swapped;
	int cx, cy, nx, ny;
	for (int i = 1; i < n2; i++)
	{
		cx = numbers[i][0];
		cy = numbers[i][1];

		if (maps[cx][cy] != 0) {
			continue;
		}

		swapped = false;
		for (int j = i + 1; j < n2; j++)
		{
			nx = numbers[j][0];
			ny = numbers[j][1];

			if (maps[nx][ny] != 0)
			{
				maps[cx][cy] = maps[nx][ny];
				maps[nx][ny] = 0;
				swapped = true;
				break;
			}
		}

		if (!swapped) {
			break;
		}

	}

	return;
}

void change() {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cpy[i][j] = 0;
		}
	}

	int ncurr;
	int cnt = 0;
	int newidx = 1;
	int cx, cy, nx, ny;//////
	int nbefore = 0;

	for (int i = 1; i < n2; i++) {
		cx = numbers[i][0];
		cy = numbers[i][1];

		ncurr = maps[cx][cy];

		if (ncurr == 0) {// to the end

			if (cnt) {
				nx = numbers[newidx][0];
				ny = numbers[newidx][1];
				cpy[nx][ny] = cnt;
				newidx++;

				nx = numbers[newidx][0];
				ny = numbers[newidx][1];
				cpy[nx][ny] = nbefore;
				newidx++;
			}
			break;
		}

		if (nbefore == ncurr) {
			cnt++;
		}
		else { // nbefore != ncurr

			   // change by using numbers
			if (cnt) {
				nx = numbers[newidx][0];
				ny = numbers[newidx][1];
				cpy[nx][ny] = cnt;
				newidx++;

				nx = numbers[newidx][0];
				ny = numbers[newidx][1];
				cpy[nx][ny] = nbefore;
				newidx++;
			}

			if (newidx >= n2)
				break;

			cnt = 1;
			nbefore = ncurr;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maps[i][j] = cpy[i][j];
		}
	}

	return;
}

void makezero(int start, int len) {

	int nx, ny;
	nx = numbers[start][0];
	ny = numbers[start][1];

	ans[maps[nx][ny]] += len;

	for (int i = 0; i < len; i++)
	{
		nx = numbers[start - i][0];
		ny = numbers[start - i][1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			break;

		maps[nx][ny] = 0;
	}
	return;
}

void explode() {

	int cx, cy, ncurr;
	int cnt[4];
	int nbefore = maps[numbers[1][0]][numbers[1][1]];
	bool exploded = true;
	while (exploded) {

		exploded = false;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i < n2; i++)
		{
			cx = numbers[i][0];
			cy = numbers[i][1];

			ncurr = maps[cx][cy];
			if (ncurr == 0) { // to the end
				if (cnt[nbefore] >= 4) {
					makezero(i - 1, cnt[nbefore]);
					exploded = true;
				}
				cnt[nbefore] = 0;
				break;
			}

			if (nbefore == ncurr) {
				cnt[ncurr]++;
			}
			else { // nbefore != ncurr

				if (cnt[nbefore] >= 4) {
					makezero(i - 1, cnt[nbefore]);
					exploded = true;
				}
				cnt[nbefore] = 0;
				cnt[ncurr] ++;
				nbefore = ncurr;
			}

		}

		if (exploded) {
			pull();
		}
	}

	return;
}

void destroy(int nmagic) {

	int dir = magics[nmagic][0];
	int dist = magics[nmagic][1];

	int xo, yo, nx, ny;
	xo = yo = n / 2;
	for (int i = 1; i <= dist; i++)
	{
		nx = xo + i * dxb[dir];
		ny = yo + i * dyb[dir];

		maps[nx][ny] = 0;
	}

	pull();

	return;
}

void blizzard() {

	numbering();

	for (int i = 0; i < m; i++)
	{
		destroy(i);

		explode();

		change();
	}

	return;
}

int main() {

	scanf("%d %d", &n, &m);
	n2 = n * n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}
	maps[n / 2][n / 2] = 4;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &magics[i][0], &magics[i][1]);
	}

	blizzard();

	printf("%d", ans[1] + ans[2] * 2 + ans[3] * 3);

	return 0;
}
