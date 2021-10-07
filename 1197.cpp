// 3584KB, 260ms

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public :
	int start;
	int end;
	int weight;

	Edge(int start, int end, int weight) {
		this->start = start;
		this->end = end;
		this->weight = weight;
	}

	bool operator< (const Edge &edge) const {
		return (this->weight) < edge.weight;
	}
};

vector<Edge> edges;
int parent[10005];

int find_parent(int x) {
	while (parent[x] != x)
		x = parent[x];
	return x;
}

void make_union(int x, int y) {

	x = find_parent(x);
	y = find_parent(y);

	if (x != y)
		parent[y] = x;
}

int main() {

	int v, e, start, end, weight, idx = 0, MSTweight = 0, edgecnt = 0;

	scanf("%d %d", &v, &e);

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &start, &end, &weight);
		edges.push_back(Edge(start, end, weight));
	}

	sort(edges.begin(), edges.end());

	while(edgecnt < v - 1 && idx < e) {
		Edge curredge = edges.at(idx);
		if (find_parent(curredge.start) == find_parent(curredge.end)) {
			idx++;
			continue;
		}

		make_union(curredge.start, curredge.end);
		idx++; edgecnt++;
		MSTweight += curredge.weight;
	}

	printf("%d", MSTweight);

	return 0;
}
