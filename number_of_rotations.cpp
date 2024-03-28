#include<bits/stdc++.h> 
using namespace std;
int findRotationCount(int arr[],int len) {
    int low = 0, high = len - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[high] >= arr[mid]) { 
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {   //right rotation
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int len=7;
    cout << findRotationCount(arr,len) << endl;
    return 0;
}
