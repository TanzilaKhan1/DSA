#include <stdio.h>

int lexicographical(char s1[],char s2[],int l1){
  int flag=0;
     for (int i = 0; i <= l1; i++){
      if(s1[i]>s2[i]){ flag=-1;
      break;}
      if(s1[i]<s2[i]){flag=1;
      break;}
     }
     return flag;
}

void swapstring(int flag, char s1[], char s2[]){
    char temp[100000];
    if(flag==-1){
      for (int i = 0; i < 100000; i++){
        temp[i]=s1[i];
        if(s1[i]=='\0'){break;}
      }
      for (int i = 0; i < 100000; i++) {
        s1[i]=s2[i];
        if(s2[i]=='\0'){break;}
      }
      for (int i = 0; i < 100000; i++){
        s2[i]=temp[i];
        if(temp[i]=='\0'){break;}
      }
    }
}
