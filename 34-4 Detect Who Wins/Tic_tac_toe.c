#include<stdio.h>
#include<stdbool.h>

int printwin(int arr[4][4], int n)
{
    int i, j;
    for(i=1; i<n; i++)
    {
        if(arr[i][1]==arr[i][2] && arr[i][2]==arr[i][3] && arr[i][1]!=-1)
        return arr[i][1];
    }
    for(j=1; j<n; j++)
    {
        if(arr[1][j]==arr[2][j] && arr[2][j]==arr[3][j] && arr[1][j]!=-1)
        return arr[1][j];
    }
    if(arr[1][1]==arr[2][2] && arr[2][2]==arr[3][3] && arr[1][1]!=-1)
    return arr[1][1];

    if(arr[1][3]==arr[2][2] && arr[2][2]==arr[3][1] && arr[3][1]!=-1)
    return arr[1][3];

    return -1;
}


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
void print_only_win_value(int arr[4][4], int n, int who)
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            if(arr[i][j]==who)
            {
                if(arr[i][j]==1) printf("x");
                else printf("0");
            }
            else
            {
                printf(" ");
            }

            
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
        //who win

        if (printwin(arr, n) ==1)
        {
            printf("Player1 is won\n");
            print_only_win_value(arr,n,1);
            break;
        }
        else if(printwin(arr, n) ==2)
            {
                printf("player2 is won\n");
                print_only_win_value(arr,n,2);

                break;
            }
        
    }
    
   

    return 0;
}
