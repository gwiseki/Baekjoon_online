// 1236KB, 148ms

#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> shortList;
bool visited[22][22];
int maps[22][22], distMaps[22][22];
int n, sx, sy, nextx, nexty, distToNext;
int time = 0, eaten = 0, ssize = 2;

int getDist(int x, int y);

bool eatenAll() {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (maps[i][j] && maps[i][j] != 9)
				return false;

	return true;
}

int getShortestDistAndPos() {

	int shortDist = 1000;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (maps[i][j] && maps[i][j] < ssize) {
				distMaps[i][j] = getDist(i, j);
				if (shortDist > distMaps[i][j])
					shortDist = distMaps[i][j];
			}
			else 
				distMaps[i][j] = 1000;
		}

	if (shortDist == 1000)
		return 0;

	shortList.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (distMaps[i][j] == shortDist)
				shortList.push_back({ i, j });

	int lsize = shortList.size();

	if (lsize > 1)
		sort(shortList.begin(), shortList.end());

	nextx = shortList.front().first;
	nexty = shortList.front().second;

	return shortDist;
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &maps[i][j]);
			if (maps[i][j] == 9) {
				sx = i; sy = j;
			}
		}

	distToNext = getShortestDistAndPos();
	while (!eatenAll() && distToNext) {

		maps[sx][sy] = 0;
		sx = nextx;
		sy = nexty;
		maps[sx][sy] = 9;

		time += distToNext;
		eaten++;

		if (eaten >= ssize) {
			ssize++;
			eaten = 0;
		}

		distToNext = getShortestDistAndPos();
	}

	printf("%d", time);

	return 0;
}

int getDist(int x, int y) {

	int currx, curry, currd;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;

	queue<int> bfs;
	bfs.push(sx);
	bfs.push(sy);
	bfs.push(0);

	while (!bfs.empty()) {
		currx = bfs.front();
		bfs.pop();
		curry = bfs.front();
		bfs.pop();
		currd = bfs.front();
		bfs.pop();
		visited[currx][curry] = true;

		if (!visited[currx + 1][curry] && currx + 1 < n && maps[currx + 1][curry] <= ssize) {
			if (currx + 1 == x && curry == y) 
				return currd + 1;
			else {
				bfs.push(currx + 1);
				bfs.push(curry);
				bfs.push(currd + 1);
				visited[currx + 1][curry] = true;
			}
		}

		if (!visited[currx][curry + 1] && curry + 1 < n && maps[currx][curry + 1] <= ssize) {
			if (currx == x && curry + 1 == y)
				return currd + 1;
			else {
				bfs.push(currx);
				bfs.push(curry + 1);
				bfs.push(currd + 1);
				visited[currx][curry + 1] = true;
			}
		}

		if (!visited[currx - 1][curry] && currx >= 1 && maps[currx - 1][curry] <= ssize) {
			if (currx - 1 == x && curry == y)
				return currd + 1;
			else {
				bfs.push(currx - 1);
				bfs.push(curry);
				bfs.push(currd + 1);
				visited[currx - 1][curry] = true;
			}
		}

		if (!visited[currx][curry - 1] && curry >= 1 && maps[currx][curry - 1] <= ssize) {
			if (currx == x && curry - 1 == y)
				return currd + 1;
			else {
				bfs.push(currx);
				bfs.push(curry - 1);
				bfs.push(currd + 1);
				visited[currx][curry - 1] = true;
			}
		}
	}

	return 1000;
}
