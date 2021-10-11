// 1472KB, 88ms

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> connect[53][53];
vector<int> unions;
queue<int> psearch;
int maps[53][53];
bool visited[53][53] = { 0, };

int absolute(int a) {

	if (a >= 0)
		return a;
	else
		return -a;
}

int main() {

	int n, l, r, day = 0;
	int xcurr, ycurr, sizecurr, sizeunion, total, each;
	int xnext, ynext;
	bool united = false;

	scanf("%d %d %d", &n, &l, &r);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &maps[i][j]);
	
	for (int i = 0; i <= n + 1; i++){
		maps[0][i] = -1;
		maps[n + 1][i] = -1;
		maps[i][0] = -1;
		maps[i][n + 1] = -1;
	}

	while (10) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {

				if (maps[i + 1][j] != -1 && absolute(maps[i][j] - maps[i + 1][j]) >= l && absolute(maps[i][j] - maps[i + 1][j]) <= r) {
					connect[i][j].push_back(i + 1);
					connect[i][j].push_back(j);
					connect[i + 1][j].push_back(i);
					connect[i + 1][j].push_back(j);
				}

				if (maps[i][j + 1] != -1 && absolute(maps[i][j] - maps[i][j + 1]) >= l && absolute(maps[i][j] - maps[i][j + 1]) <= r) {
					connect[i][j].push_back(i);
					connect[i][j].push_back(j + 1);
					connect[i][j + 1].push_back(i);
					connect[i][j + 1].push_back(j);
				}
			}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				
				if (!visited[i][j]) {
					psearch.push(i);
					psearch.push(j);
					visited[i][j] = 1;
					total = maps[i][j];
					unions.push_back(i);
					unions.push_back(j);
				}
				
				while (!psearch.empty()) {
					xcurr = psearch.front();
					psearch.pop();
					ycurr = psearch.front();
					psearch.pop();

					sizecurr = connect[xcurr][ycurr].size();
					for (int k = 0; k < sizecurr; k += 2) {
						xnext = connect[xcurr][ycurr].at(k);
						ynext = connect[xcurr][ycurr].at(k + 1);

						if (!visited[xnext][ynext]) {
							psearch.push(xnext);
							psearch.push(ynext);
							visited[xnext][ynext] = 1;
							total += maps[xnext][ynext];
							unions.push_back(xnext);
							unions.push_back(ynext);
						}
					}
				}
				
				sizeunion = unions.size();
				if (!sizeunion)
					continue;
				each = total / (sizeunion / 2);
				if (sizeunion > 2) {
					united = true;
					for (int k = 0; k < sizeunion; k += 2) {
						xcurr = unions.at(k);
						ycurr = unions.at(k + 1);
					}
				}
				
				for (int k = 0; k < sizeunion; k += 2){
					xcurr = unions.at(k);
					ycurr = unions.at(k + 1);
					maps[xcurr][ycurr] = each;
				}
				unions.clear();
			}

		if (united) {
			day++;
			united = false;
		}
		else
			break;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				visited[i][j] = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				connect[i][j].clear();
	}

	printf("%d", day);
	
	return 0;
}
