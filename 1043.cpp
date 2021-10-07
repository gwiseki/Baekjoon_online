// 1128KB, 0ms

#include <cstdio>

using namespace std;

int parent[54];
int party[54][54];

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

	int n, m, t, truth, nvisits, first, cnt = 0;
	bool istheretruth;

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &truth);
		parent[truth] = 0;
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d", &nvisits);
		party[i][0] = nvisits;
		scanf("%d", &first);
		party[i][1] = first;
		
		if (!find_parent(first)) {
			for (int j = 2; j <= nvisits; j++) {
				scanf("%d", &party[i][j]);
				make_union(first, party[i][j]);
			}
		}
		else {
			for (int j = 2; j <= nvisits; j++) {
				scanf("%d", &party[i][j]);
				if (!find_parent(party[i][j]))
					make_union(party[i][j], first);
				else 
					make_union(first, party[i][j]);
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		nvisits = party[i][0];
		istheretruth = false;
		for (int j = 1; j <= nvisits; j++) {
			if (!find_parent(party[i][j])) {
				istheretruth = true;
				break;
			}
		}

		if (!istheretruth)
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}
