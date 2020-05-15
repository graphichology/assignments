#include <stdio.h>
#include <stdlib.h>

void biggest(int*p1,int*p2,int*p3); //function declaration

int main()
{
    int n1 , n2 ,n3 ;
    printf("Enter Three Numbers :");
    scanf("%d %d %d",&n1,&n2,&n3);
    int *p1, *p2 , *p3 ;    //pointers declaration
    p1 =&n1 ; p2 =&n2 ; p3 =&n3 ;   //store address of numbers in pointers
    printf("You Entered : %d %d %d\n",*p1,*p2,*p3); //pointer dereferencing
    biggest(p1,p2,p3); // calling function
    return 0;
}

void biggest(int*p1,int*p2,int*p3){ //function Definition
if (*p1>*p2){
    if(*p1>*p3){
        p2=p1;p3=p1;
    }
    else{
        p1=p3;p2=p3;
    }
}
else {
    if(*p2>*p3){
        p1=p2;p3=p2;
    }
    else{
        p1=p3;p2=p3;
    }
}
printf("After Calling : %d %d %d",*p1,*p2,*p3);
}


