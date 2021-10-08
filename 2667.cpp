// 1232KB, 0ms

#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool maps[28][28];
bool visited[28][28] = { 0, };
stack<int> ms;
vector<int> areas;

int main() {

	int n, xcurr, ycurr, areacurr = 0, areamax;

	scanf("%d", &n);

	areamax = 0;

	char temp[28];

	for (int i = 1; i <= n; i++) {
		scanf("%s", temp);
		for (int j = 1; j <= n; j++)
			maps[i][j] = temp[j - 1] - '0';
	}

	for (int i = 0; i <= n + 1; i++) {
		maps[i][0] = 0;
		maps[i][n + 1] = 0;
		maps[0][i] = 0;
		maps[n + 1][i] = 0;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (maps[i][j] && !visited[i][j]) {

				ms.push(i);
				ms.push(j);
				visited[i][j] = 1;
				areacurr++;

				while (!ms.empty()) {

					ycurr = ms.top();
					ms.pop();
					xcurr = ms.top();
					ms.pop();

					if (maps[xcurr + 1][ycurr] && !visited[xcurr + 1][ycurr]) {
						ms.push(xcurr + 1);
						ms.push(ycurr);
						areacurr++;
						visited[xcurr + 1][ycurr] = 1;
					}
					if (maps[xcurr][ycurr + 1] && !visited[xcurr][ycurr + 1]) {
						ms.push(xcurr);
						ms.push(ycurr + 1);
						areacurr++;
						visited[xcurr][ycurr + 1] = 1;
					}
					if (maps[xcurr - 1][ycurr] && !visited[xcurr - 1][ycurr]) {
						ms.push(xcurr - 1);
						ms.push(ycurr);
						areacurr++;
						visited[xcurr - 1][ycurr] = 1;
					}
					if (maps[xcurr][ycurr - 1] && !visited[xcurr][ycurr - 1]) {
						ms.push(xcurr);
						ms.push(ycurr - 1);
						areacurr++;
						visited[xcurr][ycurr - 1] = 1;
					}

				}
				areas.push_back(areacurr);
				areacurr = 0;
			}

	sort(areas.begin(), areas.end());

	int areas_num = areas.size();

	printf("%d\n", areas_num);

	for (int i = 0; i < areas_num; i++)
		printf("%d\n", areas.at(i));

	return 0;

}
