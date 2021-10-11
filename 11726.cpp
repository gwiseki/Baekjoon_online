// 1116KB, 0ms

#include <cstdio>

int memo[1005];

int main() {

	int n;

	memo[1] = 1;
	memo[2] = 2;

	scanf("%d", &n);

	for (int i = 3; i <= n; i++) 
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007 ;
	
	printf("%d", memo[n]);

	return 0;
}
