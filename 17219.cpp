// 15536KB, 116ms

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> lst;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string site, pw;
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		cin >> site >> pw;
		lst.insert(make_pair(site, pw));
	}

	for (int i = 0; i < m; i++){
		cin >> pw;
		cout << lst[pw] << '\n';
	}

	return 0;
}
