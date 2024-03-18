#include <stdio.h>
int length(char a[]){
  int l;
  for (l = 0; l < 10000000; l++)
    {
      if(a[l]=='\0'){break;}
    }
    return l;
}
int main()
{
    char i1[1000000], i2[1000000], sum[1000000];
    int l1 = 0, l2 = 0, carry = 0, total, add, digit;
    scanf("%s", i1);
    scanf("%s", i2);
    l1=length(i1);
    l2=length(i2);
    if (l1 > l2)
    {
        total = l1 ;
    }
    else
    {
        total = l2 ;
    }
    int i = l1 - 1, j = l2 - 1;
    while (1)
    {
        if (i < 0 && j < 0)
        {
            sum[0]=carry+'0';
            break;
        }
        else if (i < 0)
        {
            add = (i2[j] + carry) -'0';
        }
        else if (j < 0)
        {
            add =( i1[i] + carry) - '0';
        }
        else
        {
            add = (i1[i] + i2[j] + carry) - 2*'0';
        }
        carry = (add / 10) ;
        digit = (add % 10) ;
        sum[total] = digit+'0';
        i--;
        j--;
        total--;
    }
    printf("%s",sum);  
}