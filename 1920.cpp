// 1892KB, 68ms

#include <cstdio>
#include <algorithm>

using namespace std;

int a[100005], b[100005];

int main() {

	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	bool exist;
	for (int i = 0; i < m; i++) {
		exist = false;
		if (binary_search(a, a + n, b[i])) 
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
