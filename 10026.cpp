// 1280KB, 0ms

#include <cstdio>
#include <queue>

using namespace std;

char rgb[100][100];
int visited[100][100];
//NEWS
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };
int n;

void bfs_rg(int x, int y, int section) {

	queue<int> que;
	char ccurr = rgb[x][y];
	que.push(x);
	que.push(y);
	visited[x][y] = section;

	while(!que.empty()) {

		int xcurr = que.front();
		que.pop();
		int ycurr = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xcurr + dx[i];
			int ny = ycurr + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
				continue;

			if (rgb[nx][ny] == ccurr) {
				que.push(nx);
				que.push(ny);
				visited[nx][ny] = section;
			}
		}
	}
}

void bfs_no_rg(int x, int y, int section) {

	queue<int> que;
	char ccurr = rgb[x][y];
	que.push(x);
	que.push(y);
	visited[x][y] = section;

	if (ccurr == 'R' || ccurr == 'G') {

		while (!que.empty()) {

			int xcurr = que.front();
			que.pop();
			int ycurr = que.front();
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = xcurr + dx[i];
				int ny = ycurr + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
					continue;

				if (rgb[nx][ny] == 'R' || rgb[nx][ny] == 'G') {
					que.push(nx);
					que.push(ny);
					visited[nx][ny] = section;
				}
			}
		}
	}
	else
	{
		while (!que.empty()) {

			int xcurr = que.front();
			que.pop();
			int ycurr = que.front();
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = xcurr + dx[i];
				int ny = ycurr + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
					continue;

				if (rgb[nx][ny] == ccurr) {
					que.push(nx);
					que.push(ny);
					visited[nx][ny] = section;
				}
			}
		}

	}
}

int main() {

	int section = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", rgb[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j]) {
				section++;
				bfs_rg(i, j, section);
			}

		}
	}

	printf("%d ", section);

	// set to initial state
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
	section = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j]) {
				section++;
				bfs_no_rg(i, j, section);
			}

		}
	}

	printf("%d", section);

	return 0;
}
