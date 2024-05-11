#include<bits/stdc++.h> 
using namespace std;

int search_element(int arr[], int target,int len) {
    int low = 0, high = len - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;

        
        if (arr[low] <=arr[mid]) {
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1; 
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 4;
    int len_arr=7;
    int ans= search_element(arr, target,len_arr);
    cout << ans << endl;
    return 0;
}
