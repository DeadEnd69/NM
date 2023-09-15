#include<stdio.h>
#include<math.h>
#define EPS 0.05
#define F(x) 2*(x)*(x)+4*(x)-10
void main()
{
    int count;
    float x0,x1,fx0,fx1,x2;
    
    printf("Given function: F(x)= 2*x*x+4x-10\n");
    printf("Error Precision: 0.05\n");
    printf("Input two initial guess: \n");
    scanf("%f%f",&x0,&x1); 
    count=1;
    

    begin:
        fx0=F(x0);
        fx1=F(x1);
        x2=x1-(fx1*(x1-x0)/(fx1-fx0));
    if(fabs(x2-x1)/x2<=EPS)
    {
        printf("\nAt iteration: %d",count);
        printf("\nRoot: %f",x2);
        printf("\nFunction Value: %f",F(x2));
        printf("\nError: %f",fabs(x2-x1)/x2);

        

    }
    else
    {
        x0=x1;
        x1=x2;
        count=count+1;
        goto begin;
    }

}