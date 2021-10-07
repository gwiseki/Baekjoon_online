// 1388KB, 4ms

#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> ms;
queue<int> mq;
vector<int> maps[1002];
bool visit[1002];

int main() {

	int n, m, v, a, b, curr, search, maps_size;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 1; i <= n; i++)
		visit[i] = 0;

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);

		maps[a].push_back(b);
		maps[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(maps[i].begin(), maps[i].end());

	ms.push(v);
	while (!ms.empty()) {
		curr = ms.top();
		ms.pop();
		if (!visit[curr]) {
			printf("%d ", curr);
			visit[curr] ++;
		}

		maps_size = maps[curr].size();

		for (int i = maps_size - 1; i >= 0; i--) {
			search = maps[curr].at(i);
			if (search && !visit[search])
				ms.push(search);
		}
	}
	printf("\n");

	for (int i = 1; i <= n; i++)
		visit[i] = 0;

	mq.push(v);
	while (!mq.empty()) {
		curr = mq.front();
		mq.pop();

		if (!visit[curr]) {
			printf("%d ", curr);
			visit[curr] ++;
		}

		maps_size = maps[curr].size();

		for (int i = 0; i < maps_size; i++) {
			search = maps[curr].at(i);
			if (search && !visit[search])
				mq.push(search);
		}
	}
		return 0;
}
