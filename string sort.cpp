#include <stdio.h>

int length(char a[]){
  int l;
  for (l = 0; l < 100000; l++){
      if(a[l]=='\0'){break;}
    }
    return l;
}

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


char ind[100];
void compare_two_String(char x[], char y[], int w, int u, int v){
    for (int c = 0; c < 100; c++)
    {
        int temp;
        if (x[c] == '\0'){
            break;
        }
        if (y[c] == '\0'){
            w = -1;
        }
        if (x[c] > y[c]) {
            w = -1;
        }
        else if (x[c] < y[c]){
            break;
        }
        else{
            continue;
        }
        if (w = -1){
            temp = ind[u];
            ind[u] = ind[v];
            ind[v] = temp;
            break;
        }
    }
}

int main(){
    char str[100][100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", str[i]);
    }
    int total = n, flag = 0;
    for (int j = 0; j < total; j++){
        ind[j] = j;
    }
    for (int m = 0; m < total - 1; m++){
        for (int k = m + 1; k < total; k++){
            compare(str[m], str[k], flag, m, k);
        }
    }
    for (size_t i = 0; i < total; i++){
        printf("%d ", ind[i]);
    }
    int x = 15;
    printf("%d ", !x);
}
