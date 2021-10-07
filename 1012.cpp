//1232KB, 0ms
#include <cstdio>
#include <vector>

using namespace std;

bool maps[55][55];
bool checked[55][55];
vector<int> dfs;

int main() {

	int T, m, n, k, x, y, xcurr, ycurr, cnt;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {

		scanf("%d %d %d", &m, &n, &k);

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				maps[i][j] = false;
				checked[i][j] = false;
			}
		cnt = 0;

		for (int i = 0; i <= m + 1; i++) {
			checked[i][0] = true;
			checked[i][n + 1] = true;
		}

		for (int i = 0; i <= n + 1; i++) {
			checked[0][i] = true;
			checked[m + 1][i] = true;
		}

		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			maps[x + 1][y + 1] = true;
		}

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (maps[i][j] && !checked[i][j]) {
					dfs.push_back(i);
					dfs.push_back(j);
					checked[i][j] = true;
					cnt++;

					while (!dfs.empty()) {
						ycurr = dfs.back();
						dfs.pop_back();
						xcurr = dfs.back();
						dfs.pop_back();

						if (maps[xcurr + 1][ycurr] && !checked[xcurr + 1][ycurr]) {
							dfs.push_back(xcurr + 1);
							dfs.push_back(ycurr);
							checked[xcurr + 1][ycurr] = true;
						}

						if (maps[xcurr][ycurr + 1] && !checked[xcurr][ycurr + 1]) {
							dfs.push_back(xcurr);
							dfs.push_back(ycurr + 1);
							checked[xcurr][ycurr + 1] = true;
						}

						if (maps[xcurr - 1][ycurr] && !checked[xcurr - 1][ycurr]) {
							dfs.push_back(xcurr - 1);
							dfs.push_back(ycurr);
							checked[xcurr - 1][ycurr] = true;
						}

						if (maps[xcurr][ycurr - 1] && !checked[xcurr][ycurr - 1]) {
							dfs.push_back(xcurr);
							dfs.push_back(ycurr - 1);
							checked[xcurr][ycurr - 1] = true;
						}
					}
				}

		printf("%d\n", cnt);

	}
	return 0;
}
