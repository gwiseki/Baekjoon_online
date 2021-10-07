// 2304KB, 0ms

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string memo[101][101];

string nplus(string a, string b) {

	int shorter, longer, diff, num, alen = a.length(), blen = b.length();

	if (alen > blen) {
		longer = alen;
		shorter = blen;
	}
	else {
		longer = blen;
		shorter = alen;
	}
	diff = longer - shorter;

	if (longer != a.length()) {
		string swaps;
		swaps = a;
		a = b;
		b = swaps;
	}

	for (int i = longer - 1; i >= diff ; i--) {
		num = atoi(a.substr(i, 1).c_str()) + atoi(b.substr(i - diff, 1).c_str());

		if (num < 10)
			a[i] = (char)(num + '0');
		else {
			a[i] = (char)(num % 10 + '0');

			int j = i;
			while (j - 1 >= 0 && a[j - 1] == '9') {
				a[j - 1] = '0';
				j--;
			}
			if (j == 0) {
				a = '1' + a;
				longer++; diff++; i++;
			}
			else
				a[j - 1] ++;
			
		}
	}
	
	return a;
}

string combination(int n, int r) {

	string ret;

	if (n == r || r == 0)
		return "1";
	else {
		if (memo[n - 1][r - 1] == "0")
			memo[n - 1][r - 1] = combination(n - 1, r - 1);
		ret = memo[n - 1][r - 1];

		if (memo[n - 1][r] == "0")
			memo[n - 1][r] = combination(n - 1, r);
		ret = nplus(ret, memo[n - 1][r]);

		return ret;
	}
}

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			memo[i][j] = "0";

	cout << combination(n, m);

	return 0;
}
