// 2700KB, 0ms

#include <iostream>
#include <queue>

using namespace std;

int visited[150010];
queue<int> vst;

int main() {

	int x, y, curr;

	cin >> x >> y;

	vst.push(x);

	while (!vst.empty()) {
		curr = vst.front();
		vst.pop();

		if (curr == y)
			break;

		if (curr + 1 <= 150000 && !visited[curr + 1]) {
			vst.push(curr + 1);
			visited[curr + 1] = visited[curr] + 1;
		}
		if (curr - 1 >= 0 && !visited[curr - 1]) {
			vst.push(curr - 1);
			visited[curr - 1] = visited[curr] + 1;
		}
		if (curr * 2 <= 150000 && !visited[curr * 2]) {
			vst.push(curr * 2);
			visited[curr * 2] = visited[curr] + 1;
		}
	}

	cout << visited[y];

	return 0;
}
