#include<stdio.h>
int main() {
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
