#include <stdio.h>
int main()
{
    char a[10000];
    scanf("%[a-zA-Z0-9]s", a);
    int l;
    for (l = 0; l < 10000; l++)
    {
        if (a[l] == '\0') break;
    }
    int flag=0;
    
  for (int i = 1; i < l-1; i++)
  {
    if(a[i]==a[0]){
        for(int j=1;j<i;j++){
           if(a[i+j]!=a[0+j]){
            flag=1;
            break; }
        }
         if(!flag){
            a[i]='\0';
            break;
        } 
    }  
  }
  printf("%s \n",a);
}