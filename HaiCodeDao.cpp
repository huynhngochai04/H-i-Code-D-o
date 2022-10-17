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
using db=double;
inline ll gcd(ll a,ll b){while (a!=b){if (a>b) a-=b; else b-=a;}};
ll cnt=0;
int n,m,s,t,u,v;
int a[1001][1001];
int visited[1001][1001];
int d[1001][1001];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
void bfs(int i,int j) // tim kiem duong di ngan nhat hang doi
{
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j]=1;
	d[i][j]=0;
	while(!q.empty())
	{
		pair<int,int> top=q.front(); q.pop();
		for (int k=0;k<4;k++)
		{
			int i1=top.first+dx[k];
			int j1=top.second+dy[k];
			if (i1>=0&&i1<=n-1&&j1>=0&&j1<=m-1&&a[i1][j1]==a[u][v])
			{
				d[i1][j1]=d[top.first][top.second]+1;
				if (i1==u&&j1==v) return;
				q.push({i1,j1});
				a[i1][j1]=1;
			}
		}
	}
}
void inp()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>s>>t>>u>>v;
	if (a[s][t]==1||a[u][v]==1||s<0||t<0||u<0||v<0||t>m-1||v>m-1||s>n-1||u>n-1)
	{
		cout<<"-1";
		return;
	}
	else
	{
	bfs(s,t);
    if (!d[u][v]) cout<<"-1"; else cout<<d[u][v]<<endl;
	}
}
int main()
{ 
	inp();
	return 0;
}
