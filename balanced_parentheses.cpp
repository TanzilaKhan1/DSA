#include<bits/stdc++.h>
using namespace std;

void print_arr(char arr[],int len){
    for (size_t i = 0; i < len; i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}

void makeParenthesis(char arr[],int ind, int open, int close) {
    if(open == 0 && close == 0) {
        print_arr(arr,ind);
        return;
    }
    if(open > 0) {
        arr[ind]='(';
        makeParenthesis(arr, ind+1, open-1, close);}
    if(close > open) {
        arr[ind]=')';
        makeParenthesis(arr, ind+1, open, close-1);}
}

int main() {
    int n = 4;  
    char arr[2*n];
    makeParenthesis(arr,0, n, n );
    return 0;
}
