// 1224KB, 0ms

///1000이상이면 틀림
#include <cstdio>
#include <string>

using namespace std;

int main() {

	int n, len, count;
	string str;
	bool ishan;

	scanf("%d", &n);

	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	count = 99;

	for (int i = 100; i <= n; i++){
		str = to_string(i);
		len = str.length();

		ishan = true;
		for (int j = 0; j < len - 2; j++) 
			if (str[j] - str[j + 1] != str[j + 1] - str[j + 2]) {
				ishan = false;
				break;
			}

		if (ishan)
			count++;
	}
		printf("%d", count);

	return 0;
}
