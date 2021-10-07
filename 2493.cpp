// 11232KB, 148ms

#include <vector>
#include <cstdio>

using namespace std;

int tops[500005];
int answers[500005];
vector<pair<int, int>> s;

int main() {

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &tops[i]);

	int j = n;
	s.push_back(make_pair(tops[n], n));

	for (int i = n - 1; i >= 1; i--){
		while (!s.empty() && s.back().first < tops[i]) {
			answers[s.back().second] = i;
			s.pop_back();
		}
		s.push_back(make_pair(tops[i], i));
	}

	while (!s.empty()) {
		answers[s.back().second] = 0;
		s.pop_back();
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", answers[i]);

	return 0;
}
