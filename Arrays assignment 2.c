#include <stdio.h>
#include <stdlib.h>
void unique(int arr[], int size, int *newSize , int newArr[] ){
    int i , j = 0;
    for(i=0;i<size;i++)
    {
        if( comparison(arr[i] , newArr , j) ==0 )
        {
            newArr[j] = arr[i];
            j++;
        }
    }*newSize = j ;
}
int comparison(int value , int arr[] , int size ){
    int i ;
    for(i=0;i<size;i++)
    {
        if(arr[i] == value)
        {
            return 1;
        }
    }return 0;
}
void printArr(int size , int arr[]){
    int i ;
    for(i = 0 ; i<size ; i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
int main(){
    int arr[] = {2,5,5,6,7,8,9,9,2,4,0,5,3};
    int size = sizeof(arr)/4 ;
    int newSize = size ;
    int newArr[newSize] ;
    unique(arr,size,&newSize,newArr);
    printf("Original array : "); printArr(size , arr) ;
    printf("Unique array : ");   printArr(newSize , newArr) ;
    printf("New Size = %d" , newSize) ;
    return 0;
}
