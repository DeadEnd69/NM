#include <stdio.h>

#include <math.h>
int main()
{
	int n, i, k, j;
	float error, sum, E[10], a[10][10], b[10], new_x[10], old_x[10];
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
	printf("Enter RHS vector: \n");
	for (i = 0; i < n; i++)
	{
		scanf("%f", &b[i]);
	}
	printf("Enter Accuracy Limit: \n ");
	scanf("%f", &error);

	for (i = 0; i < n; i++)
	{
		old_x[i] = 0;
	}

	while (1)
	{
		for (i = 0; i < n; i++)
		{
			sum = b[i];
			for (j = 0; j < n; j++)
			{
				if (i != j)
					sum = sum - a[i][j] * old_x[j];
			}
			new_x[i] = sum / a[i][i];
			E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
		}
		for (i = 0; i < n; i++)
		{
			if (E[i] > error)
			{
				for (j = 0; j < n; j++)
					old_x[j] = new_x[j];
				break;
			}
		}
		if (i == n)
			break;
		else
			continue;
	}
	printf("Solution: \n");
	for (i = 0; i < n; i++)
	{
		printf("x%d = %.2f \t", i + 1, new_x[i]);
	}

	return 0;
}
