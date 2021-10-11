// 1988KB, 304ms

#include <deque>
#include <string>
#include <iostream>

using namespace std;

deque<int> myq;

int main() {

	int n, clen, num;
	string curr;

	getline(cin, curr);
	n = atoi(curr.c_str());

	for (int i = 0; i < n; i++) {
		getline(cin, curr);

		switch (curr[0]) {
		case 'p' :
			if (curr.substr(0, 3) == "pop") {
				if (myq.empty()) {
					printf("-1\n");
					break;
				}
				else {
					if (curr[4] == 'f') {
						printf("%d\n", myq.front());
						myq.pop_front();
					}
					else {
						printf("%d\n", myq.back());
						myq.pop_back();
					}
				}
			}
			else {
				clen = curr.length();
				
				if (curr[5] == 'f') {
					num = atoi(curr.substr(11, clen - 11).c_str());
					myq.push_front(num);
				}
				else {
					num = atoi(curr.substr(10, clen - 10).c_str());
					myq.push_back(num);
				}
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
