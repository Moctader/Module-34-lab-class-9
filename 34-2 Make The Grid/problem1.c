#include<stdio.h>

void callprint(int arr[4][4], int n)
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            if(arr[i][j]==-1) printf(" ");
            if(j<n) printf("\t\t|  ");
        }
        printf("\n");
        if(i<n)printf("----------------------------------------------------");
        printf("\n");
        
    }
}

int main()
{
    int n=3, i, j;
    int arr[4][4];
    for(i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            arr[i][j]=-1;
        }
        
    }
    callprint(arr, n);

    return 0;
}
