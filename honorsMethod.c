#include <stdio.h>
int horner(int a[], int n, int x)
{
    int result = 0;
    for (int i = n; i >= 0; --i)
    {
        result = result * x + a[i];
    }

    return result;
}
void main()
{
    int a[10], n, x, i;
    printf("Enter the degree of polynomial: ");
    scanf("%d", &n);
    printf("Enter the value of x: ");
    scanf("%d", &x);
    for (i = n; i >= 0; i--)
    {
        printf("\nEnter Coefficient of [ X^%d ] : ", i);
        scanf("%d", &a[i]);
    }
    printf("Value of polynomial is: %d", horner(a, n, x));
}