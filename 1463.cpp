// 5924KB, 4ms

#include <iostream>

using namespace std;

int memo[1000005];

int main() {
	
	int n, min;

	cin >> n;

	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;

	for (int i = 4; i <= n; i++){

		min = 1000000;
		if (i % 3 == 0 && min > memo[i / 3])
			min = memo[i / 3];
		
		if (i % 2 == 0 && min > memo[i / 2])
			min = memo[i / 2];
		
		if(min > memo[i - 1])
			min = memo[i - 1];

		memo[i] = min + 1;
	}

	cout << memo[n];

	return 0;
}
