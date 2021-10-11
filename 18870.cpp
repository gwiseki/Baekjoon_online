// 12832KB, 596ms

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct trip {
	int val;
	int idx1;
	int idx2;
};

trip lst[1000000];

bool cmp_first(trip a, trip b) {
	
	return a.val < b.val;
}

bool cmp_second(trip a, trip b) {
	return a.idx1 < b.idx1;
}

int main() {

	int n, idx = 0;
	trip currtrip;

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &currtrip.val);
		currtrip.idx1 = i;
		currtrip.idx2 = 0;

		lst[i] = currtrip;
	}

	sort(lst, lst + n, cmp_first);

	for (int i = 0; i < n - 1; i++) {
		lst[i].idx2 = idx;
		if (lst[i].val != lst[i + 1].val)
			idx++;
	}

	lst[n - 1].idx2 = idx;

	sort(lst, lst + n, cmp_second);

	for (int i = 0; i < n; i++)
		printf("%d ", lst[i].idx2);

	return 0;
}
