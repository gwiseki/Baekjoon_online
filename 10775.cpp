// 1504KB, 16ms

#include <vector>
#include <cstdio>

using namespace std;

int parent[100004];

int find_parent(int x) {
	while (parent[x] != x)
		x = parent[x];
	return x;
}

int main() {

	int g, p, gi, currp, nextp, cnt = 0;

	scanf("%d %d", &g, &p);

	for (int i = 0; i <= g; i++)
		parent[i] = i;

	for (int i = 0; i < p; i++){
		scanf("%d", &gi);
		currp = find_parent(gi);
		if (currp == gi) {
			parent[gi] = find_parent(gi - 1);
			cnt++;
		}
		else {
			if (currp) {
				parent[gi] = parent[currp] = find_parent(currp - 1);
				cnt++;
			}
			else
				break;
		}
	}
	printf("%d", cnt);

	return 0;
}
