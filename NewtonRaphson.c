#include<stdio.h>
#include<math.h>
#define EPS 0.001
#define F(x) (x)*(x)+4*(x)-9
#define FD(x) 2*(x) +4
void main()
{
    int count;
    float x0,x1,fx0,fdx0;
    printf("Input the initial guess: ");
    scanf("%f",&x0);
    //printf("\n*****Newton Raphson Method******\n");
    count=1;
    printf("Given function: F(x)= x*x+4x-9\n");
    printf("Error Precision: 0.001\n");

    begin:
        fx0=F(x0);
        fdx0=FD(x0);
        x1=x0-fx0/fdx0;
    if(fabs(x1-x0)/x1<=EPS)
    {
        printf("\nAt iteration: %d",count);
        printf("\nRoot: %f",x1);
        printf("\nFunction Value: %f",F(x1));
        printf("\nError: %f",fabs(x1-x0)/x1);

        

    }
    else
    {
        x0=x1;
        count=count+1;
        goto begin;
    }

}