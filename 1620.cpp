// 19532KB, 108ms

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> nameplist;
vector<string> namelist;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string name;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> name;
		namelist.push_back(name);
		nameplist[name] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> name;

		if (name[0] >= '0' && name[0] <= '9')
			cout << *(&namelist.at(0) + atoi(name.c_str()) - 1) << '\n';
		else 
			cout << nameplist[name] + 1 << '\n';
	}

	return 0;
}
