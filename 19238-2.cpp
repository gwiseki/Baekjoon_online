// 1240KB, 0ms

#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

// N E S W
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, fuel;
int maps[23][23];
int pas[402][4];
bool over[402];
int txcurr, tycurr;

using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {

	if (a.first.first == b.first.first)
		return a.first.second < b.first.second;
	else
		return a.first.first < b.first.first;
}

int getDist(int x1, int y1, int x2, int y2) {

	if (x1 == x2 && y1 == y2)
		return 0;

	queue<tuple<int, int, int> > bfs;
	bool visited[23][23];
	int xcurr, ycurr, dcurr, xnext, ynext;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visited[i][j] = false;
		}
	}

	bfs.push(make_tuple(x1, y1, 0));
	visited[x1][y1] = true;

	while (!bfs.empty()) {
		tuple<int, int, int> curr = bfs.front();
		bfs.pop();

		xcurr = get<0>(curr);
		ycurr = get<1>(curr);
		dcurr = get<2>(curr);

		for (int i = 0; i < 4; i++)
		{
			xnext = xcurr + dx[i];
			ynext = ycurr + dy[i];

			if (maps[xnext][ynext] == 1 || visited[xnext][ynext])
				continue;

			if (xnext == x2 && ynext == y2)
				return dcurr + 1;

			bfs.push(make_tuple(xnext, ynext, dcurr + 1));
			visited[xnext][ynext] = true;
		}
	}

	return -1;
}

// min 이랑 운행 끝난 승객 check
int getNextPassAndDist() {

	vector<pair<pair<int, int>, int> > cands;

	if (maps[txcurr][tycurr] >= 2 && !over[maps[txcurr][tycurr] - 2]) {

		for (int i = 0; i < m; i++)
		{
			if (txcurr == pas[i][0] && tycurr == pas[i][1]) {
				return 1000 * i;
			}
		}
	}

	queue<tuple<int, int, int> > bfs;
	bool visited[23][23];
	int xcurr, ycurr, dcurr, xnext, ynext;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visited[i][j] = false;
		}
	}

	bfs.push(make_tuple(txcurr, tycurr, 0));
	visited[txcurr][tycurr] = true;

	while (!bfs.empty()) {

		int bsize = bfs.size();

		for (int k = 0; k < bsize; k++)
		{
			tuple<int, int, int> curr = bfs.front();
			bfs.pop();

			xcurr = get<0>(curr);
			ycurr = get<1>(curr);
			dcurr = get<2>(curr);

			for (int i = 0; i < 4; i++)
			{
				xnext = xcurr + dx[i];
				ynext = ycurr + dy[i];

				if (maps[xnext][ynext] == 1 || visited[xnext][ynext])
					continue;

				if (maps[xnext][ynext] >= 2 && !over[maps[xnext][ynext] - 2]) {
					cands.push_back({ {xnext, ynext}, maps[xnext][ynext] });
				}
				else {
					bfs.push(make_tuple(xnext, ynext, dcurr + 1));
				}
				visited[xnext][ynext] = true;
			}
		}

		if (cands.size()) {
			break;
		}
	}

	sort(cands.begin(), cands.end(), cmp);

	if (!cands.size()) {
		return -1;
	}

	return (cands.front().second - 2) * 1000 + dcurr + 1;
}

void drive() {

	int pnnext, pdnext;
	for (int i = 0; i < m; i++)
	{
		int pnext = getNextPassAndDist();

		if (pnext == -1) {
			fuel = -1;
			return;
		}

		pnnext = pnext / 1000;
		pdnext = pnext % 1000;

		fuel -= pdnext;
		if (fuel < 0) {
			fuel = -1;
			return;
		}

		int dist = getDist(pas[pnnext][0], pas[pnnext][1],
			pas[pnnext][2], pas[pnnext][3]);

		if (dist == -1) {
			fuel = -1;
			return;
		}

		fuel -= dist;
		if (fuel < 0) {
			fuel = -1;
			return;
		}
		fuel += dist * 2;

		txcurr = pas[pnnext][2];
		tycurr = pas[pnnext][3];
		over[pnnext] = true;
	}

	return;
}

int main() {

	scanf("%d %d %d", &n, &m, &fuel);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}

	for (int i = 0; i <= n + 1; i++)
	{
		maps[i][0] = maps[i][n + 1] = maps[0][i] = maps[n + 1][i] = 1;
		over[i] = false;
	}

	scanf("%d %d", &txcurr, &tycurr);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &pas[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		maps[pas[i][0]][pas[i][1]] = i + 2;
	}

	drive();

	printf("%d", fuel);

	return 0;
}
