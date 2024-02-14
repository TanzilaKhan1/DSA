#include <iostream>
#include<cmath>
using namespace std;

int main(){
    double high,low;
    int n,digit;
    scanf("%lf %lf %d %d",&low,&high,&n,&digit);
    int upper = (int)(high * digit);
    int lower = (int)(low * digit);
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
    
    double number;
    int num,ind;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&number);
        num= (int)(number*digit);
        ind=num+add;
        arr[ind]+=1;
    }
    
    for (ind = 0; ind < r+1; ind++)
    {
        int ans;
        if(arr[ind]>0){
          num=ind-add;
          number=(double)num/digit;
          ans = (int)(number * digit);  //digit=10000
        }
      
        while(arr[ind]>0)
        {   
                if (ans % 10000 == 0)
                {
                    printf("%.0lf\n", number);
                }
                else if (ans % 1000 == 0)
                {
                    printf("%.1lf\n", number);
                }
                else if (ans % 100 == 0)
                {
                    printf("%.2lf\n", number);
                }
                else if (ans % 10 == 0)
                {
                    printf("%.3lf\n", number);
                }
                else
                {
                    printf("%.4lf\n", number);
                }
          arr[ind]--;
        } 
    }

    printf("\n");
    return 0;
}
