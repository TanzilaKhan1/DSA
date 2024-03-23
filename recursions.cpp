#include <stdio.h>
int fibonacci(int n){
     if(n==0) return 0;
     if(n==1) return 1; 
    return fibonacci(n-1)+fibonacci(n-2);
}
int factorial(int n){
     if(n==0)return 1;
     return n*factorial(n-1);
}
int bigmod( int a, int n,int b){
    if(n==1){ return a%b;}
    int p;
    if(n%2==0){n=n/2;
      p=bigmod(a,n,b);
      return (p*p)%b;
    }
    else{n=(n-1)/2;
      p=bigmod(a,n,b);
      return ((a%b)*p*p)%b;
    }
}
void binarysearch(int start,int end,int search){
  if(start==end){
    printf("Not Found\n");
   }
  int mid;
  mid=(start+end)/2;
  if(mid==search){
    printf("Found\n");
  } 
  if(mid>search){
    end=mid;
    binarysearch(start,end,search);
  }
   if(mid<search){
    start=mid;
     binarysearch(start,end,search);
  }
}
int bsearch(int start,int end,int search,char x[]){
  if(start==end){
    printf("Not Found\n");
    return -1;
   }
  int mid;
  mid=(start+end)/2;
  if(mid==search){
    printf("Found\n");
    return mid;
  } 
  if(mid>search){
    end=mid;
   return bsearch(start,end,search,x);
  }
   if(mid<search){
    start=mid;
    return bsearch(start,end,search,x);
  }
}

int gcd(int n1,int n2){
 int temp;
 if(n1==n2){return n1;}
 if(n1==0 && n2!=0){return n2;}
 if(n2==0 && n1!=0){return n1;}
 if(n1<0){n1*=-1;}
 if(n2<0){n2*=-1;}
 if(n2>n1){temp=n1;
           n1=n2;
           n2=temp;}
   temp=n1%n2;
   n1=n2;
   n2=temp;
   return gcd(n1,n2);
}
int main(){
  int a=25,b=9,c=10,l1;
   int d=123246585,e=313133686, f=327;
  printf("%d ",bigmod(d,e,f));
  binarysearch(b,a,c);
  char x[20],y[20];
  scanf("%s",x);
  scanf("%s",y);
  l1=length(x);
  printf("%d ",lexicographical(x,y,l1));
}



