#include <stdio.h>
void matrix(int a[][100],int n){
   for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        } 
    }
    return;
}
void multiply(int a[][100],int b[][100],int mul[][100],int n){
    int i,j,k;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {    
            for ( k = 0; k < n; k++)
            {
                mul[i][j]+=a[i][k]*b[k][j];
                //printf("%d ",mul[i][j]);
            }
           //printf("%d ",mul[i][j]);
        } 
    }
    return;
}
int a[100][100],b[100][100];
int ans[100][100]={0};
int main(){
    int n;
    scanf("%d",&n);
    matrix(a,n); 
    matrix(b,n);
    multiply(a,b,ans,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",ans[i][j]);
        } 
        printf("\n");
    }
}