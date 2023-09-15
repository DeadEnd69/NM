#include<stdio.h>
#include<math.h>
#define EPS 0.001
#define F(x) (x)*(x)*(x)+(x)*(x)-1
#define G(x) 1/sqrt(1+(x))
float derivative(float x)
{
    return (2*x-5);
}
void main()
{
    float x0,fx,gx,x1,a,b;
    int count;
    //printf("******Fixed Point Method********");
    printf("\nGiven function: F(x)=x^3+x^2-1");
    printf("\nError Precision: 0.001\n");

    do
    {
        printf("Enter the two initial value: \n");
        scanf("%f %f",&a,&b);
        if(F(a)*F(b)<0)
        {
            printf("Given two initial values are valid!!\n");
            break;
        }
        else
            printf("Enter valid initial values!!\n");
            continue;
    }
    while(1);
    x0=(a+b)/2;
    if(fabs(derivative(x0)<1))
        printf("\nFunction form is correct.Iteration method can be applied.\n");
    else
        printf("\nFunction form is not correct. Iteration cannot be applied.\n");
    count=1;
    begin:
        gx=G(x0);
        x1=gx;
    if(fabs(x1-x0)/x1<=EPS)
    {
        printf("Root: %f",x1);
        printf("\nFunction Value: %f",F(x1));
        printf("\nNumber of iteration: %d",count);

    }
    else
    {
        x0=x1;
        count=count+1;
        goto begin;
    }


}
