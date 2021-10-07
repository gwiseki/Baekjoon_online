// 8296KB, 172ms

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class Edge {
public:
	int weight;
	int end;

	Edge(int end, int weight) {
		this->weight = weight;
		this->end = end;
	}

	bool operator < (const Edge &cmp) const {
		return (this->weight) > cmp.weight;
	}
};

priority_queue<Edge> que;
vector<pair<int, int> > roads1[20002];
int dist1[20002];
bool visited[20002];
int n, m, x;

void dijk() {

	dist1[x] = 0;
	que.push(Edge(x, 0));

	while (!que.empty()) {
		Edge curr = que.top();
		que.pop();
		int currp = curr.end;
		int currw = curr.weight;
		int currsize = roads1[currp].size();

		visited[currp] = true;
		for (int i = 0; i < currsize; i++)
		{
			int nextp = roads1[currp].at(i).first;

			if (visited[nextp])
				continue;

			int nextd = dist1[currp] + roads1[currp].at(i).second;

			if (dist1[nextp] > nextd) {
				dist1[nextp] = nextd;
			}
			else
				continue;

			que.push(Edge(nextp, dist1[nextp]));
		}
	}
}

int main() {

	int start, end, w;

	scanf("%d %d %d", &n, &m, &x);

	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &start, &end, &w);
		roads1[start].push_back({ end, w });
	}

	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
		dist1[i] = 2000000;
	}

	dijk();

	for (int i = 1; i <= n; i++) {
		if (dist1[i] == 2000000)
			printf("INF\n");
		else
			printf("%d\n", dist1[i]);
	}

	return 0;
}
