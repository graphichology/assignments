#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
/*int i;
printf("Enter the size of your text: ");
scanf("%d",&i);*/
printf("Enter a text : ");
char text[100];
gets(text);
if(text[0]>=65 && text[0]<=90){ // the first character is capital?? print it
printf("%c",text[0]);
}
else if (text[0]>=97 && text[0]<=122)
{
   printf("%c",text[0]-32);
}
int x=0;
for (x;x<strlen(text);x++){
if (text[x]==33 || text[x]==46 || text[x]==63){ //if the character is ?!. exist print it
    if(text[x+1]>=65 && text[x+1]<=90){ // the next character is capital?? print it
        printf("%c",text[x+1]);
    }
    else if(text[x+1]>=97 && text[x+1]<=122) // the next character is small?? capital it
    {
        printf("%c",text[x+1]-32);
    }
    else //if the next character diffrent print it
    {
     printf("%c",text[x+1]);
    }
}
else //if the character isn't ?!. print it
{
     if(text[x+1]>=65 && text[x+1]<=90){ // the next character is capital?? small it
        printf("%c",text[x+1]+32);
    }
    else if(text[x+1]>=97 && text[x+1]<=122) // the next character is small?? print it
    {
        printf("%c",text[x+1]);
    }
    else //if the next character diffrent print it
    {
     printf("%c",text[x+1]);
    }
}
}
}
