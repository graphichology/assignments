#include <stdio.h>
#include <stdlib.h>
int grid[8][8]={0};
int grid2[8][8]={0};
void scaning();
void printing(int a , int arr[8][8]);
void checking(int oldArr[8][8],int newArr[8][8]);
//void swaping(int **grid,int **grid2);
int main()
{

    scaning();
    printing(0,grid);
    checking(grid,grid2);
    printing(1,grid2);
    checking(grid2,grid);
    printing(2,grid);
    checking(grid,grid2);
    printing(3,grid2);

return 0 ;
}
void scaning(){
for(int x=1;x<=6;x++){
        for(int y=1 ; y<=6 ; y++){
            printf("enter a value of (%d,%d) : ",x,y);
            scanf("%d",&grid[x][y]);
        }
    }

}
void printing(int a , int arr[8][8]){
printf("Grid %d = \n\n",a);
    for(int x=0;x<=7;x++){
        for(int y=0;y<=7;y++){
            printf("[%d]   ",arr[x][y]);
            if(y==7) printf("\n\n");
        }
    }

}
void checking(int oldArr[8][8],int newArr[8][8]){
         for(int x=1;x<=6;x++){
            for(int y=1;y<=6;y++){
                int sum=0;
                for(int i=x-1 ; i<= x+1 ; i++){
                    for(int j=y-1;j<=y+1;j++){
                        sum+=oldArr[i][j];
                        if (i==x+1 & j== y+1){
                            if(oldArr[x][y]==0 & sum == 3){
                                newArr[x][y]=1;
                            }
                            else if(oldArr[x][y]==1 & (sum == 3 | sum == 4)){
                                newArr[x][y]=1;}
                            else
                            {newArr[x][y]=0;}

                        }

                    }
                }
            }
            }


}

