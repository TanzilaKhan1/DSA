#include<bits/stdc++.h> 
using namespace std;

int findPeakElement(int arr[],int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid1 = (low + high) / 2;
        int mid2 = mid1 + 1;
        if (arr[mid1] >= arr[mid2]) {
            high = mid1;
        } else {
            low = mid2;
        }
    }
    return low;
}

int main() {
    int arr[]= {1, 2, 3, 4, 5, 6,};
    int len=6;
    cout <<findPeakElement(arr,len) << endl;
    return 0;
}
