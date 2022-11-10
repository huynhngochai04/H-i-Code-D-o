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
class soPhuc{
	private:
		int thuc,ao;
	public:
		friend istream& operator >> (istream& getIn, soPhuc &a);
		friend ostream& operator << (ostream& getOut, soPhuc a);
		soPhuc operator + (soPhuc another);
		soPhuc operator - (soPhuc another);
		bool operator == (soPhuc another);
};
istream& operator >> (istream& getIn, soPhuc &a)
{
	getIn>>a.thuc>>a.ao;
	return getIn;
}
bool soPhuc::operator ==(soPhuc another)
{
	if (this->thuc==another.thuc&&this->ao==another.ao) return true; return false;
}
ostream& operator <<(ostream& getOut, soPhuc a)
{
	getOut<<a.thuc<<" "<<a.ao;
	return getOut;
}
soPhuc soPhuc::operator + (soPhuc another)
{
	soPhuc tong;
	tong.thuc=this->thuc+another.thuc;
	tong.ao=this->ao+another.ao;
	return tong;
}
soPhuc soPhuc::operator - (soPhuc another)
{
	soPhuc hieu;
	hieu.thuc=this->thuc-another.thuc;
	hieu.ao=this->ao-another.ao;
	return hieu;
 } 
int main()
{ 
	soPhuc a,b;
	cin>>a>>b;
	cout<<a+b<<endl<<a-b<<endl;
	if (a==b)
	{
		cout<<"YES";
	} else cout<<"NO";
	return 0;
}
