#include <iostream>
#include <cmath>
using namespace std;

void bsearch(int start,int end,int search,int x[]){
  if(start==end){
    printf("0\n");
    return;
   }
  int mid;
  mid=(start+end)/2;
  if(x[mid]==search){
    printf("1\n");
    return;
  } 
  if(x[mid]>search){
    end=mid-1;
   return bsearch(start,end,search,x);
  }
   if(x[mid]<search){
    start=mid+1;
    return bsearch(start,end,search,x);
  }
}

int main()
{

    int n, q;
    int arr[1000005];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q);
    
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        bsearch(0,n-1,x,arr);
    }

    return 0;
}
