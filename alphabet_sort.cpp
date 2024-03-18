#include <iostream>
using namespace std;

int main(){
    char str[1000005];
    scanf("%s",str);
    int len;
    for (len = 0; len < 1000005 ; len++)
    {
       if(str[len]=='\0'){
        break;
       }
    }

    short int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i]=0;
    }
    
    int ind;
    for (int i = 0; i < len; i++)
    {       
        ind=str[i]-'a';
        arr[ind]+=1;
    }
    char ch;
    int k=0;
    for (ind = 0; ind < 26; ind++)
    {
        if(arr[ind]!=0){
           ch=ind+'a';
           for (int i = 0; i < arr[ind]; i++)
           {
               str[k]=ch;
               k++;
           } 
        }
    }
    str[k]='\0';
    printf("%s\n",str);
    return 0;

}