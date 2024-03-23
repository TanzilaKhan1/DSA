#include <iostream>
#include<cmath>

using namespace std;

void find_Nth_root(double x, int n){
    double upper,lower,epsilon=0.00000001;
    if(x>=0 && x<1.0){
        lower=x;
        upper=1;
    }
    else{
        lower=1;
        upper=x;
    }
    double mid=(lower+upper)/2;
    double diff=pow(mid,n)-x;
    while(abs(diff)>epsilon){
         if(diff>0){
            upper=mid;
         }
         else{
            lower=mid+epsilon;
         }
         mid=(lower+upper)/2;
         diff=pow(mid,n)-x;
    }
    printf("%.9lf\n",mid);
    return;
}


int main(){
    double num;
    int n;
    scanf("%lf %d",&num,&n);
    if(num-1<0.0000000001){
        printf("1.0");
    }
    else{
       find_Nth_root(num,n) ;
    }
    return 0;
}
