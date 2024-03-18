#include <iostream>
using namespace std;

int main(){
    short int arr[1000][1000]={0},n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
       int x,y;
       scanf("%d %d", &x,&y);
       arr[x][y]++;
    }
    
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if(arr[i][j]!=0){
                while(arr[i][j]>0){
                    printf("%d %d\n",i,j);
                    arr[i][j]--;
                }
            }
        }  
    }
    return 0;

}