// 2024KB, 0ms

#include <iostream>
#include <string>

using namespace std;

int main() {

	string str, ncurr;

	cin >> str;

	int idx = 0, len = str.length(), sum = 0;

	ncurr = "";

	while (idx < len && str[idx] != '-') {
		if (str[idx] == '+') {
			if (ncurr != "") {
				sum += stoi(ncurr);
				ncurr = "";
			}
		}
		else {
			ncurr += str[idx];
		}
		idx++;
	}

	sum += stoi(ncurr);
	ncurr = "";

	int mid = 0;
	while(idx < len) {

		if (str[idx] == '+') {
			if (ncurr != "") {
				mid += stoi(ncurr);
				ncurr = "";
			}
		}
		else if (str[idx] == '-') {
			if (ncurr != "") {
				mid += stoi(ncurr);
				ncurr = "";
			}

			sum -= mid;
			mid = 0;
		}
		else {
			ncurr += str[idx];
		}

		idx++;
	}

	if (ncurr != "") {
		mid += stoi(ncurr);
		sum -= mid;
	}

	cout << sum;

	return 0;
}
