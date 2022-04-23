#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int max = 0;

void move(int fishes[][3], int coord[][6], int cnt) {

	int xcurr, ycurr, dcurr, xnext, ynext, dnext;

	// fish move
	for (int i = 1; i < 17; i++)
	{
		dcurr = fishes[i][0];
		if (dcurr == 8) {
			continue;
		}

		xcurr = fishes[i][1];
		ycurr = fishes[i][2];

		dnext = dcurr;
		xnext = xcurr + dx[dnext];
		ynext = ycurr + dy[dnext];
		
		// shark or wall, rotate
		while (xnext <= 0 || ynext <= 0 || xnext > 4 || ynext > 4 || coord[xnext][ynext] >= 17) {
			dnext = (dnext + 1) % 8;
			xnext = xcurr + dx[dnext];
			ynext = ycurr + dy[dnext];
		}
		
		// swap position
		int nextnum = coord[xnext][ynext];
		fishes[i][0] = dnext;
		fishes[i][1] = xnext;
		fishes[i][2] = ynext;
		fishes[nextnum][1] = xcurr;
		fishes[nextnum][2] = ycurr;

		coord[xcurr][ycurr] = nextnum;
		coord[xnext][ynext] = i;
	}

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}

	// shark move 
	bool sharkmoved = false;

	dcurr = fishes[17][0];
	xcurr = fishes[17][1];
	ycurr = fishes[17][2];
	for (int idx = 1; idx <= 3; idx++)
	{
		xnext = xcurr + dx[dcurr] * idx;
		ynext = ycurr + dy[dcurr] * idx;

		if (xnext <= 0 || ynext <= 0 || xnext > 4 || ynext > 4)
			continue;

		if (coord[xnext][ynext] == 0 || coord[xnext][ynext] >= 17)
			continue;

		int nextfish[18][3];
		int nextcd[6][6]; // edges for wall
		int nextcnt = cnt;

		// copy
		for (int i = 1; i < 18; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				nextfish[i][j] = fishes[i][j];
			}
		}

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				nextcd[i][j] = coord[i][j];
			}
		}

		sharkmoved = true;

		nextcnt += coord[xnext][ynext];
		nextfish[17][1] = xnext;
		nextfish[17][2] = ynext;
		nextfish[17][0] = fishes[coord[xnext][ynext]][0];
		nextfish[coord[xnext][ynext]][0] = 8; // eaten
		nextcd[xnext][ynext] = 17;
		nextcd[xcurr][ycurr] = 0;
		
		move(nextfish, nextcd, nextcnt);
	}

	if (!sharkmoved) {
		if (max < cnt)
			max = cnt;
	}
}

int main() {

	int inputs;

	// dir, x, y
	// 1~16 : fish, 17 : shark
	int fishes[18][3];

	// edges for wall
	int coord[6][6];


	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			scanf("%d", &inputs);
			coord[i][j] = inputs;
			scanf("%d", &fishes[inputs][0]);
			fishes[inputs][0]--;
			fishes[inputs][1] = i;
			fishes[inputs][2] = j;
		}
	}

	// walls
	for (int i = 0; i < 5; i++)
	{
		coord[0][i] = 17;
		coord[i + 1][0] = 17;
		coord[5][i + 1] = 17;
		coord[i][5] = 17;
	}

	// eaten fish
	int cnt = coord[1][1];
	fishes[17][0] = fishes[coord[1][1]][0];
	fishes[17][1] = 1;
	fishes[17][2] = 1;
	fishes[coord[1][1]][0] = 8; // eaten
	coord[1][1] = 17;
	
	move(fishes, coord, cnt);

	printf("%d", max);

	return 0;
}