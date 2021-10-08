// 1984KB, 4ms

#include <iostream>
#include <string>

using namespace std;

int main() {

	int T, count, answer, csize;
	string curr;

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		answer = count = 0;
		cin >> curr;

		csize = curr.length();
		for (int i = 0; i < csize; i++) {
			if (curr[i] == 'O') {
				count++;
				answer += count;
			}
			else
				count = 0;
		}
		cout << answer << endl;

	}

	return 0;
}
