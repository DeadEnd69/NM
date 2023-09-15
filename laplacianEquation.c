#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SQR 4

typedef float array[SQR + 1][SQR + 1];

void getrow(int i, array u)
{
    int j;

    printf("Enter the value of u[%d,j],j=1,%d\n", i, SQR);

    for (j = 1; j <= SQR; j++)
        scanf("%f", &u[i][j]);
}

void getcol(int j, array u)
{
    int i;
    printf("Enter the value of u[i%d],i=2,%d\n", j, SQR - 1);

    for (i = 2; i <= SQR - 1; i++)
        scanf("%f", &u[i][j]);
}

void printarr(array u, int width, int precision)
{
    int i, j;

    for (i = 1; i <= SQR; i++)
    {
        for (j = 1; j <= SQR; j++)
            printf("%*.*f\t", width, precision, u[i][j]);
        printf("\n");
    }
}

int main()
{
    array u;
    float maxerr, aerr, err, t;
    int i, j, itr, maxitr;

    for (i = 1; i <= SQR; i++)
        for (j = 1; j <= SQR; j++)
            u[i][j] = 0;

    printf("Enter the boundary conditions:\n");
    getrow(1, u);
    getrow(SQR, u);
    getcol(1, u);
    getcol(SQR, u);

    printf("Enter allowed error, maximum Iterations:\n");
    scanf("%f %d", &aerr, &maxitr);
    printf("%s", "fixed");

    for (itr = 1; itr <= maxitr; itr++)
    {
        maxerr = 0;
        for (i = 2; i <= SQR - 1; i++)
        {
            for (j = 2; j <= SQR - 1; j++)
            {
                t = (u[i - 1][j] + u[i + 1][j] + u[i][j + 1] + u[i][j - 1]) / 4;
                err = fabs(u[i][j] - t);

                if (err > maxerr)
                    maxerr = err;
                u[i][j] = t;
            }
        }

        printf("Iteration no. %d\n", itr);
        printarr(u, 9, 2);

        if (maxerr <= aerr)
        {
            printf("After %d iterations\n", itr);
            printf("The solution:\n");
            printarr(u, 8, 1);
            return 0;
        }
    }
    printf("Iterations not sufficient.\n");
    return 1;
}
