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
class lecturers{
	private:
		string id,name,subject;
		static int count;
	public:
		string getSubject()
		{
			return this->subject;
		}
		int getCount()
		{
			return this->count;
		}
		friend istream& operator >> (istream & getIn, lecturers &a);
		friend ostream& operator << (ostream& getOut, lecturers a);
		friend void chuanHoa (lecturers &);
		void upperCount();
		bool operator == (string s);
};
int lecturers::count=0;
bool lecturers::operator ==(string s)
{
	stringstream ss(s);
	string tmp="";
	string result="";
	while (ss>>tmp)
	{
		result+=toupper(tmp[0]);
	}
	return this->subject==result;
}
void lecturers::upperCount()
{
	count++;
}
istream& operator >> (istream& getIn, lecturers &a)
{
	getline(getIn,a.name);
	getline(getIn,a.subject);
	return getIn;
}
void chuanHoa (lecturers &a)
{
	a.upperCount();
	string s=a.subject;
	stringstream ss(s);
	string tmp="";
	string result="";
	while (ss>>tmp)
	{
		result+=toupper(tmp[0]);
	}
	a.subject=result;
	a.id="GV";
	ostringstream convert;
	convert<<a.getCount();
	string p=convert.str();
	int k=p.size();
	while (k<2)
	{
		p="0"+p;
		k++;
	}
	a.id=a.id+p;
}
ostream& operator << (ostream& getOut,lecturers a)
{
	getOut<<a.id<<" "<<a.name<<" "<<a.subject<<endl;
	return getOut;
}
int main()
{
	int n;
	cin>>n;
	lecturers a[n];
	cin.ignore();
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		chuanHoa(a[i]);
	}
	int T;
	cin>>T;
	cin.ignore();
	while (T--)
	{
		string pre_test;
		getline(cin,pre_test);
		cout<<"DANH SACH GIANG VIEN BO MON ";
		stringstream ss(pre_test);
		string tmp="";
		string result="";
		while (ss>>tmp)
		{
			result+=toupper(tmp[0]);
		}
		cout<<result<<":"<<endl;
		for (lecturers x:a)
		{
			if (x==pre_test)
			{
				cout<<x;
			}
		}
		cout<<endl;
	}
	return 0;
}
