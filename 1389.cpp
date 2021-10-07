// 1276KB, 0ms

#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int mins[102][102];
int bacon[102];
vector<int> rel[102];
int n, m;

int bfs(int mfrom, int mto) {

	bool visited[102];
	queue<int> que;
    
    for(int i = 1; i <= n; i ++)
        visited[i] = false;

	que.push(mfrom);
	que.push(0);
	visited[mfrom] = true;
	while (!que.empty()) {
		int mcurr = que.front();
		que.pop();
		int mw = que.front();
		que.pop();

		int csize = rel[mcurr].size(), mnext;
		for (int i = 0; i < csize; i++) {
			mnext = rel[mcurr].at(i);
			if (mnext == mto)
				return mw + 1;
			else {
				if (visited[mnext])
					continue;

				que.push(mnext);
				que.push(mw + 1);
				visited[mnext] = true;
			}
		}
	}
    
    return -1;
}

int main() {

	int a, b;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mins[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		rel[a].push_back(b);
		rel[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!mins[i][j]) {
				mins[i][j] = bfs(i, j);
				mins[j][i] = mins[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			bacon[i] += mins[i][j];
	}

	int minval = 10000000;
	for (int i = 1; i <= n; i++) {
		if (minval > bacon[i])
			minval = bacon[i];
	}

	for (int i = 1; i <= n; i++) {
		if (minval == bacon[i]) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}
