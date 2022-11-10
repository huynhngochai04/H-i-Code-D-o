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
class giaoVien;
class sinhVien;
class sinhVien{
	friend class giaoVien;
	private: // ham private ( ko lay dc truc tiep nhung co the thong qua getter hoac setter )
		string id,name,birthday;
		double gpa;
		static int dem;
	public:
		//constructor 
		void getInformation(); // Nhap thong tin sinhVien
		void printInformation(); // in ra thong tin
		void upperID();
		friend void chuanHoa(sinhVien&);
		int getCount();
		friend istream& operator >> (istream &getIn, sinhVien&);
		friend ostream& operator << (ostream &getOut, sinhVien);
		friend bool operator < (sinhVien a, sinhVien b);
};
bool operator<(sinhVien a,sinhVien b)
{
	if (a.gpa<b.gpa) return a.gpa; else return b.gpa;
}
//Implementation
istream& operator >> (istream &getIn, sinhVien&a){
	getIn.ignore();
	cout<<"Get your id :";
	getIn >> a.id;
	cout<<"Get your name :"; getIn.ignore();
	getline(getIn,a.name);
	cout<<"Get your birthday :"; getIn >> a.birthday;
	cout<<"Get your GPA :"; getIn >> a.gpa;
	return getIn;
}
ostream& operator << (ostream &getOut, sinhVien a)
{
	getOut << a.id << " " << a.name <<" "<<a.birthday <<" "<< fixed <<setprecision(2)<<a.gpa;
}
int sinhVien::dem=0;
void sinhVien::upperID()
{
	++dem;
}
void chuanHoa (sinhVien &a)
{
	string tmp="";
	stringstream ss(a.name);
	string result="";
	while (ss>>tmp)
	{
		for (char &x:tmp) x=tolower(x);
		tmp[0]=toupper(tmp[0]);
		result+=tmp+" ";
	}
	result.erase(result.size()-1);
	a.name = result;
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
	cout<<"Get your name: "; getline(cin,name);
	cout<<"Get your birthday: "; cin>>this->birthday;
	cin.ignore();
	cout<<"Get your GPA: "; cin>>this->gpa;
}
void sinhVien::printInformation()
{
	cout<<this->id<<" "<<this->name<<" "<<this->birthday<<" "<<fixed<<setprecision(2)<<this->gpa<<" ";
	cout<<endl;
}
class giaoVien{
	private:
		string khoa;
	public:
		void update(sinhVien&);
};
void giaoVien::update(sinhVien &x)
{
	x.gpa=3.20;
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
	sort(a,a+n);
	for (sinhVien x:a)
	{
		cout<<x<<endl;
	}
	return 0;
}
