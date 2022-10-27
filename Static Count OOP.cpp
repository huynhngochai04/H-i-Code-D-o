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
class sinhVien{
	private: // ham private ( ko lay dc truc tiep nhung co the thong qua getter hoac setter )
		string id,name,birthday;
		double gpa;
		static int dem;
	public:
		//constructor 
		void getInformation(); // Nhap thong tin sinhVien
		void printInformation(); // in ra thong tin
		void upperID();
		int getCount();
};
//Implementation
int sinhVien::dem=0;
void sinhVien::upperID()
{
	++dem;
}
int sinhVien::getCount()
{
	return dem;
}
void sinhVien::getInformation()
{
	dem++; // dem = 1;
	this->id = "SV"+string(3-to_string(dem).size(),'0')+to_string(dem); // SV 001
	cin.ignore();
	cout<<"Get your name:"; getline(cin,name);
	cout<<"Get your birthday:"; cin>>this->birthday;
	cin.ignore();
	cout<<"Get your GPA:"; cin>>this->gpa;
}
void sinhVien::printInformation()
{
	cout<<this->id<<" "<<this->name<<" "<<this->birthday<<" "<<fixed<<setprecision(2)<<this->gpa<<" ";
	cout<<endl;
}
int main()
{ 
	int n;
	cin>>n;
	sinhVien a[n];
	for (int i=0;i<n;i++)
	{
		a[i].getInformation();
	}
	for (int i=0;i<n;i++)
	{
		a[i].printInformation();
	}
	return 0;
}
