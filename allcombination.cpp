#include<bits/stdc++.h> 
using namespace std; 
 
int r;

void combinations(int arr[], int data[], 
                    int start, int end, int ind) 
{ 
    if (ind == r) 
    { 
        printf("%d",data[0]);
        for (int j = 1; j < r; j++) 
            printf(" %d",data[j]); 
        printf("\n"); 
        return; 
    } 
 
    for (int i = start; i <= end && (end - i + 1) >= (r - ind); i++) 
    { 
        data[ind] = arr[i]; 
        combinations(arr, data, i+1, end, ind+1); 
    } 
} 

int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5,6}; 
    r = 4; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int data[r];
    combinations(arr, data, 0, n-1, 0);
} 
