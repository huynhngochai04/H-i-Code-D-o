#include <bits/stdc++.h>
#include <set>
#include <map>
using namespace std;
void merge(int a[],int l,int m,int r)
{
	vector <int> x(a+l,a+m+1);
	vector <int> y(a+m+1,a+r+1);
	int i=0,j=0;
	while (i<x.size()&&j<y.size())
	{
		if (x[i]<=y[j])
		{
			a[l]=x[i];
			l++;
			i++;
		} else
		{
			a[l]=y[j];
			l++;
			j++;
		}
	}
	while (i<x.size())
	{
		a[l]=x[i];
		l++;
		i++;
	}
	while (j<y.size())
	{
		a[l]=y[j];
		l++;
		j++;
	}
}
void mergeSort(int a[],int l,int r)
{
	if (l>=r) return;
	int m=(l+r)/2;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	merge(a,l,m,r);
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int &x:a)
	{
		cin>>x;
	}
	mergeSort(a,0,n-1);
	for (int x:a)
	{
		cout<<x<<" ";
	}
	return 0;
}
