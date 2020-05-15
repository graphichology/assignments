#include <stdio.h>
#include <stdlib.h>
int day_year;
int year;
int i;
int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
void find_data(int ,int , int * , int *);

int main()
{
    scanf("%d %d",&day_year,&year);
    find_data(day_year,year,&day_year,&months);
    return 0;
}

void find_data(int day_year,int year, int *day , int *month){

    if( year%4 == 0) months[1]=29;
    if( *day >366) printf("error");
    else {
        for(i=0;*day>months[i];i++){
        *day-=months[i];
        }
        printf("%d %/ %d %/ %d",*day,i+1,year);
    }

}
