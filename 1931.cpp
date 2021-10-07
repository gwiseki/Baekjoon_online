// 3532KB, 84ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> lists;

int main() {

	int n, start, end, next, cnt = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> start >> end;
		lists.push_back({ end, start });
	}

	sort(lists.begin(), lists.end());
	
	next = lists.at(0).first;
	cnt++;
	for (int i = 1; i < n; i++)
		if (next <= lists.at(i).second) {
			next = lists.at(i).first;
			cnt++;
		}
	cout << cnt;
	
	return 0;
}
