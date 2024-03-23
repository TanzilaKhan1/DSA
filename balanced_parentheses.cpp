#include <iostream>
#include <vector>
using namespace std;


void print_arr(char arr[],int len){
    for (size_t i = 0; i < len; i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}


void generateParenthesis(int open, int close, char arr[],int ind) {
    if(open == 0 && close == 0) {
        print_arr(arr,ind);
        return;
    }
    if(open > 0) {
        arr[ind]='(';
        generateParenthesis(open-1, close,arr, ind+1);}
    if(close > open) {
        arr[ind]=')';
        generateParenthesis(open, close-1, arr, ind+1);}
}

int main() {
    int n = 4; // 3 pairs of parentheses  
    char arr[2*n];
    generateParenthesis(n, n, arr,0);
    return 0;
}
