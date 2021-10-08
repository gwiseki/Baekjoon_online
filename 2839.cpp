// 1112KB, 0ms

#include <cstdio>
#include <vector>

using namespace std;

int main() {

	int n, num, curr, ans = 0;
	bool answer;

	scanf("%d", &n);

	num = n / 5;

	answer = false;
	for (int i = num; i >= 0; i--){
		curr = n - i * 5;
		if (curr % 3 == 0) {
			ans = i + curr / 3;
			answer = true;
			break;
		}
	}

	if (answer)
		printf("%d", ans);
	else
		printf("-1");

	return 0;
}
