#include <bits/stdc++.h>
#include <set>
#include <map>
#include <sstream>
#include <stack>
using namespace std;
using ll=long long ;
ll sum;
int main()
{
	int a,b;
	cin>>a>>b;
	string pre_fake;
	cin>>pre_fake;
	ll n=0;
	for (char &x:pre_fake) x=toupper(x);
	if (a==b)
	{
		cout<<pre_fake;
		return 0;
	}
	if (a==2)
	{
		int p=pre_fake.size()-1;
		for (int i=0;i<pre_fake.size();i++)
		{
			if (pre_fake[i]!=0)
			{
				sum+=(pre_fake[i]-48)*pow(a,p);
			}
			p--;
		}
	}
	if (a>2&&a<=9)
	{
		int p=pre_fake.size()-1;
		for (int i=0;i<pre_fake.size();i++)
		{
			if (pre_fake[i]!=0)
			{
				sum+=(pre_fake[i]-48)*pow(a,p);
			}
			p--;
		}
	}
	if (a>10)
	{
		int p=pre_fake.size()-1;
		int pre_test=0;
		for (int i=0;i<pre_fake.size();i++)
		{
			if (pre_fake[i]=='A')
			{
			
				pre_test=10;
			}
			if (pre_fake[i]=='B')
			{
				pre_test=11;
			}
			if (pre_fake[i]=='C')
			{
				pre_test=12;
			}
			if (pre_fake[i]=='D')
			{
				pre_test=13;
			}
			if (pre_fake[i]=='E')
			{
				pre_test=14;
			}
			if (pre_fake[i]=='F')
			{
				pre_test=15;
			}
			if (pre_fake[i]>='0'&&pre_fake[i]<='9')
			{
				pre_test=pre_fake[i]-48;
			}
			sum+=pre_test*pow(a,p);
			p--;
		}
	}
	if (a!=10) n=sum; else n=stoi(pre_fake);
	if (b==10)
	{
		cout<<sum;
		return 0;
	}
	if (b==2)
	{
	stack <int> st;
	while (n)
	{
		if (n%2==0) st.push(0); else st.push(1);
		n/=b;
	}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	if (b>2&&b<10)
	{
		stack <int> st;
	while (n)
	{
		st.push(n%b);
		n/=b;
	}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	if (b==11)
	{
		stack <string> st;
		while (n)
		{
			ostringstream convert;
			convert<<n%11;
			string ss=convert.str();
			if (n%11>=0&&n%11<=9) st.push(ss); else 
			{
				if (n%11==10)
				{
					st.push("A");
				}
			}
			n/=b;
		}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	if (b==12)
	{
		stack <string> st;
		while (n)
		{
			ostringstream convert;
			convert<<n%12;
			string ss=convert.str();
			if (n%12>=0&&n%12<=9) st.push(ss); else 
			{
				if (n%12==10)
				{
					st.push("A");
				}
				if (n%12==11)
				{
					st.push("B");
				}
			}
			n/=b;
		}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	if (b==13)
	{
		stack <string> st;
		while (n)
		{
			ostringstream convert;
			convert<<n%13;
			string ss=convert.str();
			if (n%13>=0&&n%13<=9) st.push(ss); else 
			{
				if (n%13==10)
				{
					st.push("A");
				}
				if (n%13==11)
				{
					st.push("B");
				}
				if (n%13==12)
				{
					st.push("C");
				}
			}
			n/=b;
		}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	if (b==14)
	{
		stack <string> st;
		while (n)
		{
			ostringstream convert;
			convert<<n%14;
			string ss=convert.str();
			if (n%14>=0&&n%14<=9) st.push(ss); else 
			{
				if (n%14==10)
				{
					st.push("A");
				}
				if (n%14==11)
				{
					st.push("B");
				}
				if (n%14==12)
				{
					st.push("C");
				}
				if (n%14==13)
				{
					st.push("D");
				}
			}
			n/=b;
		}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	if (b==15)
	{
		stack <string> st;
		while (n)
		{
			ostringstream convert;
			convert<<n%15;
			string ss=convert.str();
			if (n%15>=0&&n%15<=9) st.push(ss); else 
			{
				if (n%15==10)
				{
					st.push("A");
				}
				if (n%15==11)
				{
					st.push("B");
				}
				if (n%15==12)
				{
					st.push("C");
				}
				if (n%15==13)
				{
					st.push("D");
				}
				if (n%15==14)
				{
					st.push("E");
				}
			}
			n/=b;
		}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	if (b==16)
	{
		stack <string> st;
		while (n)
		{
			ostringstream convert;
			convert<<n%16;
			string ss=convert.str();
			if (n%16>=0&&n%16<=9) st.push(ss); else 
			{
				if (n%16==10)
				{
					st.push("A");
				}
				if (n%16==11)
				{
					st.push("B");
				}
				if (n%16==12)
				{
					st.push("C");
				}
				if (n%16==13)
				{
					st.push("D");
				}
				if (n%16==14)
				{
					st.push("E");
				}
				if (n%16==15)
				{
					st.push("F");
				}
			}
			n/=b;
		}
		while (!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
	}
	return 0;
}
