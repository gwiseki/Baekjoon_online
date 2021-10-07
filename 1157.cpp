// 4876KB, 40ms

#include <iostream>
#include <string>

using namespace std;

int chars[30] = { 0, };

int main() {

	int len, max = 0, anschar;
	string input;
	char curr, answer;

	cin >> input;

	len = input.length();

	for (int i = 0; i < len; i++) {
		curr = input[i];
		if (curr >= 'a' && curr <= 'z')
			chars[curr - 'a']++;
		else
			chars[curr - 'A']++;
	}

	for (int i = 0; i < 26; i++)
		if (max < chars[i]) {
			max = chars[i];
			anschar = i;
		}

	answer = anschar + 'A';

	for (int i = 0; i < 26; i++)
		if (max == chars[i] && anschar != i) {
			answer = '?';
			break;
		}
	
	if (answer == '?') {
		cout << '?' << '\n';
		return 0;
	}

	cout << answer << '\n';

	return 0;
}
