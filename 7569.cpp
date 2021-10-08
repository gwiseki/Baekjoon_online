// 6976KB, 104ms

#include <cstdio>
#include <queue>

using namespace std;

int maps[103][103][103];
queue<int> bfs;

int main() {

	int m, n, h, currsize, answer = 0;
	int ic, jc, kc;
	bool isolate, finish;

	scanf("%d %d %d", &n, &m, &h);

	for (int k = 0; k < h; k++)
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &maps[k][i][j]);
				if (maps[k][i][j] == 1) {
					bfs.push(k);
					bfs.push(i);
					bfs.push(j);
				}
			}

	while (1) {

		currsize = bfs.size() / 3;

		for (int z = 0; z < currsize; z++) {

			kc = bfs.front();
			bfs.pop();
			ic = bfs.front();
			bfs.pop();
			jc = bfs.front();
			bfs.pop();

			if (ic + 1 < m && maps[kc][ic + 1][jc] == 0) {
				maps[kc][ic + 1][jc] = 1;
				bfs.push(kc);
				bfs.push(ic + 1);
				bfs.push(jc);
			}

			if (ic - 1 >= 0 && maps[kc][ic - 1][jc] == 0) {
				maps[kc][ic - 1][jc] = 1;
				bfs.push(kc);
				bfs.push(ic - 1);
				bfs.push(jc);
			}

			if (jc + 1 < n && maps[kc][ic][jc + 1] == 0) {
				maps[kc][ic][jc + 1] = 1;
				bfs.push(kc);
				bfs.push(ic);
				bfs.push(jc + 1);
			}

			if (jc - 1 >= 0 && maps[kc][ic][jc - 1] == 0) {
				maps[kc][ic][jc - 1] = 1;
				bfs.push(kc);
				bfs.push(ic);
				bfs.push(jc - 1);
			}

			if (kc + 1 < h && maps[kc + 1][ic][jc] == 0) {
				maps[kc + 1][ic][jc] = 1;
				bfs.push(kc + 1);
				bfs.push(ic);
				bfs.push(jc);
			}

			if (kc - 1 >= 0 && maps[kc - 1][ic][jc] == 0) {
				maps[kc - 1][ic][jc] = 1;
				bfs.push(kc - 1);
				bfs.push(ic);
				bfs.push(jc);
			}
		}

		if (!bfs.empty())
			answer++;
		else
			break;
	}

	//isolate check
	isolate = false;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				if (maps[k][i][j] == 0) {
					isolate = true;
					break;
				}
			if (isolate)
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
