#include <bits/stdc++.h>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <stack>
#include <deque>
#define PI 3.141592653589793238
using namespace std;
using ll=long long;
int m,n;
int a[1001][1001];
int dx[8]={-1,0,0,1,1,1,-1,-1};
int visited[1001][1001]={0};
int dy[8]={0,1,-1,0,1,-1,1,-1};
int check=0;
inline ll gcd(ll a,ll b){while (a!=b){if (a>b) a-=b; else b-=a;}};
void DFS(int i,int j)
{
	visited[i][j]=1;
    for (int k=0;k<8;k++)
    {
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=0&&i1<=m-1&&j1>=0&&j1<=n-1&&a[i1][j1]==0&&visited[i1][j1]==0)
        {
        	if (i1==m-1)
        	{
        		check++;
        		return;
			}
			DFS(i1,j1);
        }
    }
}
void getInput()
{
	cin>>m>>n;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	if (m==1)
	{
		cout<<"Yes";
		return;
	}
	memset(visited,0,sizeof(visited));
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (a[i][j]==0&&i==0&&visited[i][j]==0)
			{
				DFS(i,j);
				if (check!=0) 
				{
					cout<<"Yes";
					return;
				}
			}
		}
	}
	cout<<"No";
}
int main()
{
	getInput();
	return 0;
}
