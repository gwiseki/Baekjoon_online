// 1500KB, 76ms

#include <string>
#include <vector>

using namespace std;

int arr[100005];

int main() {

	int n, m, i, j;
	
	scanf("%d %d", &n, &m);

	for (int k = 0; k < n; k++)
	{
		scanf("%d", &arr[k]);
	}

	for (int k = 1; k < n; k++)
	{
		arr[k] = arr[k - 1] + arr[k];
	}

	for (int k = 0; k < m; k++)
	{
		scanf("%d %d", &i, &j);

		if (i == 1) {
			printf("%d\n", arr[j - 1]);
			continue;
		}
		printf("%d\n", arr[j - 1] - arr[i - 2]);
	}

	return 0;
}
