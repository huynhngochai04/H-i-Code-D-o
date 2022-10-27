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
	public:
		//constructor 
		sinhVien(string,string,string,double); // Ham co san neu co du 4 thanh phan
		sinhVien(); // Ham co san neu sinhVien nhap vao = "\0";
		void getInformation(); // Nhap thong tin sinhVien
		double getGpa(); // Lay GPA thong qua getGpa
		string getId(); // lay ID thong qua ham getID ( lay trong private )
		void setGpa(double gpa); // thay doi GPA co trong ham private
		void printInformation(); // in ra thong tin
		~sinhVien(); // khi ket thuc cac thu tuc thi ham nay se duoc goi
};
//Implementation
sinhVien::sinhVien()
{
	
}
sinhVien::sinhVien(string id,string name,string birthday,double gpa)
{
	this->id = id;
	this->name = name;
	this->birthday = birthday;
	this->gpa = gpa;
}
void sinhVien::getInformation()
{
	cout<<"Get your id number:"; cin>>this->id;
	cin.ignore();
	cout<<"Get your name:"; getline(cin,name);
	cout<<"Get your birthday:"; cin>>this->birthday;
	cin.ignore();
	cout<<"Get your GPA:"; cin>>this->gpa;
}
void sinhVien::setGpa(double gpa)
{
	this->gpa = gpa;
}
void sinhVien::printInformation()
{
	cout<<this->id<<" "<<this->name<<" "<<this->birthday<<" "<<fixed<<setprecision(2)<<this->gpa<<" ";
}
double sinhVien::getGpa()
{
	return this->gpa;
}
string sinhVien::getId()
{
	return this->id;
}
bool cmp(sinhVien a,sinhVien b)
{
	return a.getGpa() > b.getGpa();
}
int main()
{ 
	sinhVien x;
	x.getInformation();
	x.setGpa(4.0);
	x.printInformation();
	return 0;
}
