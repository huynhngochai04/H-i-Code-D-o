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
int n=8,m=8,s,t,u,v;
int a[1001][1001];
int visited[1001][1001];
int d[1001][1001];
int dx[8]={-2,-2,-1,1,-1,1,2,2};
int dy[8]={-1,1,-2,-2,2,2,-1,1};
void bfs(int i,int j) // tim kiem duong di ngan nhat hang doi
{
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j]=0;
	d[i][j]=0;
	while(!q.empty())
	{
		pair<int,int> top=q.front(); q.pop();
		for (int k=0;k<8;k++)
		{
			int i1=top.first+dx[k];
			int j1=top.second+dy[k];
			if (i1>=0&&i1<=n-1&&j1>=0&&j1<=m-1&&a[i1][j1]!=0)
			{
				d[i1][j1]=d[top.first][top.second]+1;
				if (i1==u&&j1==v) return;
				q.push({i1,j1});
				a[i1][j1]=0;
			}
		}
	}
}
void inp()
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			a[i][j]=1;
		}
	}
	cin>>s>>t>>u>>v;
	bfs(s,t);
	cout<<d[u][v]<<endl;
}
int main()
{ 
	inp();
	return 0;
}
