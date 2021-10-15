// 1244KB, 16ms

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// NESW
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

int maps[53][53];
int n, m, minTime = 2501, empties = 0;
vector<pair<int, int> > inacs;

void spread(vector<int> combi) {

	int maps_cpy[53][53];
	int isize = inacs.size();
	int ecopy = empties;
	queue<int> que;

	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			maps_cpy[i][j] = maps[i][j];
		}
	}

	for (int i = 0; i < isize; i++)
	{
		if (combi.at(i) == 1) {
			que.push(inacs.at(i).first);
			que.push(inacs.at(i).second);
			que.push(2);
		}
	}

	int xcurr, ycurr, tcurr, xnext, ynext, tnext;
	while (!que.empty()) {
		xcurr = que.front();
		que.pop();
		ycurr = que.front();
		que.pop();
		tcurr = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			xnext = xcurr + dx[i];
			ynext = ycurr + dy[i];
			tnext = tcurr + 1;

			if (maps_cpy[xnext][ynext] != 1 && maps_cpy[xnext][ynext] <= 2) {

				if (maps_cpy[xnext][ynext] == 0) {
					ecopy--;

					if (ecopy <= 0) {

						if (minTime > tnext)
							minTime = tnext;
						return;
					}
				}
				que.push(xnext);
				que.push(ynext);
				que.push(tnext);

				maps_cpy[xnext][ynext] = tnext;
			}
		}
	}
}

void getMinTime() {

	vector<int> combi;

	int isize = inacs.size();
	int idx;
	for (idx = 0; idx < m; idx++)
		combi.push_back(1);

	while (idx < isize) {
		combi.push_back(0);
		idx++;
	}
	
	sort(combi.begin(), combi.end());

	do {
		spread(combi);
	} while (next_permutation(combi.begin(), combi.end()));

	return;
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &maps[i][j]);
			if (maps[i][j] == 0) {
				empties++;
			}
			else if (maps[i][j] == 2) {
				inacs.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i <= n + 1; i++)
	{
		maps[0][i] = maps[n + 1][i] = maps[i][0] = maps[i][n + 1] = 1;
	}

	if (!empties) {
		printf("0");
		return 0;
	}
	getMinTime();

	if (minTime == 2501) {
		printf("-1");
		return 0;
	}

	printf("%d", minTime - 2);

	return 0;
}
