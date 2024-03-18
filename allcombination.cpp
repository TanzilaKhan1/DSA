#include<bits/stdc++.h> 
using namespace std; 
 
/* arr[] ---> Input Array 
data[] ---> Temporary array to store current combination 
start & end ---> Starting and Ending indexes in arr[] 
index ---> Current index in data[] 
r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], 
                    int start, int end, 
                    int index, int r) 
{ 
    // Current combination is ready
    // to be printed, print it 
    if (index == r) 
    { 
        for (int j = 0; j < r; j++) 
            cout << data[j] << " "; 
        cout << endl; 
        return; 
    } 
 
    // replace index with all possible 
    // elements. The condition "end-i+1 >= r-index"
    // makes sure that including one element 
    // at index will make a combination with 
    // remaining elements at remaining positions 
    for (int i = start; i <= end && 
        end - i + 1 >= r - index; i++) 
    { 
        data[index] = arr[i]; 
        combinationUtil(arr, data, i+1, 
                        end, index+1, r); 
    } 
} 


void printCombination(int arr[], int N, int R) 
{ 
    // A temporary array to store all combination one by one 
    int data[R]; 
    combinationUtil(arr, data, 0, N-1, 0, R); 
} 
 
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int R = 3; 
    int N = sizeof(arr)/sizeof(arr[0]); 
    printCombination(arr, N, R); 
} 