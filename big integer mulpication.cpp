#include <stdio.h>
int length(char a[]){
  int l;
  for (l = 0; l < 100000; l++)
    {
      if(a[l]=='\0'){break;}
    }
    return l;
}
char substract(char car,char x,char y,char ans){
    char ch=y+car-'0';
    if(ch<=x){
            ans=x-ch+'0';
            return 0;}
    else{
        x+=10;
        ans=x-ch+'0';
        return 1; }
}
void substraction(char a[],char b[],int i, int j,int total,char sub[],char carry){
   char minus,c;
   if (i < 0 && j < 0) {return;}
   if (j < 0){
            minus=(a[i]-carry); }
        c=substract(carry,a[i],b[j],sub[total]) ;
        carry=c;
        substraction(a,b,i-1,j-1,total-1,sub,carry);
}
int lexicographical(char s1[],char s2[],int l1){
  int flag=0;
     for (int i = 0; i <= l1; i++)
     {
      if(s1[i]>s2[i]){ flag=-1;
      break;}
      if(s1[i]<s2[i]){flag=1;
      break;}
     }
     return flag;
}

int main()
{
    char i1[1000000], i2[1000000], sub[1000000];
    int l1,  l2, carry = 0, total, add, digit;
    scanf("%s", i1);
    scanf("%s", i2);
    l1=length(i1);
    l2=length(i2);
    int i = l1 - 1, j = l2 - 1,carry=0;
    if (l1 > l2){  total = l1 ;
      substraction(i1,i2,i,j,total,sub,carry);  }                    
    if(l1<l2){  total = l2 ;
     substraction(i2,i1,j,i,total,sub,carry);}
    if(l1==l2){
      int flag=lexicographical(i1,i2,l1);
      if(flag==0){
        printf("0");}
      if(flag==-1){
        substraction(i2,i1,j,i,total,sub,carry);}
      if(flag==1){ 
        substraction(i1,i2,i,j,total,sub,carry); }
    }
     printf("%s",sub);
 }
   