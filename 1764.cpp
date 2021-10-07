// 12296KB, 56ms

#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> names;
vector<string> lists;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, cnt = 0, lsize;
	string lname;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> lname;
		names[lname]++;
	}

	for (int i = 0; i < m; i++) {
		cin >> lname;
		if (names[lname]) {
			cnt++;
			lists.push_back(lname);
		}
	}

	sort(lists.begin(), lists.end());

	cout << cnt;
	for (int i = 0; i < cnt; i++)
		cout << '\n' << lists.at(i);

	return 0;
}
