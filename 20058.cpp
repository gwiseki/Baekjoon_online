// 1268KB, 60ms

#include <cstdio>
#include <queue>

using namespace std;

int n, n2, q;
int maps[65][65], cpy[65][65];
int ls[1001];
int sum, lump;

// NESW
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void getlump() {

	queue<int> que;
	vector<int> lumps;
	bool visited[65][65];

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			visited[i][j] = false;
		}
	}

	int lsize, xcurr, ycurr, xnext, ynext;
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (maps[i][j] && !visited[i][j]) {
				lsize = 0;

				que.push(i);
				que.push(j);
				visited[i][j] = true;
				lsize++;

				while (!que.empty()) {

					xcurr = que.front();
					que.pop();
					ycurr = que.front();
					que.pop();

					for (int k = 0; k < 4; k++)
					{
						xnext = xcurr + dx[k];
						ynext = ycurr + dy[k];

						if (xnext < 0 || xnext >= n2 || ynext < 0 || ynext >= n2
							|| visited[xnext][ynext] || ! maps[xnext][ynext])
							continue;
						else {
							que.push(xnext);
							que.push(ynext);
							visited[xnext][ynext] = true;
							lsize++;
						}
					}
				}
				if (lsize >= 2)
					lumps.push_back(lsize);
			}
		}
	}

	int maxlump = 0;
	for (int i = 0; i < lumps.size(); i++)
	{
		if (maxlump < lumps.at(i))
			maxlump = lumps.at(i);
	}
	lump = maxlump;

	return;
}

void getsum() {

	int ret = 0;
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			ret += maps[i][j];
		}
	}
	sum = ret;

	return;
}

void decreaseIce() {

	int xnext, ynext;

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			cpy[i][j] = maps[i][j];
		}
	}

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (cpy[i][j] > 0) {
				int yesice = 0;
				for (int k = 0; k < 4; k++)
				{
					xnext = i + dx[k];
					ynext = j + dy[k];
					if (xnext < 0 || xnext >= n2 || ynext < 0 || ynext >= n2)
						continue;

					if (cpy[xnext][ynext] > 0) {
						yesice++;
					}
				}

				if (yesice < 3) {
					maps[i][j]--;
				}
			}
		}
	}

	return;
}

void rotate(int x, int y, int len) {

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cpy[x + i][y + j] = maps[x + i][y + j];
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			maps[x + i][y + j] = cpy[x + len - 1 - j][y + i];
		}
	}

	return;
}

void firestorm() {

	int lcurr, lcurr2, xcurr, ycurr, nl2;
	for (int k = 0; k < q; k++)
	{
		lcurr = ls[k];
		lcurr2 = 1 << lcurr;
		nl2 = 1 << (n - lcurr);

		for (int i = 0; i < nl2; i++)
		{
			for (int j = 0; j < nl2; j++)
			{
				rotate(i * lcurr2, j * lcurr2, lcurr2);
			}
		}

		decreaseIce();
	}

	return;
}

int main() {

	scanf("%d %d", &n, &q);

	n2 = 1 << n;

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}

	for (int i = 0; i < q; i++)
	{
		scanf("%d", &ls[i]);
	}

	firestorm();

	getsum();

	getlump();

	printf("%d\n%d", sum, lump);

	return 0;
}
