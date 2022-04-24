#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m, f, maps[22][22]; // 1~, 1~
int src[401][2], dest[401][2], sx, sy; // 1~
int left, leftpas, nextdisttosrc;

int getdist(int x1, int y1, int x2, int y2) {

	bool visited[22][22];
	int cx, cy, cd, nx, ny, nd;
	vector<pair<int, int> > cands;
	queue<int> bfs;

	if (x1 == x2 && y1 == y2)
		return 0;

	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			visited[i][j] = false;
		}
	}

	bfs.push(x1);
	bfs.push(y1);
	bfs.push(0);
	visited[x1][y1] = true;

	while (!bfs.empty()) {

		cx = bfs.front();
		bfs.pop();
		cy = bfs.front();
		bfs.pop();
		cd = bfs.front();
		bfs.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			nd = cd + 1;
			if (maps[nx][ny] != -1 && !visited[nx][ny]) {

				if (nx == x2 && ny == y2) {
					return nd;
				}

				bfs.push(nx);
				bfs.push(ny);
				bfs.push(nd);
				visited[nx][ny] = true;
			}
		}
	}

	return -1;
}

int getnextpas() {

	bool visited[22][22], found;
	int cx, cy, cd, nx, ny, nd;
	vector<pair<int, int> > cands;
	queue<int> bfs;

	if (maps[sx][sy] > 0) {
		nextdisttosrc = 0;
		return maps[sx][sy];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visited[i][j] = false;
		}
	}

	bfs.push(sx);
	bfs.push(sy);
	bfs.push(0);
	visited[sx][sy] = true;

	found = false;
	while (!bfs.empty() && !found) {

		int loop = bfs.size() / 3;
		for (int j = 0; j < loop; j ++) {
			cx = bfs.front();
			bfs.pop();
			cy = bfs.front();
			bfs.pop();
			cd = bfs.front();
			bfs.pop();

			for (int i = 0; i < 4; i++)
			{
				nx = cx + dx[i];
				ny = cy + dy[i];
				nd = cd + 1;
				if (maps[nx][ny] != -1 && !visited[nx][ny]) {

					if (maps[nx][ny] > 0) {
						nextdisttosrc = nd;
						cands.push_back({ nx, ny });
						found = true;
					}
					else {
						bfs.push(nx);
						bfs.push(ny);
						bfs.push(nd);
						visited[nx][ny] = true;
					}
				}
			}
		}
	}

	if (cands.empty()) {
		return -1;
	}

	sort(cands.begin(), cands.end());

	return maps[cands.front().first][cands.front().second];
}

void drive() {

	left = f;
	leftpas = m;
	int num;
	
	while (leftpas > 0) {

		num = getnextpas();

		if (num == -1) {
			left = -1;
			break;
		}

		if (left < nextdisttosrc) {
			left = -1;
			break;
		}

		left -= nextdisttosrc;
		maps[src[num][0]][src[num][1]] = 0;

		int todest = getdist(src[num][0], src[num][1], dest[num][0], dest[num][1]);

		if (todest == -1) {
			left = -1;
			break;
		}

		if (left < todest) {
			left = -1;
			break;
		}

		left += todest;
		leftpas--;

		sx = dest[num][0];
		sy = dest[num][1];
	}

	return;
}

int main() {

	scanf("%d %d %d", &n, &m, &f);

	int input;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &input);
			if (input == 0)
				maps[i][j] = input;
			else
				maps[i][j] = -1;
		}
	}

	scanf("%d %d", &sx, &sy);

	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d %d", &src[i][0], &src[i][1], &dest[i][0], &dest[i][1]);
		maps[src[i][0]][src[i][1]] = i;
	}

	for (int i = 0; i < n + 2; i++)
	{
		maps[i][0] = -1;
		maps[i][n + 1] = -1;
		maps[0][i] = -1;
		maps[n + 1][i] = -1;
	}

	drive();

	printf("%d", left);

	return 0;
}
