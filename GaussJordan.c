#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, k, j, p, q;
	float pivot, term, sum = 0, a[10][10], b[10], x[10];
	printf("Enter Dimension of System of equations: \n ");
	scanf("%d", &n);
	printf("Enter coefficients of Augmented Matrix: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}
	// Elimination
	for (k = 0; k < n; k++)
	{
		pivot = a[k][k];
		for (p = 0; p < n + 1; p++)
		{
			a[k][p] = a[k][p] / pivot; // Normalization
		}
		for (i = 0; i < n; i++)
		{
			term = a[i][k];
			if (k != i)
				for (j = 0; j < n + 1; j++)
				{
					a[i][j] = a[i][j] - a[k][j] * term;
				}
		}
	}
	printf("Solution: \n");
	for (i = 0; i < n; i++)
	{
		printf("x%d=%.2f\t", i + 1, a[i][n]); // Access the last column
	}

	return 0;
}
