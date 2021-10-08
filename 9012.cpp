// 1224KB, 0ms

#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

char par[51];
stack<char> mys;

int main() {

	int T, plen;
	bool isvps;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {

		isvps = true;
		scanf("%s", par);

		plen = strlen(par);

		while (!mys.empty())
			mys.pop();

		for (int i = 0; i < plen; i++) {
			if (par[i] == '(')
				mys.push('(');
			else {
				if (mys.empty()) {
					isvps = false;
					break;
				}
				else 
					mys.pop();
			}
		}

		if (!mys.empty())
			isvps = false;

		if (isvps)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
