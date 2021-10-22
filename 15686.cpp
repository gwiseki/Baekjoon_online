// 1248KB, 4ms

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int maps[51][51];
int dists[101][14];
int shops[14][2];
int nshops, nhomes;

int abs(int a) {
	return a > 0 ? a : a * (-1);
}

int getdist(int x, int y, int idx) {

	int xshop = shops[idx][0];
	int yshop = shops[idx][1];

	int ret = abs(x - xshop) + abs(y - yshop);

	return ret;
}

int getdisttoshopsforthiscombination(vector<int> combi) {

	int mincurr;
	int ret = 0;
	for (int i = 0; i < nhomes; i++)
	{
		mincurr = 1000;
		for (int j = 0; j < nshops; j++)
		{
			if (combi.at(j)) {
				if (mincurr > dists[i][j])
					mincurr = dists[i][j];
			}
		}
		ret += mincurr;
	}
	return ret;
}

int findchicken() {

	vector<int> combi;
	int ret = 100 * 13 * 100 * 100, disttoshops;
	for (int i = 0; i < m; i++)
	{
		combi.push_back(1);
	}
	for (int i = m; i < nshops; i++)
	{
		combi.push_back(0);
	}
	sort(combi.begin(), combi.end());

	do {
		disttoshops = getdisttoshopsforthiscombination(combi);

		if (ret > disttoshops) {
			ret = disttoshops;
		}
	} while (next_permutation(combi.begin(), combi.end()));

	return ret;
}

void getdistsAll() {

	int idxh = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] == 1)
			{
				for (int idx = 0; idx < nshops; idx++)
				{
					dists[idxh][idx] = getdist(i, j, idx);
				}
				idxh++;
			}
		}
	}
	nhomes = idxh;
	return;
}

int main() {

	scanf("%d %d", &n, &m);

	nshops = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &maps[i][j]);
			if (maps[i][j] == 2) {
				shops[nshops][0] = i;
				shops[nshops][1] = j;
				nshops++;
			}
		}
	}

	getdistsAll();

	int mindist = findchicken();

	printf("%d", mindist);

	return 0;
}
