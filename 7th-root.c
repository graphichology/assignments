#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double x, y, num ,result;
int i;

void main()
{
    printf("enter a number to get 7th-root:");
    scanf("%lf", &x);

    for(i=10;i>=0;i--){
    if(pow(i,7)<=x){
        num=pow(i,7);
        y=(x-num)/num;
        result=(1+(y/7)+(((1/7)*((1/7)-1)*pow(y,2))/2)+(((1/7)*((1/7)-1)*((1/7)-2)*pow(y,3))/6));
        printf("%f",i*result);
        break;
    }

}
}
