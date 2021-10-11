// 1988KB, 304ms

#include <queue>
#include <string>
#include <iostream>

using namespace std;

queue<int> myq;

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
				if (myq.empty())
					printf("-1\n");
				else {
					printf("%d\n", myq.front());
					myq.pop();
				}
			}
			else {
				num = atoi(curr.substr(5, clen - 5).c_str());
				myq.push(num);
			}
			break;
		case 's' :
			printf("%d\n", myq.size());
			break;
		case 'f' :
			if (myq.empty())
				printf("-1\n");
			else
				printf("%d\n", myq.front());
			break;
		case 'b':
			if (myq.empty())
				printf("-1\n");
			else
				printf("%d\n", myq.back());
			break;
		case 'e' :
			printf("%d\n", myq.empty());
			break;
		default :
			break;
		}
	}

	return 0;
}
