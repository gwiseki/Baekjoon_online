// 1232KB, 0ms

#include <cstdio>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<int, int> ladder;
queue<int> bfs, cnt;
bool visited[101];

int main() {

	int n, m, answer = 0;
	bool moved, visits;
	int curr, currcnt, next, xtemp, ytemp;

	for (int i = 0; i < 101; i++)
		visited[i] = false;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &xtemp, &ytemp);
		ladder[xtemp] = ytemp;
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &xtemp, &ytemp);
		ladder[xtemp] = ytemp;
	}

	bfs.push(1);
	cnt.push(0);
	visited[1] = true;
	while (!bfs.empty() && !answer) {
		curr = bfs.front();
		bfs.pop();
		currcnt = cnt.front();
		cnt.pop();
		
		for (int i = 1; i <= 6; i++)
		{
			visits = false;
			moved = false;
			next = curr + i;

			if (next > 100)
				break;

			if (visited[next])
				continue;

			if (next == 100) {
				answer = currcnt + 1;
				break;
			}

			visited[next] = true;

			int nextLadder = ladder[next];
			int prevLadder;
			while (nextLadder) {
				if (visited[nextLadder]) {
					visits = true;
					break;
				}
				visited[nextLadder] = true;
				moved = true;
				prevLadder = nextLadder;
				nextLadder = ladder[nextLadder];
			}

			if (moved) {
				bfs.push(prevLadder);
				cnt.push(currcnt + 1);
				continue;
			}

			if (visits) {
				continue;
			}

			if (!moved) {
				bfs.push(next);
				cnt.push(currcnt + 1);
			}
		}
	}

	printf("%d", answer);

	return 0;
}
