#include <iostream>
#include<cmath>

using namespace std;

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countsort(int arr[],int n,int place)
{
        int range=10,freq[range],i;    //range for integers is 10 as digits range from 0-9
        for (int j = 0; j < range; j++)
           freq[j]=0;

        int output[n];
        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--)
        {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
}

void radixsort(int arr[],int n,int maxx)            //maxx is the maximum element in the array
{
        int mul=1;
        while(maxx)
        {
                countsort(arr,n,mul);
                mul*=10;
                maxx/=10;
        }
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int main() {
  int n;
  //int n = sizeof(arr) / sizeof(arr[0]);
  scanf("%d",&n);
  int arr[n+5];
  for (int i = 0; i < n+5; i++)
  {
    scanf("%d",&arr[i]);
  }
  
  int max=getMax(arr, n);
  radixsort(arr, n,max);
  printArray(arr, n);
  return 0;

}