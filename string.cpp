#include <stdio.h>
int main(){
    char a[10000];
    scanf("%[a-zA-Z0-9]s",&a[0]);
    int l,mid=0,need;
  for (l = 0; l < 10000; l++)
  {
    if(a[l]=='\0'){break;}
  }
  int length=l,flag=0;
  for (int i = 1; i < length; i++)
  {
    if(a[i-1]==a[i]){
      for(int j=1;j<i;j++){
        int left=i-(j+1);
        int right=i+j;
        if(left<0 || right>=length){break;}
        if(a[i-(j+1)]!=a[i+j]){
            flag=1;
            break; }
      if(!flag){ mid=i;}
       break;
      }
    }
  }
  if(mid==0){ need=length;}
  else{
  need=(mid*2)-length;}
  printf("%d\n",need);
}
