// 1988KB, 0ms

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

typedef long long int ll;

ll pows[50];

int main() {

	int len;
	ll val = 0;
	string str;

	cin >> len;
	cin >> str;

	pows[0] = 1;
	for (int i = 1; i < len; i++)
		pows[i] = (pows[i - 1] * 31) % 1234567891;

	for (int i = 0; i < len; i++) 
		val = (val + (str[i] - 'a' + 1) * pows[i]) % 1234567891;
	
	printf("%lld", val);

	return 0;
}
