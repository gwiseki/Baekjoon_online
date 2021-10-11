// 8928KB, 320ms

#include <cstdio>
#include <algorithm>

using namespace std;

struct ipair {
	int num;
	int order;
};

int a[500005];
int cnt[500005];
ipair b[500005];

bool cmp(ipair a, ipair b) {
	return a.num < b.num;
}

int main() {

	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i].num);
		b[i].order = i;
	}
	sort(b, b + m, cmp);

	int x = 0, y = 0;
	while (x < m && y < n) {

		if (b[x].num == a[y]) {
			cnt[b[x].order] ++;
			y++;
			continue;
		}
		else if (b[x].num < a[y]) 
			x++;
		
		else if (b[x].num > a[y]) 
			y++;
	}

	for (int i = 0; i < m - 1; ++i)	
		if (b[i].num == b[i + 1].num)		
			cnt[b[i + 1].order] = cnt[b[i].order];
		
	for (int i = 0; i < m; ++i)
		printf("%d ", cnt[i]);

	return 0;
}
