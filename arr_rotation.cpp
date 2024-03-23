#include<stdio.h>

void element_at_index(int arr[],int ind){  //without doing rotation(right)
     int sum;
    sum=(n+ind-(k%n))%n;
    if(sum>(n-1)){
            sum=sum-n;
        }
    printf("%d\n",arr[sum]);
}

int main() {  // left rotation
    int n, d;
    scanf("%d%d", &n, &d);
    int arr[100010];
    for (int m = 0; m < n; m++)
    {
        scanf("%d", &arr[m]);
    }
    for (int i = 0; i < d; i++)
    {
        int z = arr[0];
        for (int j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = z;
    }
    for (int x = 0; x < n; x++)
    {
        printf("%d ", arr[x]);
    }
    printf("\n");
    return 0;
}
