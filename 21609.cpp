// 1244KB, 4ms
 
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// NESW
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

int n, m, scores = 0;
int maps[23][23], cpy[23][23];

bool cmp(vector<int> a, vector<int> b) {

	if (a.at(0) == b.at(0)) {

		if (a.at(1) == b.at(1)) {

			if (a.at(2) == b.at(2)) {

				return a.at(3) > b.at(3);
			}
			else {
				return a.at(2) > b.at(2);
			}
		}
		else {
			return a.at(1) > b.at(1);
		}
	}
	else {
		return a.at(0) > b.at(0);
	}
}

void remove(int standard) {

	queue<int> bfs;
	int sx = standard / 100;
	int sy = standard % 100;

	int color, xc, yc, xn, yn;

	color = maps[sx][sy];
	bfs.push(sx);
	bfs.push(sy);
	maps[sx][sy] = -2;

	while (!bfs.empty()) {

		xc = bfs.front();
		bfs.pop();
		yc = bfs.front();
		bfs.pop();

		for (int k = 0; k < 4; k++)
		{
			xn = xc + dx[k];
			yn = yc + dy[k];

			if (maps[xn][yn] < 0 || 
				((maps[xn][yn] != color) && maps[xn][yn] > 0))
				continue;

			bfs.push(xn);
			bfs.push(yn);
			maps[xn][yn] = -2;
		}
	}

	return;
}

void rotate() {

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cpy[i][j] = maps[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			maps[i][j] = cpy[j][n - i + 1];
		}
	}

	return;
}

void gravity() {

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			if (maps[i][j] == -2)
			{
				for (int k = i - 1; k >= 1; k--)
				{
					if (maps[k][j] >= 0) {
						maps[i][j] = maps[k][j];
						maps[k][j] = -2;
						break;
					}
					else if (maps[k][j] == -1)
						break;
					// if -2, continue;
				}
			}
		}
	}

	return;
}

int findblock() {

	vector<vector<int> > blocklist;
	queue<int> bfs;
	vector<int> zeroes;
	int visited[23][23];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (maps[i][j] == 0) 
			{
				zeroes.push_back(i);
				zeroes.push_back(j);
			}
		}
	}
	int zsize = zeroes.size();

	int color, cnt, rainbow, sx, sy;
	int xn, yn, xc, yc;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (maps[i][j] > 0 && !visited[i][j]) {

				cnt = 1;
				bfs.push(i);
				bfs.push(j);
				visited[i][j] = true;

				color = maps[i][j];
				sx = i; // fixed
				sy = j; // update later
				rainbow = 0;
				
				while (!bfs.empty()) {

					xc = bfs.front();
					bfs.pop();
					yc = bfs.front();
					bfs.pop();

					for (int k = 0; k < 4; k++)
					{
						xn = xc + dx[k];
						yn = yc + dy[k];

						if (maps[xn][yn] < 0 || visited[xn][yn] || 
							((maps[xn][yn] != color) && maps[xn][yn] > 0) )
							continue;

						if (sy > yn && sx >= xn && (maps[xn][yn] != 0)) {
							sx = xn;
							sy = yn;
						}

						if (maps[xn][yn] == 0)
							rainbow++;

						cnt++;
						bfs.push(xn);
						bfs.push(yn);
						visited[xn][yn] = true;
					}
				}

				if (cnt > 1) {
					vector<int> cblock;
					cblock.push_back(cnt);
					cblock.push_back(rainbow);
					cblock.push_back(sx);
					cblock.push_back(sy);
					blocklist.push_back(cblock);
				}

				for (int z = 0; z < zsize; z+=2)
				{
					visited[zeroes.at(z)][zeroes.at(z + 1)] = false;
				}
			}
		}
	}

	if (blocklist.size()) {

		sort(blocklist.begin(), blocklist.end(), cmp);

		scores += (blocklist.front().at(0) * blocklist.front().at(0));

		return blocklist.front().at(2) * 100 + blocklist.front().at(3);
	}
	else {
		return 0;
	}

	return 0;
}

void autoplay() {

	int standard = findblock();

	while (standard) {

		remove(standard);

		gravity();

		rotate();

		gravity();

		standard = findblock();
	}

	return;
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}

	for (int i = 0; i <= n + 1; i++)
	{
		maps[0][i] = maps[n + 1][i] = maps[i][0] = maps[i][n + 1] = -1;
	}

	autoplay();

	printf("%d", scores);

	return 0;
}
