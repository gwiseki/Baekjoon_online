// 4760KB, 740ms

#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int, string>> lists;

int main() {

	int n, lsize;
	string curr;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> curr;
		lists.insert({ curr.length(), curr });
	}

	lsize = lists.size();

	for (auto now : lists)
		cout << now.second << endl;
	return 0;
}
