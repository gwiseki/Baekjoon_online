// 1244KB, 0ms

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int seats[21][21], cnts[21][21];
int n, n2, answer;
int pos[401];
int cs[401][4];
// NEWS
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool cmp(pair<int, int> a, pair<int, int> b) {

	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

int satis(int cnt) {

	if (cnt == 0)
		return 0;
	else if (cnt == 1)
		return 1;
	else if (cnt == 2)
		return 10;
	else if (cnt == 3)
		return 100;
	else // 4
		return 1000;
	
}

int whenEmpty() {

	int xnext, ynext, ret = 0;
	int blanks[21][21];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			blanks[i][j] = 0;
		}
	}

	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (seats[i][j])
				continue;
			
			for (int k = 0; k < 4; k++)
			{
				xnext = i + dx[k];
				ynext = j + dy[k];

				if (xnext < 0 || xnext >= n || ynext < 0 || ynext >= n || seats[xnext][ynext])
					continue;

				blanks[i][j] ++;
			}

			if (maxi < blanks[i][j])
				maxi = blanks[i][j];
		}
	}

	if (maxi == 0) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(!seats[i][j])
					return 1000 * i + j;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maxi == blanks[i][j])
				return 1000 * i + j;
		}
	}

	return ret;
}

int main() {

	scanf("%d", &n);

	n2 = n * n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			seats[i][j] = 0;
		}
	}

	for (int i = 0; i <= n2; i++)
	{
		pos[i] = -1;
	}

	int curr, pcurr, xcurr, ycurr, xnext, ynext, xnextb, ynextb, max, blanks;
	vector<pair<int, int> > cands;

	answer = 0;
	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &curr);
		scanf("%d %d %d %d", &cs[curr][0], &cs[curr][1], &cs[curr][2], &cs[curr][3]);

		for (int j = 0; j < 4; j++)
		{
			pcurr = pos[cs[curr][j]];
			if (pcurr != -1) {
				xcurr = pcurr / 1000;
				ycurr = pcurr % 1000;

				for (int k = 0; k < 4; k++)
				{
					xnext = xcurr + dx[k];
					ynext = ycurr + dy[k];
					if (xnext < 0 || xnext >= n || ynext < 0 || ynext >= n || seats[xnext][ynext])
						continue;
					cnts[xnext][ynext] = 0;
				}
			}
		}

		max = 0;
		for (int j = 0; j < 4; j++)
		{
			pcurr = pos[cs[curr][j]];
			if (pcurr != -1) {
				xcurr = pcurr / 1000;
				ycurr = pcurr % 1000;

				for (int k = 0; k < 4; k++)
				{
					xnext = xcurr + dx[k];
					ynext = ycurr + dy[k];
					if (xnext < 0 || xnext >= n || ynext < 0 || ynext >= n || seats[xnext][ynext])
						continue;
					cnts[xnext][ynext]++;

					if (max < cnts[xnext][ynext]) {
						max = cnts[xnext][ynext];
					}
				}
			}
		}

		cands.clear();
		for (int j = 0; j < 4; j++)
		{
			pcurr = pos[cs[curr][j]];
			if (pcurr != -1) {
				xcurr = pcurr / 1000;
				ycurr = pcurr % 1000;

				for (int k = 0; k < 4; k++)
				{
					xnext = xcurr + dx[k];
					ynext = ycurr + dy[k];
					if (xnext < 0 || xnext >= n || ynext < 0 || ynext >= n || seats[xnext][ynext])
						continue;

					if (max == cnts[xnext][ynext]) {
						blanks = 0;

						for (int b = 0; b < 4; b++) {
							xnextb = xnext + dx[b];
							ynextb = ynext + dy[b];

							if (xnextb < 0 || xnextb >= n || ynextb < 0 || ynextb >= n || seats[xnextb][ynextb])
								continue;
							else
								blanks++;
						}

						cands.push_back({ blanks, xnext * 1000 + ynext });
					}
				}
			}
		}

		sort(cands.begin(), cands.end(), cmp);

		if (!cands.empty()) {
			pos[curr] = cands.front().second;
		}
		else {
			pos[curr] = whenEmpty();
		}

		int xpos = pos[curr] / 1000;
		int ypos = pos[curr] % 1000;
		seats[xpos][ypos] = curr;
	}

	int num, xside, yside, snum;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			num = seats[i][j];
			snum = 0;
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					xside = i + dx[y];
					yside = j + dy[y];

					if (xside < 0 || xside >= n || yside < 0 || yside >= n)
						continue;

					if (cs[num][x] == seats[xside][yside])
						snum++;
				}
			}
			answer += satis(snum);
		}
	}

	printf("%d", answer);

	return 0;
}
