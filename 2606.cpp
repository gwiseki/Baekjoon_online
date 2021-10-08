// 1232KB, 0ms

#include <cstdio>
#include <vector>

using namespace std;

vector<int> con[105];
vector<int> dfs;
bool checked[105];

int main() {

	int n, edges, x, y, curr, csize, search, cnt = 0;

	scanf("%d", &n);
	scanf("%d", &edges);

	for (int i = 1; i <= edges; i++) {
		scanf("%d %d", &x, &y);

		con[x].push_back(y);
		con[y].push_back(x);
	}

	dfs.push_back(1);
	checked[1] = true;

	while (!dfs.empty()) {
		curr = dfs.back();
		dfs.pop_back();

		csize = con[curr].size();
		for (int i = 0; i < csize; i++) {

			search = con[curr].at(i);
			if (!checked[search]) {
				dfs.push_back(search);
				checked[search] = true;
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
