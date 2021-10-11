// 9284KB, 40ms

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {

	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return a.second < b.second;
	else 
		return false;
	
}

int main() {
    
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, ncurr;
	string scurr;

	vector<pair<int, int>> pp;
	vector<string> mlist;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ncurr >> scurr;

		mlist.push_back(scurr);
		pp.push_back({ ncurr, i });
	}

	sort(pp.begin(), pp.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << pp.at(i).first << ' ' << *(&mlist.at(0) + pp.at(i).second) << '\n';

	return 0;
}
