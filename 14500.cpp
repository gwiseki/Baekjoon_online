// 2100KB, 28ms

#include <cstdio>

using namespace std;

int tmap[502][502];
int n, m, max = 0, sum = 0;

void cyan() {

	// horizontal
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 3; j++)
		{
			sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += tmap[i][j + k];
			}
			if (max < sum)
				max = sum;
		}
	}

	// vertical
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += tmap[i + k][j];
			}
			if (max < sum)
				max = sum;
		}
	}
}

void yellow() {

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i + 1][j];
			sum += tmap[i + 1][j + 1];
			if (max < sum)
				max = sum;
		}
	}
}

void orange() {

	// o x
	// o x
	// o o
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i + 1][j];
			sum += tmap[i + 2][j];
			sum += tmap[i + 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}

	// o o o
	// o x x
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i][j + 2];
			sum += tmap[i + 1][j];
			if (max < sum)
				max = sum;
		}
	}

	// o o
	// x o
	// x o

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i + 1][j + 1];
			sum += tmap[i + 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}

	// x x o
	// o o o
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i][j + 2];
			sum += tmap[i - 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}

	// x o
	// x o
	// o o
	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i - 1][j + 1];
			sum += tmap[i - 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}

	// o x x 
	// o o o
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i + 1][j];
			sum += tmap[i + 1][j + 1];
			sum += tmap[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}

	// o o
	// o x
	// o x
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i + 1][j];
			sum += tmap[i + 2][j];
			if (max < sum)
				max = sum;
		}
	}

	// o o o
	// x x o
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i][j + 2];
			sum += tmap[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}

}

void green() {

	// o x
	// o o 
	// x o
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i + 1][j];
			sum += tmap[i + 1][j + 1];
			sum += tmap[i + 2][j + 1];
			if (max < sum)
				max = sum;
		}
	}

	// x o o
	// o o x
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i - 1][j + 1];
			sum += tmap[i - 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}

	// x o
	// o o
	// o x
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i + 1][j];
			sum += tmap[i + 1][j - 1];
			sum += tmap[i + 2][j - 1];
			if (max < sum)
				max = sum;
		}
	}

	// o o x
	// x o o
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i + 1][j + 1];
			sum += tmap[i + 1][j + 2];
			if (max < sum)
				max = sum;
		}
	}

}

void pink() {

	// o o o
	// x o x
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i][j + 2];
			sum += tmap[i + 1][j + 1];
			if (max < sum)
				max = sum;
		}
	}

	// x o
	// o o
	// x o
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 1; j < m; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i + 1][j];
			sum += tmap[i + 2][j];
			sum += tmap[i + 1][j - 1];
			if (max < sum)
				max = sum;
		}
	}

	// x o x
	// o o o
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i][j + 1];
			sum += tmap[i][j + 2];
			sum += tmap[i - 1][j + 1];
			if (max < sum)
				max = sum;
		}
	}

	// o x
	// o o
	// o x
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sum = 0;
			sum += tmap[i][j];
			sum += tmap[i + 1][j];
			sum += tmap[i + 2][j];
			sum += tmap[i + 1][j + 1];
			if (max < sum)
				max = sum;
		}
	}

}

int main() {

	// inputs
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &tmap[i][j]);
		}
	}

	// solution
	cyan();
	yellow();
	orange();
	green();
	pink();

	printf("%d", max);

	return 0;
}
