// 1112KB, 0ms

#include <cstdio>

int main() {

	int curr, next, dir;


	scanf("%d %d", &curr, &next);

	if (next - curr > 0)
		dir = 1;
	else
		dir = -1;

	curr = next;
	for (int i = 0; i < 6; i++) {
		scanf("%d", &next);

		if ((next - curr > 0 && dir < 0) || (next - curr < 0 && dir > 0)) {
			printf("mixed");
			return 0;
		}

		curr = next;
	}

	if (dir > 0)
		printf("ascending");
	else
		printf("descending");

	return 0;
}
