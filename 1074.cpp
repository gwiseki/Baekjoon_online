// 1300KB, 0ms

#include <cstdio>
#include <cmath>

using namespace std;

int main() {

	int n, r, c;
	
	scanf("%d %d %d", &n, &r, &c);

	int len = pow(2, n);
	int cnt = len * len;
	int xs = 0, ys = 0, xe = len, ye = len;

	while (len > 0) {
		
		int half = len / 2;

		if (r < half && c < half) {
			xe /= 2;
			ye /= 2;
			cnt -= (half * half * 3);
		}
		else if (r < half && c >= half) {
			ys += half;
			xe /= 2;
			cnt -= (half * half * 2);
			c -= half;
		}
		else if (r >= half && c < half) {
			xs += half;
			ye /= 2;
			cnt -= (half * half * 1);
			r -= half;
		}
		else {
			xs += half;
			ys += half;
			r -= half;
			c -= half;
		}

		len /= 2;
	}

	printf("%d", cnt - 1);

	return 0;
}
