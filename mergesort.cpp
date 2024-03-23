#include <iostream>
using namespace std;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize, int l) {
    int i = 0, j = 0, k = l;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            k++;
            i++;
        } else {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < leftSize) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    int left[mid - l + 1], right[r - mid];
    for (int i = 0; i <= mid - l; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < r - mid; i++) {
        right[i] = arr[mid + 1 + i];
    }
    merge(arr, left, mid - l + 1, right, r - mid, l);
}


void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[]={7,3,9,1, 5 ,7 ,3 ,2};
 // int i=0;
//   while(scanf("%d",arr[i])!=EOF){
//     i++;
//   }

  int size = sizeof(arr) / sizeof(arr[0]);
  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}
