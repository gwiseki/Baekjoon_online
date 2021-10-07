// 2160KB, 0ms

#include <iostream>
#include <string>

using namespace std;

string tree[65];

string search(int n, int x, int y) {

	if (n == 1)
		return to_string(tree[x][y] - '0');

	int hn = n / 2;
	string curr = "";
	
	string ul = search(hn, x, y);
	string ur = search(hn, x, y + hn);
	string ll = search(hn, x + hn, y);
	string lr = search(hn, x + hn, y + hn);

	if (ul == ur && ur == ll && ll == lr
		&& ul.length() == 1
		&& ur.length() == 1
		&& ll.length() == 1
		&& lr.length() == 1)
		curr += ul;
	else {
		curr += "(";
		curr += ul;
		curr += ur;
		curr += ll;
		curr += lr;
		curr += ")";
	}

	return curr;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
	}

	string ans = search(n, 0, 0);

	cout << ans;

	return 0;
}
