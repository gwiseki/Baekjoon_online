// 1268KB, 4ms

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// NSWE
int dx[5] = { -10, -1, 1, 0, 0};
int dy[5] = { -10, 0, 0, -1, 1};

int n, m, k;
int maps_origin[23][23][2]; // # of shark, left smell time
int prior[402][5][4], dir[402], pos[402][2];
bool isdead[402];
int ctime = 0, sharknum = 0;

void move() {

	int maps[23][23][2];
	queue<int> sharksalive;

	for (int i = 1; i <= m; i++)
	{
		sharksalive.push(i);
	}

	while (sharknum > 1) {

		int scurr, currsharksalive = sharksalive.size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j][0] = maps_origin[i][j][0];
				maps[i][j][1] = maps_origin[i][j][1];
			}
		}

		int xcurr, ycurr, xnext, ynext, dnext;
		bool ismoved;
		// update maps,pos,dir
		for (int i = 0; i < currsharksalive; i++)
		{
			ismoved = false;
			scurr = sharksalive.front();
			sharksalive.pop();

			if (isdead[scurr])
				continue;

			xcurr = pos[scurr][0];
			ycurr = pos[scurr][1];
			
			// move to no smell space
			for (int j = 0; j < 4; j++)
			{
				dnext = prior[scurr][dir[scurr]][j];
				xnext = xcurr + dx[dnext];
				ynext = ycurr + dy[dnext];

				if (xnext < 0 || xnext >= n || ynext < 0 || ynext >= n)
					continue;

				if (!maps_origin[xnext][ynext][0]) {

					// competition
					if (maps[xnext][ynext][0] && maps[xnext][ynext][1] == k) {

						sharknum--;
						if (scurr > maps[xnext][ynext][0]) {
							isdead[scurr] = true;
							ismoved = true;
							pos[scurr][0] = xnext;
							pos[scurr][1] = ynext;
							break;
						}
						else
							isdead[maps[xnext][ynext][0]] = true;
					}
					ismoved = true;
					break;
				}
			}

			if (!ismoved) {
				// move to my smell space
				for (int j = 0; j < 4; j++)
				{
					dnext = prior[scurr][dir[scurr]][j];
					xnext = xcurr + dx[dnext];
					ynext = ycurr + dy[dnext];

					if (xnext < 0 || xnext >= n || ynext < 0 || ynext >= n) {
						continue;
					}

					if (maps_origin[xnext][ynext][0] == scurr) {
						break;
					}
				}
			}
			
			if (!isdead[scurr]) {
				dir[scurr] = dnext;
				pos[scurr][0] = xnext;
				pos[scurr][1] = ynext;
				maps[xnext][ynext][0] = scurr;
				maps[xnext][ynext][1] = k;
				sharksalive.push(scurr);
			}
		}

		ctime++;
		if (ctime > 1000) {
			ctime = -1;
			break;
		}

		// decrease smell time
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][j][1] > 0 && 
					((i != pos[maps[i][j][0]][0]) || (j != pos[maps[i][j][0]][1]))) {
					maps[i][j][1] --;

					if (maps[i][j][1] == 0) {
						maps[i][j][0] = 0;
					}

				}
			}
		}

		// copy for next move
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps_origin[i][j][0] = maps[i][j][0];
				maps_origin[i][j][1] = maps[i][j][1];
			}
		}
	}

	return;
}

int main() {

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &maps_origin[i][j][0]);
			if (maps_origin[i][j][0]) {
				maps_origin[i][j][1] = k;
				pos[maps_origin[i][j][0]][0] = i;
				pos[maps_origin[i][j][0]][1] = j;
				sharknum++;
			}
		}
	}

	for (int i = 0; i <= m; i++)
	{
		isdead[i] = false;
	}

	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &dir[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int l = 0; l < 4; l++)
			{
				scanf("%d", &prior[i][j][l]);
			}
		}
	}

	move();

	printf("%d", ctime);

	return 0;
}
