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
class phanSo{
	private:
		int a,b;
	public:
		friend int solveProblem(phanSo);
		friend istream& operator >> (istream& getIn,phanSo &a);
		friend ostream& operator << (ostream& getOut,phanSo a);
};
istream&operator >> (istream& getIn,phanSo &a)
{
	getIn>>a.a>>a.b;
	return getIn;
}
int solveProblem(phanSo a)
{
	while (a.a!=a.b)
	{
		if (a.a>a.b) a.a-=a.b; else a.b-=a.a;
	}
	return a.a;
}
ostream &operator << (ostream & getOut,phanSo a)
{
	int ucln=solveProblem(a);
	cout<<a.a/ucln<<"/"<<a.b/ucln;
}
int main()
{ 
	phanSo a;
	cin>>a;
	cout<<a;
	return 0;
}
