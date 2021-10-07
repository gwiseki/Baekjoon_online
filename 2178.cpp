// 1248KB, 0ms

#include <cstdio>
#include <queue>

using namespace std;

bool maps[103][103];
bool visited[103][103] = { 0, };
queue<int> qu;

int main() {
	
	int n, m;
	int xcurr, ycurr, time;
	char ms[103];

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%s", ms);
		for (int j = 1; j <= m; j++)
			maps[i][j] = ms[j - 1] - 48;
	}
		
	for (int i = 0; i <= n + 1; i++) {
		maps[i][0] = 0;
		maps[i][m + 1] = 0;
	}

	for (int i = 0; i <= m + 1; i++) {
		maps[0][i] = 0;
		maps[n + 1][i] = 0;
	}

	qu.push(1);
	qu.push(1);
	qu.push(1);
	visited[1][1] = true;

	while (!qu.empty()) {

		xcurr = qu.front();
		qu.pop();
		ycurr = qu.front();
		qu.pop();
		time = qu.front();
		qu.pop();
		

		if (xcurr == n && ycurr == m)
			break;

		if (maps[xcurr + 1][ycurr] && !visited[xcurr + 1][ycurr]) {
			qu.push(xcurr + 1);
			qu.push(ycurr);
			qu.push(time + 1);
			visited[xcurr + 1][ycurr] = true;
		}
		if (maps[xcurr - 1][ycurr] && !visited[xcurr - 1][ycurr]) {
			qu.push(xcurr - 1);
			qu.push(ycurr);
			qu.push(time + 1);
			visited[xcurr - 1][ycurr] = true;
		}
		if (maps[xcurr][ycurr - 1] && !visited[xcurr][ycurr - 1]) {
			qu.push(xcurr);
			qu.push(ycurr - 1);
			qu.push(time + 1);
			visited[xcurr][ycurr - 1] = true;
		}
		if (maps[xcurr][ycurr + 1] && !visited[xcurr][ycurr + 1]) {
			qu.push(xcurr);
			qu.push(ycurr + 1);
			qu.push(time + 1);
			visited[xcurr][ycurr + 1] = true;
		}
	}

	printf("%d\n", time);

	return 0;
}
