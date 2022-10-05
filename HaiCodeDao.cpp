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
inline ll gcd(ll a,ll b){while (a!=b){if (a>b) a-=b; else b-=a;}};
int main()
{
	string s;
	getline(cin,s);
	stringstream ss(s);
	string tmp="";
	string pre_check="";
	int dem=0;
	stack <int> st;
	while (ss>>tmp)
	{
		dem=0;
		for (char x:tmp)
		{
			if (x=='-')
			{
				int p=stoi(tmp);
				st.push(p);
				break;
			} else if (x>='0'&&x<='9')
			{
				st.push(stoi(tmp));
				break;
			}
		}
		if (tmp[0]=='C') st.pop();
		if (tmp[0]=='D') st.push(st.top()*2);
		if (tmp[0]=='+') 
		{
			int target=st.top();
			st.pop();
			int pre_dis=st.top();
			st.push(target);
			st.push(target+pre_dis);
		}
	}
	ll sum=0;
	while (!st.empty())
	{
		sum+=st.top();
		st.pop();
	}
	cout<<sum;
	return 0;
}
