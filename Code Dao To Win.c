#include <stdio.h>
#include <string.h>
int n,m;
int a[1001][1001];
int dx[8]={-1,0,0,1,1,1,-1,-1};
int dy[8]={0,-1,1,0,-1,1,1,-1};
int visited[1001][1001]={0};
int cnt=0;
void nhap()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
int DFS(int i,int j)
{
    int sum=0;
    for (int k=0;k<8;k++)
    {
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=0&&i1<=n-1&&j1>=0&&j1<=m-1&&a[i1][j1]==1) sum++;
    }
    return sum;
}
void solveProblem(int a[1001][1001])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]==0) printf("0 "); else
            {
                printf("%d ",DFS(i,j));
            }
        }
        printf("\n");
    }
}
int main()
{
    nhap();
    solveProblem(a);
    return 0;
}
