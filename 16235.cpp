// 1772KB, 88ms

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int A[12][12];
int nutrt[12][12];
vector<int> trees[12][12];
vector<int> dead[12][12];
vector<int> alive[12][12];

int main() {
	int n, m, k, xcurr, ycurr, agecurr, trees_size, answer = 0;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &A[i][j]);

	for (int i = 0; i <= n + 1; i++) {
		nutrt[i][0] = -1;
		nutrt[i][n + 1] = -1;
		nutrt[0][i] = -1;
		nutrt[n + 1][i] = -1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			nutrt[i][j] = 5;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &xcurr, &ycurr, &agecurr);
		trees[xcurr][ycurr].push_back(agecurr);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			trees_size = trees[i][j].size();
			if (trees_size > 2)
				sort(trees[i][j].begin(), trees[i][j].end());
		}
	
	for (int y = 0; y < k; y++) {
		//spring
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {

				trees_size = trees[i][j].size();
				for (int s = 0; s < trees_size; s++) {
					agecurr = trees[i][j].at(s);

					if (nutrt[i][j] >= agecurr) {
						nutrt[i][j] -= agecurr;
						alive[i][j].push_back(agecurr + 1);
					}

					else
						dead[i][j].push_back(agecurr);
				}
				trees[i][j].clear();
			}

		//summer
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				trees_size = dead[i][j].size();
				if (trees_size)
					for (int s = 0; s < trees_size; s++)
						nutrt[i][j] += dead[i][j].at(s) / 2;
				dead[i][j].clear();
			}

		//fall
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {

				trees_size = alive[i][j].size();
				for (int s = 0; s < trees_size; s++) {
					agecurr = alive[i][j].at(s);

					if (!(agecurr % 5)) {
						if (nutrt[i - 1][j] != -1)
							trees[i - 1][j].push_back(1);

						if (nutrt[i - 1][j + 1] != -1)
							trees[i - 1][j + 1].push_back(1);

						if (nutrt[i][j + 1] != -1)
							trees[i][j + 1].push_back(1);

						if (nutrt[i + 1][j + 1] != -1)
							trees[i + 1][j + 1].push_back(1);

						if (nutrt[i + 1][j] != -1)
							trees[i + 1][j].push_back(1);

						if (nutrt[i + 1][j - 1] != -1)
							trees[i + 1][j - 1].push_back(1);

						if (nutrt[i][j - 1] != -1)
							trees[i][j - 1].push_back(1);

						if (nutrt[i - 1][j - 1] != -1)
							trees[i - 1][j - 1].push_back(1);
					}
				}
			}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {

				trees_size = alive[i][j].size();
				for (int s = 0; s < trees_size; s++) {
					agecurr = alive[i][j].at(s);
					trees[i][j].push_back(agecurr);
				}
				alive[i][j].clear();
			}
		//winter
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				nutrt[i][j] += A[i][j];
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			answer += trees[i][j].size();

	printf("%d", answer);

	return 0;
}
