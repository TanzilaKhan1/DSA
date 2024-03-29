#include<bits/stdc++.h>
using namespace std;

int lessEqualToMid(int **input, int mid,int n, int m) {
    int count = 0;
    int  x = n - 1, y = 0;
    while (x >= 0 && y < m) {
        if (mid < input[x][y]) {
            x--;
        } 
        else {
            count += x + 1;
            y++;
        }
    }
    return count;
}

int kthSmallest(int n,int m,int **input,int k) {
    int low=input[0][0];
    int high=input[n-1][m-1]; 
    while (high > low) {
        int mid = low + (high - low) / 2;
        int count = lessEqualToMid(input, mid, n,m);
        if (count >= k) {        
            high = mid;
        } 
        else {
             low = mid + 1;
        }
    }
    return low;
}

int main() {  
    int n=3,m=3 ;
    int **arr = new int*[n]; 
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int k = 7;
    cout << kthSmallest(n,m,arr,k) << endl;
    return 0;
}
