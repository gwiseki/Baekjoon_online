// 17432KB, 2276ms

#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

multiset<int> ms;

int main() {

	int T, oprs, num;
	string curr;

	getline(cin, curr);
	T = atoi(curr.substr(0, curr.length()).c_str());

	for (int tc = 0; tc < T; tc++) {
		getline(cin, curr);
		oprs = atoi(curr.substr(0, curr.length()).c_str());

		ms.clear();

		for (int i = 0; i < oprs; i++) {
			getline(cin, curr);

			if (curr[0] == 'I') {
				num = atoi(curr.substr(2, curr.length() - 2).c_str());
				ms.insert(num);
			}
			else {
				if (!ms.size())
					continue;
				else {
					if (curr[2] == '1')
						ms.erase(prev(ms.end()));
					else
						ms.erase(ms.begin());
				}
				
			}
		}

		if (ms.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *(prev(ms.end())) << ' ' << *(ms.begin()) << '\n';
	}

	return 0;
}
