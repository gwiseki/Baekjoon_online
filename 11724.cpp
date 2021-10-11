// 2160KB, 128ms

#include <cstdio>
#include <vector>

using namespace std;

bool con[1005][1005];
bool chck[1005];
vector<int> srch;

int main() {

	int n, m, x, y, curr, cnt = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);

		con[x][y] = true;
		con[y][x] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (!chck[i]) {
			srch.push_back(i);
			chck[i] = true;
			cnt++;
		}

		while (!srch.empty()) {
			curr = srch.back();
			srch.pop_back();

			for (int j = 1; j <= n; j++){
				if (con[curr][j]) {
					if (!chck[j]) {
						srch.push_back(j);
						chck[j] = true;
					}
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
