//25
//25
#include <bits/stdc++.h>
using namespace std;

int a_even[]={0,2,4};
    int a_odd[]={1,3};
void permute( int start, int end,int sam[])
{
    
    if (start == end){
        printf("%d",sam[0]); 
        for (int i = 1; i <end ; i++)
        {
            printf(" %d",sam[i]); 
        }
         printf("\n"); 
        return;
        }
    else
    {
        // Permutations made
        for (int i = start; i < end; i++)
        {
            if(i%2==0){
                for (int j = 0; j < 3; j++)
                {
                    sam[i]=a_even[j];
                    permute(i+1, end, sam);
                }
                return;
            }
            else{
                for (int j = 0; j < 2; j++)
                {
                    sam[i]=a_odd[j];
                    permute(i+1, end, sam);
                }
                return;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int sample[n];
    int start=0,end=n;

    permute(start, end, sample);
    return 0;

}