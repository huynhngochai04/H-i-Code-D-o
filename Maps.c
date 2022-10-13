#include <stdio.h>
#include <string.h>
int n,m;
int a[1001][1001];
int dx[8]={-1,0,0,1,-1,-1,1,1};
int dy[8]={0,-1,1,0,1,-1,1,-1};
int visited[1001][1001];
int p=0;
void DFS(int i,int j)
{
    visited[i][j]=1;
    int c=0;
    for (int k=1;k<=8;k++)
    {
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=0&&i1<=n-1&&j1>=0&&j1<=m-1&&a[i1][j1]==1&&visited[i1][j1]==0)
        {
            DFS(i1,j1);
        }
    }
}
void inp()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int cnt=0;
    memset(visited,0,sizeof(visited));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]==1&&visited[i][j]==0)
            {
                DFS(i,j);
                p++;
            }
        }
    }
        printf("%d",p);
}
int main()
{
    inp();
    return 0;
}
