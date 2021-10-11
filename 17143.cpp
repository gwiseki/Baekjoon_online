// 1364KB, 20ms

#include <cstdio>
#include <vector>

using namespace std;

int maps[102][102][3] = { { 0, 0, 0 }, };
int maps_next[102][102][3] = { { 0, 0, 0 }, };

int main() {

	int R, C, M, r, c, s, d, z;
	int next_pos, got = 0;

	scanf("%d %d %d", &R, &C, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		maps[r][c][0] = s;
		maps[r][c][1] = d;
		maps[r][c][2] = z;
	}

	for (int k = 1; k <= C; k++){
		
		for (int i = 1; i <= R; i++)
			if (maps[i][k][2]) {
				got += maps[i][k][2];
				maps[i][k][0] = maps[i][k][1] = maps[i][k][2] = 0;
				break;
			}
		
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				if (maps[i][j][2]) {

					switch (maps[i][j][1]) {
					case 1 :
						
						next_pos = i - maps[i][j][0];

						if (next_pos <= 0)
							while (1) {
								if (next_pos >= R + 1) {
									next_pos -= (next_pos - R) * 2;
									maps[i][j][1] = 1;
								}
								else if (next_pos <= 0) {
									next_pos += (next_pos - 1) * (-2);
									maps[i][j][1] = 2;
								}
								else
									break;
							}

						if (maps_next[next_pos][j][2]) {
							if (maps_next[next_pos][j][2] <= maps[i][j][2]) {
								maps_next[next_pos][j][0] = maps[i][j][0];
								maps_next[next_pos][j][1] = maps[i][j][1];
								maps_next[next_pos][j][2] = maps[i][j][2];
							}
						}
						else {
							maps_next[next_pos][j][0] = maps[i][j][0];
							maps_next[next_pos][j][1] = maps[i][j][1];
							maps_next[next_pos][j][2] = maps[i][j][2];
						}
						break;
					case 2:
						next_pos = i + maps[i][j][0];

						if (next_pos >= R + 1)
							while (1) {
								if (next_pos >= R + 1) {
									next_pos -= (next_pos - R) * 2;
									maps[i][j][1] = 1;
								}
								else if (next_pos <= 0) {
									next_pos += (next_pos - 1) * (-2);
									maps[i][j][1] = 2;
								}
								else
									break;
							}

						if (maps_next[next_pos][j][2]) {
							if (maps_next[next_pos][j][2] <= maps[i][j][2]) {
								maps_next[next_pos][j][0] = maps[i][j][0];
								maps_next[next_pos][j][1] = maps[i][j][1];
								maps_next[next_pos][j][2] = maps[i][j][2];
							}
						}
						else {
							maps_next[next_pos][j][0] = maps[i][j][0];
							maps_next[next_pos][j][1] = maps[i][j][1];
							maps_next[next_pos][j][2] = maps[i][j][2];
						}
						break;

					case 3:
						next_pos = j + maps[i][j][0];

						if (next_pos >= C + 1)
							while (1) {
								if (next_pos >= C + 1) {
									next_pos -= (next_pos - C) * 2;
									maps[i][j][1] = 4;
								}
								else if (next_pos <= 0) {
									next_pos += (next_pos - 1) * (-2);
									maps[i][j][1] = 3;
								}
								else
									break;
							}

						if (maps_next[i][next_pos][2]) {
							if (maps_next[i][next_pos][2] <= maps[i][j][2]) {
								maps_next[i][next_pos][0] = maps[i][j][0];
								maps_next[i][next_pos][1] = maps[i][j][1];
								maps_next[i][next_pos][2] = maps[i][j][2];
							}
						}
						else {
							maps_next[i][next_pos][0] = maps[i][j][0];
							maps_next[i][next_pos][1] = maps[i][j][1];
							maps_next[i][next_pos][2] = maps[i][j][2];
						}
						break;

					case 4:
						next_pos = j - maps[i][j][0];

						if (next_pos <= 0)
							while (1) {
								if (next_pos >= C + 1) {
									next_pos -= (next_pos - C) * 2;
									maps[i][j][1] = 4;
								}
								else if (next_pos <= 0) {
									next_pos += (next_pos - 1) * (-2);
									maps[i][j][1] = 3;
								}
								else
									break;
							}

						if (maps_next[i][next_pos][2]) {
							if (maps_next[i][next_pos][2] <= maps[i][j][2]) {
								maps_next[i][next_pos][0] = maps[i][j][0];
								maps_next[i][next_pos][1] = maps[i][j][1];
								maps_next[i][next_pos][2] = maps[i][j][2];
							}
						}
						else {
							maps_next[i][next_pos][0] = maps[i][j][0];
							maps_next[i][next_pos][1] = maps[i][j][1];
							maps_next[i][next_pos][2] = maps[i][j][2];
						}
						break;
					default :
						printf("wrong direction\n");
						break;
					}
				}

		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++) {
				if (maps_next[i][j][2]) {
					maps[i][j][0] = maps_next[i][j][0];
					maps[i][j][1] = maps_next[i][j][1];
					maps[i][j][2] = maps_next[i][j][2];
					maps_next[i][j][0] = maps_next[i][j][1] = maps_next[i][j][2] = 0;
				}
				else
					maps[i][j][0] = maps[i][j][1] =	maps[i][j][2] = 0;
			}
	}

	printf("%d", got);

	return 0;
}
