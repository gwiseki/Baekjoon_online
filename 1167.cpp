// 8532KB, 120ms

#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

vector<pair<int, int> > links[100005];
stack<pair<int, int> > dfs;
vector<int> maxinfo;
bool visited[100005];

void find() {

	int maxp, max = 0;
	while (!dfs.empty()) {
		int currp = dfs.top().first;
		int currw = dfs.top().second;
		int currsize = links[currp].size();
		dfs.pop();

		bool pushed = false;
		for (int i = 0; i < currsize; i++)
		{
			int nextp = links[currp].at(i).first;
			if (!visited[nextp]) {
				visited[nextp] = true;
				dfs.push({ nextp, currw + links[currp].at(i).second });
				pushed = true;
			}
		}

		if (!pushed) {
			if (max < currw) {
				max = currw;
				maxp = currp;
			}
		}
	}

	maxinfo.push_back(max);
	maxinfo.push_back(maxp);
}

int main() {

	int v, maxp, max = 0;
	int start, to, w, dstart;

	scanf("%d", &v);

	for (int k = 0; k < v; k++)
	{
		scanf("%d", &start);

		scanf("%d", &to);

		while (to != -1) {
			scanf("%d", &w);

			links[start].push_back({ to, w });

			scanf("%d", &to);
		}
	}

	for (int k = 1; k <= v; k++)
	{
		if (links[k].size() == 1) {
			dstart = k;
			break;
		}
	}

	for (int k = 1; k <= v; k++)
	{
		visited[k] = false;
	}
	visited[dstart] = true;
	dfs.push({ dstart, 0 });
	find();

	dstart = maxinfo.at(1);
	for (int k = 1; k <= v; k++)
	{
		visited[k] = false;
	}
	visited[dstart] = true;
	dfs.push({ dstart, 0 });
	maxinfo.clear();
	find();

	printf("%d", maxinfo.at(0));

	return 0;
}
