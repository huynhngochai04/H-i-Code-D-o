
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
typedef long long int ll;
typedef unsigned int u;
int length1=0,length2=0;
void getInput()
{
    scanf("%d",&length1);
    char a[length1*2];
    getchar();
    for (int i=0;i<length1*2;i++)
    {
        scanf("%c",&a[i]);
    }
    scanf("%d",&length2);
    getchar();
    char b[length2*2];
    for (int i=0;i<length2*2;i++)
    {
        scanf("%c",&b[i]);
    }
    int cnt=0;
    int target1=0,target2=0;
    int d=0;
    char c[1001];
    int mu=2;
    if (length2<=length1)
    {
    for (int i=0;i<length1*2;i++)
    {
        if (length2*mu==i)
        {
            d=0;
            mu+=2;
        }
        if (a[i]>='0'&&a[i]<='9') target1=a[i]-'0';
        else
        {
            if (a[i]=='A') target1=10;
            if (a[i]=='B') target1=11;
            if (a[i]=='C') target1=12;
            if (a[i]=='D') target1=13;
            if (a[i]=='E') target1=14;
            if (a[i]=='F') target1=15;
        }
        if (b[d]>='0'&&b[d]<='9') target2=b[d]-'0';
        else
        {
            if (b[d]=='A') target2=10;
            if (b[d]=='B') target2=11;
            if (b[d]=='C') target2=12;
            if (b[d]=='D') target2=13;
            if (b[d]=='E') target2=14;
            if (b[d]=='F') target2=15;
        }
        int k=target1^target2;
        if (k>=0&&k<=9)
        {
            c[cnt]=k+'0';
        }
        else
        {
            if (k==10) c[cnt]='A';
            if (k==11) c[cnt]='B';
            if (k==12) c[cnt]='C';
            if (k==13) c[cnt]='D';
            if (k==14) c[cnt]='E';
            if (k==15) c[cnt]='F';
        }
        cnt++;
        d++;
    }
    }
    else
    {
        for (int i=0;i<length2*2;i++)
    {
        if (length1*mu==i)
        {
            d=0;
            mu+=2;
        }
        if (a[d]>='0'&&a[d]<='9') target1=a[d]-'0';
        else
        {
            if (a[d]=='A') target1=10;
            if (a[d]=='B') target1=11;
            if (a[d]=='C') target1=12;
            if (a[d]=='D') target1=13;
            if (a[d]=='E') target1=14;
            if (a[d]=='F') target1=15;
        }
        if (b[i]>='0'&&b[i]<='9') target2=b[i]-'0';
        else
        {
            if (b[i]=='A') target2=10;
            if (b[i]=='B') target2=11;
            if (b[i]=='C') target2=12;
            if (b[i]=='D') target2=13;
            if (b[i]=='E') target2=14;
            if (b[i]=='F') target2=15;
        }
        int k=target1^target2;
        if (k>=0&&k<=9)
        {
            c[cnt]=k+'0';
        }
        else
        {
            if (k==10) c[cnt]='A';
            if (k==11) c[cnt]='B';
            if (k==12) c[cnt]='C';
            if (k==13) c[cnt]='D';
            if (k==14) c[cnt]='E';
            if (k==15) c[cnt]='F';
        }
        cnt++;
        d++;
    }
    }
    for (int i=0;i<cnt;i++)
    {
        printf("%c",c[i]);
    }
}
int checkPrimeNumber(int n)
{
    if (n<2) return 0;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}
void swap(int *ptr1,int *ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
void bubbleSort(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (a[i]>a[j])
            {
                swap(&a[i],&a[j]);
            }
        }
    }
}
int main(){
    getInput();
    return 0;
}
