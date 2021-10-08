// 1164KB, 0ms

#include <cstdio>

using namespace std;

bool maps[130][130];
bool divide[130][130];
bool checked[130][130];

int main() {

	int n, curr, times, bnum = 0, wnum = 0;
	bool same, init;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			scanf("%d", &maps[i][j]);
	
	curr = n;
	while (curr > 0) {

		times = n / curr;

		//초기화
		for (int i = 0; i < times; i++)
			for (int j = 0; j < times; j++)
				divide[i * curr][j * curr] = false;

		for (int i = 0; i < times; i++)
			for (int j = 0; j < times; j++) {

				same = true;
				init = maps[i * curr][j * curr];
				if(!checked[i * curr][j * curr])
					for (int x = 0; x < curr; x++) {
						for (int y = 0; y < curr; y++) {
							if (init != maps[i * curr + x][j * curr + y]) {
								same = false;
								break;
							}
						}
						if (!same)
							break;
					}

				if (!same)
					divide[i * curr][j * curr] = true;
			}

		for (int i = 0; i < times; i++)
			for (int j = 0; j < times; j++) 
				if (!divide[i * curr][j * curr] && !checked[i * curr][j * curr]) {
					if (maps[i * curr][j * curr])
						bnum++;
					else
						wnum++;

					for (int x = 0; x < curr; x++)
						for (int y = 0; y < curr; y++)
							checked[i * curr + x][j * curr + y] = true;
				}
		
		curr /= 2;
	}
		
	printf("%d\n%d", wnum, bnum);

	return 0;
}
