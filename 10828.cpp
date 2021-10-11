// 1988KB, 308ms

#include <cstdio>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

stack<int> mys;

int main() {

	int n, clen, num;
	string curr;

	getline(cin, curr);
	n = atoi(curr.c_str());

	for (int i = 0; i < n; i++) {
		getline(cin, curr);

		switch (curr[0]) {
		case 'p' :
			clen = curr.length();

			if (clen == 3) {
				if (mys.empty())
					printf("-1\n");
				else {
					printf("%d\n", mys.top());
					mys.pop();
				}
			}
			else {
				num = atoi(curr.substr(5, clen - 5).c_str());
				mys.push(num);
			}
			break;
		case 's' :
			printf("%d\n", mys.size());
			break;
		case 't' :
			if (mys.empty())
				printf("-1\n");
			else
				printf("%d\n", mys.top());
			break;
		case 'e' :
			printf("%d\n", mys.empty());
			break;
		default :
			break;
		}
	}

	return 0;
}
