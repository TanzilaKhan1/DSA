#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int upper,lower,n;
    scanf("%d %d %d",&lower,&upper,&n);
    int add,r;
    if(lower<0){
      add= abs(lower);
      if(upper>=0){
        r=abs(lower)+upper;}
      else{
        r=abs(lower)-abs(upper);
      }
    }
    else{
        add=-lower;
        r=upper-lower;
    }
    
    short int arr[r+1];
    for (int i = 0; i < r+1; i++)
    {
        arr[i]=0;
    }
    
    int num,ind;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num);
        ind=num+add;
        arr[ind]+=1;
    }
    
    for (ind = 0; ind < r+1; ind++)
    {
        if(arr[ind]!=0){
           num=ind-add;
           for (int i = 0; i < arr[ind]; i++)
           {
               printf("%d ",num);
           } 
        }
    }
    printf("\n");
    return 0;
}