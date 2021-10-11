// 1176KB, 0ms

#include <cstdio>
#include <list>

using namespace std;

list<int> li;

int main() {

	int n, k, rpt;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		li.push_back(i);

    printf("<");
	list<int>::iterator iter = li.begin();
	list<int>::iterator copy;
	for (int i = 0; i < n - 1; i++) {

		rpt = ( k - 1 )% li.size();
		for (int j = 0; j < rpt; j++) {
			if (iter == li.end()) {
				iter = li.begin();
				iter++;
				continue;
			}
			iter++;
		}

		if (iter == li.end()) 
			iter = li.begin();
		
		printf("%d, ", *iter);
		copy = iter;
		iter++;
		li.erase(copy);
	}
    if (iter == li.end())
		iter = li.begin();
	printf("%d>", *iter);

	return 0;
}
