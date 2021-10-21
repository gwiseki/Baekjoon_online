// 1424KB, 20ms

#include <cstdio>
#include <queue>
#include <unordered_map>

using namespace std;

int dx[9] = { 100, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = { 100, -1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
int maps[52][52], cpy[52][52];
int ms[101][2];
vector<int> clouds, moved;
unordered_map<int, int> cld;

int getsum() {

	int sum = 0;
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			sum += maps[a][b];
		}
	}

	return sum;
}

void storm() {

	clouds.push_back(100 * (n - 1) + 0);
	clouds.push_back(100 * (n - 1) + 1);
	clouds.push_back(100 * (n - 2) + 0);
	clouds.push_back(100 * (n - 2) + 1);

	int csize, dcurr, scurr, cl, xn, yn, xb, yb;
	for (int i = 0; i < m; i++)
	{
		dcurr = ms[i][0];
		scurr = ms[i][1];

		csize = clouds.size();
		moved.clear();  cld.clear();
		for (int j = 0; j < csize; j++)
		{
			cl = clouds.at(j);

			// 1.
			xn = (cl / 100 + scurr * dx[dcurr]);
			if (xn >= n) {
				xn %= n;
			}
			while (xn < 0) {
				xn += n;
			}
			
			yn = (cl % 100 + scurr * dy[dcurr]);
			if (yn >= n) {
				yn %= n;
			}
			while (yn < 0) {
			yn += n;
			}

			// 2.
			maps[xn][yn] ++;
			moved.push_back(100 * xn + yn);
			cld[100 * xn + yn] ++;
		}

		// 3.
		clouds.clear();

		// 4. 
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				cpy[a][b] = maps[a][b];
			}
		}

		for (int j = 0; j < csize; j++)
		{
			xn = moved.at(j) / 100;
			yn = moved.at(j) % 100;
			for (int k = 2; k <= 8; k+=2)
			{
				xb = xn + dx[k];
				yb = yn + dy[k];

				if (xb < 0 || xb >= n || yb < 0 || yb >= n) {
					continue;
				}

				if (cpy[xb][yb]) {
					maps[xn][yn] ++;
				}
			}
		}

		// 5.
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (maps[a][b] >= 2 && !cld[100 * a + b])
				{
					clouds.push_back(100 * a + b);
					maps[a][b] -= 2;
				}
			}
		}
	}

	return;
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &maps[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &ms[i][0], &ms[i][1]);
	}

	storm();

	int sum = getsum();

	printf("%d", sum);

	return 0;
}
