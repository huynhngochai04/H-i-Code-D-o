#include <bits/stdc++.h>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <stack>
#include <deque>
#include <string>
#include <conio.h>
#define PI 3.141592653589793238

using namespace std;
using ll=long long;
using db=double;
inline ll gcd(ll a,ll b){while (a!=b){if (a>b) a-=b; else b-=a;}};

void exitProgramming(); // Thoat khoi chuong trinh
void getInput(); // Nhap vao tu ban phim su lua chon
void productManagement(); // Quan ly san pham
void billManagement(); // Quan ly hoa don
void exportAll(); // Xuat het tat ca san pham dang co
void buyObject(); // Mua hang tu cua hang
void addObject(); // Them san pham
void editObject(); // Chinh sua san pham
void eraseObject(); // Xoa san pham
void menuConsole(); // Cua so menu
void readDataFromFile(); // doc du lieu tu file
void selectChoice(); // In ra 2 lua chon
void checkOnKeyboard(); // Kiem tra nhap vao tu ban phim 1 hay 2

void exitProgramming()
{
	cout<<"** Tam biet cac ban **";
}

void menuConsole()
{
	printf("*******************************************\n");
	printf("**     CHUONG TRINH QUAN LY BAN HANG     **\n");
	printf("**       1: Quan ly san pham             **\n");
	printf("**       2: Quan ly hoa don              **\n");
	printf("**       3: Thong ke hang hoa            **\n");
	printf("**       4: Mua hang                     **\n");
	printf("**       0: Thoat                        **\n");
	printf("*******************************************\n");
	printf("**       Nhap vao lua chon cua ban       **\n");
}
void getInput()
{
	menuConsole();
	while (1)
	{
	if (_kbhit()) // If you hit on the button on keyboard
	{
		char c=_getch(); // Get character from input
		if (c==-32) c=_getch();
		if (c=='0') 
		{
			exitProgramming();
			break;
		}
		if (c=='1') productManagement();
		if (c=='2') billManagement();
		if (c=='3') exportAll();
		if (c=='4') buyObject();
	}
	}
}

void buyObject()
{
	cout<<"** DAY LA DANH MUC MUA HANG **\n";
	string id="";
	int count=0;
	string name_client="";
	cout<<"Nhap vao ten khach hang: "; getline(cin,name_client);
	string date="";
	cout<<"Nhap vao ngay ban san pham: "; cin>>date;
	cin.ignore();
	if (date[1]=='/') date="0"+date;
	if (date[4]=='/') date.insert(3,"0");
	string name_staff="";
	cout<<"Nhap vao ten nhan vien ban hang: "; 
	cin.ignore();
	getline(cin,name_staff);
	ofstream file;
	file.open("C:\\Users\\ADMIN\\Downloads\\hoa_don.txt",ios::app);
	cout<<"Nhap vao so luong san pham ma khach mua: "; cin>>count;
	file<<"Vao ngay "<<date<<endl;
	file<<"Khach hang ten: "<<name_client<<" da mua hang"<<endl;
	for (int i=0;i<count;i++)
	{
		cout<<"Nhap vao ma san pham khach mua: "; cin>>id;
		int x=0; cout<<"So luong: ";
		cin>>x;
		file<<"Khach hang da mua san pham co id: "<<id;
		file<<" So luong: "<<x<<endl;
	}
	file<<"Ten nhan vien ban hang: "<<name_staff<<endl;
	file.close();
}

void productManagement()
{
	string id="";
	cout<<"*******************************************\n";
	printf("**       MUC QUAN LY BAN HANG            **\n");
	printf("**           1:Them san pham moi         **\n");
	printf("**           2:Sua mat hang              **\n");
	printf("**           3:Xoa mat hang              **\n");
	printf("**           4:Liet ke cac mat hang      **\n");
	printf("**           0:Thoat                     **\n");
	cout<<"*******************************************\n";
	while (1)
	{
		if (_kbhit())
		{
			char c=_getch();
			if (c=='0')
			{
				printf("** Ban da thoat khoi muc quan ly ban hang **\n");
				menuConsole();
				break;
			}
			if (c=='1') addObject();
			if (c=='2') editObject();
			if (c=='3') eraseObject();
			if (c=='4') exportAll();
		}
	}
}

void addObject()
{
	cout<<"** DAY LA DANH MUC THEM SAN PHAM **\n";
	fstream file;
	file.open("C:\\Users\\ADMIN\\Downloads\\san_pham.txt",ios::app);
	string id="",name_object="";
	int price_in=0,price_out=0;
	int remaining=0;
	int k;
	cout<<"Moi ban nhap so san pham can them: ";
	cin>>k;
		for (int i=0;i<k;i++)
		{
		cout<<"Moi ban nhap ma san pham: "; cin>>id; 
		file<<id<<endl;
		cin.ignore();
		cout<<"Moi ban nhap vao ten san pham: "; getline(cin,name_object);
		for (char x:name_object) file<<x;
		file<<endl;
		cout<<"Moi ban nhap vao gia nhap vao: "; cin>>price_in;
		file<<price_in<<endl;
		cout<<"Moi ban nhap vao gia ban ra: "; cin>>price_out; 
		file<<price_out<<endl;
		cout<<"Moi ban nhap vao so luong: "; cin>>remaining; 
		file<<remaining<<endl;
		}
	file.close();
}

void selectChoice()
{
	printf("1: Thay doi\n");
	printf("2: Giu nguyen\n");
}
 
void checkOnKeyboard()
{
		
} 
 
void editObject()
{
	cout<<"** DAY LA DANH MUC CHINH SUA SAN PHAM **\n";
	string id="";
	cout<<"Nhap vao ma san pham ban muon sua: ";
	cin>>id;
	fstream file;
	file.open("C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
	int pos=0;
	int target=0;
	while (!file.eof())
	{
		char tmp[255];
		file.getline(tmp,255);
		int k=0;
		pos++;
		int count=0;
		while (k<id.size())
		{
			if (tmp[k]==id[k]) count++; else break;
			k++;
		}
		if (count==id.size())
		{
			target=pos;
			break;
		}
	}
	file.close();
	ifstream fin;
	fin.open("C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
	ofstream getSwap;
	getSwap.open("C:\\Users\\ADMIN\\Downloads\\trung_gian.txt");
	int dem=1;
	string line="";
	while (getline(fin,line))
	{
		dem++;
		if (dem==target)
		{
			cout<<"Ban co muon thay doi ma san pham khong: \n";
    		selectChoice();
    		int x; cin>>x;
    		if (x==1)
    		{
    			string newID="";
    			cout<<"Moi ban vui long nhap ID moi cho san pham: "; cin>>newID;
    			getSwap<<newID<<endl;
			}
			else
			{
				getSwap<<line<<endl;
			}
		}
		if (dem==target+1)
		{
			cout<<"Ban co muon sua ten san pham khong: \n";
			selectChoice();
			int x;
			cin>>x;
			cin.ignore();
			if (x==1)
			{
				cout<<"Moi ban vui long nhap ten san pham moi: ";
				string name_object="";
				getline(cin,name_object);
				getSwap<<name_object<<endl;
			}
			else
			{
				getSwap<<line<<endl;
			}
		}
		if (dem==target+2)
		{
			cout<<"Ban co muon thay doi gia nhap vao khong: \n";
			selectChoice();
			int x; cin>>x;
			if (x==1)
			{
				cout<<"Moi ban vui long nhap gia thu vao moi: ";
				int newPriceIn=0;
				cin>>newPriceIn;
				getSwap<<newPriceIn<<endl;
			} 
			else
			{
				getSwap<<line<<endl;
			}
		}
		if (dem==target+3)
		{
			cout<<"Ban co muon thay doi gia ban ra khong: \n";
			selectChoice();
			int x; cin>>x;
			if (x==1)
			{
				cout<<"Moi ban nhap vao gia ban ra moi: ";
				int newPriceOut=0;
				cin>>newPriceOut;
				getSwap<<newPriceOut<<endl;
			} else
			{
				getSwap<<line<<endl;
			}
		}
		if (dem==target+4)
		{
			cout<<"Ban co muon thay doi so luong khong: \n";
			selectChoice();
			int x; cin>>x;
			if (x==1)
			{
				cout<<"Moi ban nhap vao so luong moi: ";
				int count=0;
				cin>>count;
				getSwap<<count<<endl;
			} else
			{
				getSwap<<line<<endl;
			}
		}
		if (dem!=target&&dem!=target+1&&dem!=target+2&&dem!=target+3&&dem!=target+4)
		{
			getSwap<<line<<endl;
		}
	}
	getSwap.close();
	fin.close();
	remove("C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
	rename("C:\\Users\\ADMIN\\Downloads\\trung_gian.txt","C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
}

void eraseObject()
{
	cout<<"** DAY LA DANH MUC XOA HANG **\n";
	string id="";
	cout<<"Nhap vao ma san pham ban muon xoa: ";
	cin>>id;
	fstream file;
	file.open("C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
	int pos=0;
	int target=0;
	while (!file.eof())
	{
		char tmp[255];
		file.getline(tmp,255);
		int k=0;
		pos++;
		int count=0;
		while (k<id.size())
		{
			if (tmp[k]==id[k]) count++; else break;
			k++;
		}
		if (count==id.size())
		{
			target=pos;
			break;
		}
	}
	file.close();
	ifstream fin;
	fin.open("C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
	ofstream getSwap;
	getSwap.open("C:\\Users\\ADMIN\\Downloads\\trung_gian.txt");
	int dem=0;
	string line="";
	while (getline(fin,line))
	{
    	dem++;
    	if (dem==target||dem==target+1||dem==target+2||dem==target+3||dem==target+4) continue;
    	else
    	getSwap<<line<<endl;
	}
	getSwap.close();
	fin.close();
	remove("C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
	rename("C:\\Users\\ADMIN\\Downloads\\trung_gian.txt","C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
}

void readDataFromFile(std::string file)
{
	std::fstream fileInput(file);
	while (!fileInput.eof())
	{
		char line[255];
		fileInput.getline(line, 255);
		std::cout << line << std::endl;
	}
	fileInput.close();
}

void billManagement()
{
	ifstream file;
	file.open("C:\\Users\\ADMIN\\Downloads\\hoa_don.txt",ios::in);
	while (!file.eof())
	{
		char tmp[256];
		file.getline(tmp,255);
		std::cout<< tmp << std::endl;
	}
	file.close();
}

void exportAll()
{
	std::fstream fileInput("C:\\Users\\ADMIN\\Downloads\\san_pham.txt");
	printf("*******************************************\n");
	int count=4;
	while (!fileInput.eof())
	{
		char temp[255];
		fileInput.getline(temp,255);
		std::string line = temp;
		if (count!=4)
		{
		if (count%5==0)
		{
			cout<<"Ma san pham: ";
		}
		if (count%5==1)
		{
			cout<<"Ten san pham: ";
		}
		if (count%5==2)
		{
			cout<<"Gia san pham nhap vao: ";
		}
		if (count%5==3)
		{
			cout<<"Gia ban ra hoa don: ";
		}
		if (count%5==4)
		{
			cout<<"So luong con lai: ";
		}
		}
		count++;
		std::cout<<line<<endl;
	}
	fileInput.close();
}

void mainProgramming()
{
	getInput();
}

int main()
{
	mainProgramming();
	return 0;
}
