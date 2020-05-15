#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double* root(double *num)
{
    int n;
    printf("enter the root number:");
    scanf("%d",&n);
    double i;
    for(i=0;pow(i,n)<=*num;i+=.001)
    {

    }
    *num=i;
    return num;
}


void main()
{
    double x=0;
    printf("enter a number:");
    scanf("%lf", &x);
    double result=*root(&x);
    printf("%lf",result);

}
