#include <stdio.h>

void insertion_sort(int a[], int n) {  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])  
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
    }  
}  

void selection_sort(int arr[], int n)  {  
    int i, j, small;     
    for (i = 0; i < n-1; i++)  {  
        small = i;     
        for (j = i+1; j < n; j++){  
           if (arr[j] < arr[small]){  
             small = j;  }
        }
        int temp = arr[small];  
        arr[small] = arr[i];  
       arr[i] = temp;  
    }  
}  

