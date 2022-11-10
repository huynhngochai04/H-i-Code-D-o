#include <bits/stdc++.h>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <stack>
#include <deque>
#include <string>
#define PI 3.141592653589793238
using namespace std;
using ll=long long;
using db=double;
inline ll gcd(ll a,ll b){while (a!=b){if (a>b) a-=b; else b-=a;}};
//1 class: lop - private
//2 thuoc tinh: attribute - public
//3 phuong thuc: method, behavior - protected
// object: doi tuong
//constructor : ham khoi tao
//destructor : ham huy
//this pointer
//Encapsulation : dong goi
//Acess modifier:
//1 Private;
//2 public
//3 protected
//SV001=>SV002=>SV003
//forward declaration
class sinhVien{
	private:
		string id,name,lop,email;
	public:
		friend istream& operator >> (istream& getIn, sinhVien &x);
		friend ostream& operator << (ostream& getOut,sinhVien x);
		bool operator == (string s);
};
bool sinhVien::operator ==(string s)
{
	return this->lop==s;
}
istream& operator >> (istream& getIn,sinhVien &x)
{
	getIn>>x.id;
	getIn.ignore();
	getline(getIn,x.name);
	getIn>>x.lop;
	getIn>>x.email;
	return getIn;
}
ostream& operator << (ostream& getOut, sinhVien x)
{
	getOut<<x.id<<" "<<x.name<<" "<<x.lop<<" "<<x.email<<endl;
	return getOut;
}
int main()
{ 
	int n;
	cin>>n;
	sinhVien a[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int q;
	cin>>q;
	while (q--)
	{
		string check;
		cin>>check;
		cout<<"DANH SACH SINH VIEN LOP "<<check<<endl<<endl;
		for (int i=0;i<n;i++)
		{
			if (a[i]==check) 
			{
				cout<<a[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
