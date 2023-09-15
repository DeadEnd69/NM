#include<stdio.h>
#include<math.h>
#define EPS 0.05
#define F(x) 3*(x)*(x)-6*(x)+2
void main()
{
    int count;
    float a,b,m,fa,fb,fm;
    printf("******SOLUTION BY BISECTION METHOD********");
    printf("\nGIVEN EQUATION: F(x)= 3*x*x-6*x+2");
    printf("\nError Precision: 0.05\n");
    do
    {
        printf("Enter the two initial value: \n");
        scanf("%f%f",&a,&b);
        fa=F(a);
        fb=F(b);
        if(fa*fb<0)
        {
            printf("Given two initial values are valid!!\n");
            break;
        }
        else
        {
            printf("Enter valid initial values!!\n");
        }   continue;
    }
    while(1);
    count=0;
    begin:
    fa=F(a);
    fb=F(b);
    m=(a+b)/2;
    fm=F(m);
    if(fa*fm==0)
    {
        printf("Root: %.2f\n",m);
        printf("Function value: %.2f\n",fm);
        printf("Iteration: %d\n",count);
     }
    else if (fa*fm<0)
    {
        b=m;
        count++;
    }
    else
    {
        a=m;
        count++;
    }
    if(fabs(a-b)/b>EPS)
    {
        goto begin;
        
    }
    else
    {
        printf("At Iteration: %d\n",count);
        printf("Root: %.2f\n",m);
        printf("Function value: %.2f\n",fm);
        printf("Error:%.2f",fabs(a-b)/b);
         
    }
    
}