#include<bits/stdc++.h> 
using namespace std;

int findMin(int arr[],int len) {
    int low = 0, high =len - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[high] >= arr[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return arr[low];
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int len=5;
    cout << findMin(arr,len) << endl;
    return 0;
}

