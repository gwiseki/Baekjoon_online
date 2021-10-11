// 1992KB, 448ms

#include <iostream>
#include <string>
#include <set>
#include <cstring>

using namespace std;

set<int> ms, oneto20;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, num;
	string curr;
	set<int>::iterator iter;

	getline(cin, curr);
	m = atoi(curr.c_str());

	for (int i = 1; i <= 20; i++)
		oneto20.insert(i);

	for (int tc = 0; tc < m; tc++) {

		getline(cin, curr);

		switch (curr[0]) {
		case 'a':
			if (curr[1] == 'd')
				ms.insert(atoi(curr.substr(4, curr.length() - 4).c_str()));
			else
				ms = oneto20;
			break;
		case 'r':
			iter = ms.find(atoi(curr.substr(7, curr.length() - 7).c_str()));
			if (iter == ms.end())
				break;
			else
				ms.erase(iter);
			break;
		case 'c':
			if (ms.find(atoi(curr.substr(6, curr.length() - 6).c_str())) == ms.end())
				cout << '0' << '\n';
			else
				cout << '1' << '\n';
			break;
		case 't':
			num = atoi(curr.substr(7, curr.length() - 7).c_str());
			iter = ms.find(num);

			if (iter == ms.end())
				ms.insert(num);
			else
				ms.erase(iter);
			break;
		case 'e':
			ms.clear();
			break;
		}

	}

	return 0;
}
