#include <stdio.h>

#include <math.h>
#define f(x) 1 / (1 + (x))
int main()
{
	int i, k;
	float a, x0, xn, h, fx0, fxn, term, v;
	printf("Enter values of Lower and Upper limit:\n");
	scanf("%f%f", &x0, &xn);
	printf("Enter Number of Segments:\n");
	scanf("%d", &k);
	h = (xn - x0) / k;
	fx0 = f(x0);
	fxn = f(xn);
	term = f(x0) + f(xn);
	for (i = 1; i <= k - 1; i = i + 2)
	{
		a = x0 + i * h;
		term = term + 4 * (f(a));
	}
	for (i = 2; i <= k - 2; i = i + 2)
	{
		a = x0 + i * h;
		term = term + 2 * (f(a));
	}
	v = h / 3 * term;
	printf("Value of Integration=%f\n", v);

	return 0;
}
