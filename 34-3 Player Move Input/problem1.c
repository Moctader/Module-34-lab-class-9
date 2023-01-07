#include<stdio.h>
#include<stdbool.h>

void callprint(int arr[4][4], int n)
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            if(arr[i][j]==-1) printf(" ");
            if(arr[i][j]==1) printf("x");
            if(arr[i][j]==2) printf("0");
            
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
    bool player1=true;
    bool player2=false;
    while (true)
    {
        callprint(arr, n);
        if (player1)
        {
            int r,c;
            flag:
            printf("player 1 turn (x), Enter row and column:");
            scanf("%d %d", &r, &c);
            if(arr[r][c]!=-1)
            {
                printf("invalid approach\n");
                goto flag;
            }
            arr[r][c]=1;
            player1=false;
            player2=true;
        }
        else
        {
            int r, c;
            flag2:
            printf("player 2 turn (0), Enter row and column");
            scanf("%d %d", &r, &c);
            if (arr[r][c]!=-1)
            {
                printf("invalid approach\n");
                goto flag2;
            }
            arr[r][c]=2;
            player2=false;
            player1=true;
            
        }
    }
    
   

    return 0;
}
