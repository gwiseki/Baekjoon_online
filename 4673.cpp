// 1232KB, 0ms

#include <cstdio>
#include <string>

using namespace std;

bool nums[10050];

int main() {
	string curr;
	int len, next;

	for (int i = 1; i < 10000; i++){
		curr = to_string(i);
		len = curr.length();

		next = i;
		for (int j = 0; j < len; j++)
			next += (curr[j] - '0');

		nums[next] = true;
	}

	for (int i = 1; i <= 10000; i++)
		if (nums[i] == false)
			printf("%d\n", i);
	

	return 0;
}
