// 9316KB, 100ms

#include <cstdio>
#include <queue>

using namespace std;

int maps[1003][1003];
queue<int> bfs;

int main() {

	int m, n, currsize, answer = 0;
	int ic, jc;
	bool isolate;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &maps[i][j]);
			if (maps[i][j] == 1) {
				bfs.push(i);
				bfs.push(j);
			}
		}

	while (1) {

		currsize = bfs.size() / 2;

		for (int z = 0; z < currsize; z++) {

			ic = bfs.front();
			bfs.pop();
			jc = bfs.front();
			bfs.pop();

			if (ic + 1 < m && maps[ic + 1][jc] == 0) {
				maps[ic + 1][jc] = 1;
				bfs.push(ic + 1);
				bfs.push(jc);
			}

			if (ic - 1 >= 0 && maps[ic - 1][jc] == 0) {
				maps[ic - 1][jc] = 1;
				bfs.push(ic - 1);
				bfs.push(jc);
			}

			if (jc + 1 < n && maps[ic][jc + 1] == 0) {
				maps[ic][jc + 1] = 1;
				bfs.push(ic);
				bfs.push(jc + 1);
			}

			if (jc - 1 >= 0 && maps[ic][jc - 1] == 0) {
				maps[ic][jc - 1] = 1;
				bfs.push(ic);
				bfs.push(jc - 1);
			}
			
		}

		if (!bfs.empty())
			answer++;
		else
			break;
	}

	//isolate check
	isolate = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (maps[i][j] == 0) {
				isolate = true;
				break;
			}
		if (isolate)
			break;
	}

	if (isolate) 
		answer = -1;

	printf("%d", answer);

	return 0;
}
