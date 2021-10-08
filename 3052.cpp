// 1112KB, 0ms

#include <cstdio>
#include <string>

using namespace std;

int main() {

	int surp[42] = { 0, };
	int curr, answer = 0;

	for (int i = 0; i < 10; i++){
		scanf("%d", &curr);

		surp[curr % 42] ++;
	}

	for (int i = 0; i < 42; i++)
		if (surp[i])
			answer++;

	printf("%d", answer);

	return 0;
}
