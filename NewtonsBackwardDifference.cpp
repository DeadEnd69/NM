#include <stdio.h>

int fact(int n)
{
	int f = 1, i;
	for (i = 1; i <= n; i++)
		f = f * i;
	return f;
}

int main()
{
	int n, i, j, ch = 30;
	float arr[10][11], px = 1, x, y, p, h;

	printf("Enter the number of points: \n");
	scanf("%d", &n);
	printf("Enter the value at which interpolated value is needed: \n");
	scanf("%f", &x);

	for (i = 0; i < n; i++)
	{
		printf("Enter the value of x and fx at i=%d\n", i);

		scanf("%f", &arr[i][0]);

		scanf("%f", &arr[i][1]);
	}

	// forming the difference table
	for (j = 2; j <= n; j++)
	{
		for (i = 0; i < n - 1; i++)
			arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];
	}

	// calculate the value of f(x) for x
	h = arr[n - 1][0] - arr[n - 2][0];
	p = (x - arr[n - 1][0]) / h;
	y = arr[n - 1][1];

	for (i = 1; i < n; i++)
	{
		px = px * (p + (i - 1));
		y = y + (arr[n - 1 - i][i + 1] * px) / fact(i);
	}

	printf("\nInterpolation value = %.2f\n", y);

	return 0;
}
