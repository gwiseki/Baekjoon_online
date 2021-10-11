// 1268KB, 0ms

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int maps[101][101];
vector<pair<int, int>> counts;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)
		return true;
	else if (a.second > b.second)
		return false;
	else { // ==
		return a.first < b.first;
	}
}

int main() {
	int r, c, k, rownum, calnum, time = 0;
	
	int maxlen = 0;

	scanf("%d %d %d", &r, &c, &k);
	r--; c--;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &maps[i][j]);

	rownum = calnum = 3;

	while (maps[r][c] != k) {
		if (rownum >= calnum) {
			for (int i = 0; i < rownum; i++) {

				int count[101];
				for (int j = 0; j <= 100; j++)
					count[j] = 0;

				for (int j = 0; j < calnum; j++) {
					if (maps[i][j]) 
						count[maps[i][j]] ++;
				}

				for (int j = 0; j < calnum; j++) 
					maps[i][j] = 0;

				for(int j = 0; j <= 100; j ++)
					if(count[j])
						counts.push_back(make_pair(j, count[j]));

				sort(counts.begin(), counts.end(), cmp);

				int x = 0;
				int countslen = counts.size();
				for (int j = 0; j < countslen; j++) {
					maps[i][x++] = counts.at(j).first;
					maps[i][x++] = counts.at(j).second;
				}
				if (maxlen < x)
					maxlen = x;

				counts.clear();
			}
			calnum = maxlen;
			maxlen = 0;
		}

		else {
			for (int i = 0; i < calnum; i++) {

				int count[101];
				for (int j = 0; j <= 100; j++)
					count[j] = 0;

				for (int j = 0; j < rownum; j++)
					if (maps[j][i]) 
						count[maps[j][i]] ++;
					
				for (int j = 0; j < calnum; j++)
					maps[j][i] = 0;

				for (int j = 0; j <= 100; j++)
					if (count[j])
						counts.push_back(make_pair(j, count[j]));

				sort(counts.begin(), counts.end(), cmp);

				int x = 0;
				int countslen = counts.size();
				for (int j = 0; j < countslen; j++) {
					maps[x++][i] = counts.at(j).first;
					maps[x++][i] = counts.at(j).second;
				}
				if (maxlen < x)
					maxlen = x;

				counts.clear();
			}
			rownum = maxlen + 1;
			maxlen = 0;
		}

		time++;
		if (time > 100) {
			time = -1;
			break;
		}

		if (maps[r][c] > 100)
			break;
	}
	printf("%d", time);

	return 0;
}

