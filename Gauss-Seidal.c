#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j;
	float error, sum, E[10], a[10][10], b[10], x[10], x_new[10];
	printf("Enter Dimension of System of equations: \n ");
	scanf("%d", &n);
	printf("Enter coefficients row-wise: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}
	printf("Enter B vector: \n");
	for (i = 0; i < n; i++)
	{
		scanf("%f", &b[i]);
	}
	printf("Enter Accuracy Limit: \n ");
	scanf("%f", &error);

	for (i = 0; i < n; i++)
	{
		x[i] = 0;
	}

	int converged = 0; // Variable to track convergence

	while (!converged)
	{
		for (i = 0; i < n; i++)
		{
			sum = b[i];
			for (j = 0; j < n; j++)
			{
				if (i != j)
					sum -= a[i][j] * x[j];
			}
			x_new[i] = sum / a[i][i];
		}

		// Calculate error ratios
		converged = 1; // Assume convergence
		for (i = 0; i < n; i++)
		{
			E[i] = fabs(x_new[i] - x[i]) / fabs(x_new[i]);
			x[i] = x_new[i]; // Update x for the next iteration
			if (E[i] > error)
			{
				converged = 0; // Not converged, continue the loop
				break;
			}
		}
	}

	printf("Solution: \n");
	for (i = 0; i < n; i++)
	{
		printf("x%d = %.2f \t", i + 1, x[i]);
	}

	return 0;
}
