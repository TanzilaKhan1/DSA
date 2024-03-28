#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(int arr1[],int len1,int arr2[],int len2) {
    if (len1 > len2) 
         return findMedianSortedArrays(arr2, len1, arr1,len2);

    int low = 0, high = len1;
    while (low <= high) {
        int part1 = (low + high) / 2;
        int part2 = (len1+ len2+ 1) / 2 - part1;
        int maxL1 ,minR1,maxL2,minR2;
        
        if(part1 == 0){
            maxL1=INT_MIN;
        }
        else{
            maxL1=arr1[part1 - 1];
        }
        if(part1 == len1){
            minR1=INT_MAX;
        }
        else{
            minR1=arr1[part1];
        }
        
        if(part2 == 0){
            maxL2=INT_MIN;
        }
        else{
            maxL2=arr2[part2 - 1];
        }
        if(part2 == len2){
            minR2=INT_MAX;
        }
        else{
            minR2=arr2[part2];
        }


        if (maxL2 <= minR1 && maxL1 <= minR2) {
            if ((len1 + len2) % 2 != 0) {
                
                return max(maxL1, maxL2);
            } 
            else {
                return (max(maxL1, maxL2) + min(minR1, minR2)) / 2.0;
            }
        } else if (maxL1 <= minR2) {
            low = part1 + 1;
        } else {
            high = part1 - 1;
        }
    }
}

int main() {
    int arr1[] = {1, 3};
    int arr2[] = {2, 3 ,4};
    int len1=2;
    int len2=3;
    cout << findMedianSortedArrays(arr1,len1,arr2,len2) << endl;
    return 0;
}


int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
