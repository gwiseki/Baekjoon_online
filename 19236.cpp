// 1232KB, 0ms

#include <cstdio>
#include <vector>

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1};
int maxi = 0;

void hunt(vector<vector<int> > maps, vector<vector<int> > pos, int cnt) {

	int dcurr, xcurr, ycurr, xnext, ynext, nnext, dnext, idx;
	for (int i = 1; i <= 16; i++) {
		dcurr = pos[i][2];
		xcurr = pos[i][0];
		ycurr = pos[i][1];

		if (xcurr == -1)
			continue;

		idx = 0;
		while (idx < 8) {
			xnext = xcurr + dx[dcurr];
			ynext = ycurr + dy[dcurr];

			if (xnext < 0 || xnext >= 4 || ynext < 0 || ynext >= 4 || maps[xnext][ynext] == 17) {
				dcurr = (dcurr + 1) % 8;
				idx++;
				continue;
			}
			pos[i][2] = dcurr;

			nnext = maps[xnext][ynext];
			dnext = pos[nnext][2];

			maps[xnext][ynext] = i;
			pos[nnext][0] = xcurr;
			pos[nnext][1] = ycurr;

			maps[xcurr][ycurr] = nnext;
			pos[i][0] = xnext;
			pos[i][1] = ynext;
			break;
		}

	}

	int sxcurr = pos[17][0];
	int sycurr = pos[17][1];
	int sdcurr = pos[17][2];

	for (idx = 1; idx <= 3; idx++)
	{
		xnext = sxcurr + dx[sdcurr] * idx;
		ynext = sycurr + dy[sdcurr] * idx;

		if (xnext < 0 || xnext >= 4 || ynext < 0 || ynext >= 4) {
			if (maxi < cnt)
				maxi = cnt;
			break;
		}
		
		if (maps[xnext][ynext] == 0) {
			continue;
		}

		vector<vector<int> > maps_cpy(maps);
		vector<vector<int> > pos_cpy(pos);

		nnext = maps_cpy[xnext][ynext];
		dnext = pos_cpy[nnext][2];

		maps_cpy[sxcurr][sycurr] = 0;
		pos_cpy[nnext][0] = -1;

		maps_cpy[xnext][ynext] = 17;
		pos_cpy[17][0] = xnext;
		pos_cpy[17][1] = ynext;
		pos_cpy[17][2] = dnext;

		hunt(maps_cpy, pos_cpy, cnt + nnext);
	}

	return;
}

int main() {

	vector<vector<int> > maps; // [4][4]
	vector<vector<int> > pos; // [18][3] x, y, direction
	int fishnum, fishd, cnt = 0;

	for (int i = 0; i < 18; i++) {
		vector<int> temp;
		temp.push_back(0); temp.push_back(0); temp.push_back(0);
		pos.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		vector<int> vmap;
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &fishnum);
			vmap.push_back(fishnum);

			scanf("%d", &fishd);
			pos[fishnum][0] = i;
			pos[fishnum][1] = j;
			pos[fishnum][2] = fishd - 1;
		}
		maps.push_back(vmap);
	}

	pos[maps[0][0]][0] = -1;
	pos[17][0] = 0;
	pos[17][1] = 0;
	pos[17][2] = pos[maps[0][0]][2];

	cnt += maps[0][0];
	maps[0][0] = 17;

	hunt(maps, pos, cnt);

	printf("%d", maxi);

	return 0;
}
