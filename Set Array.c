#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
typedef long long int ll;
typedef unsigned int u;
int a[1001][1001];
int m,n;
void getInput()
{
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void sapXepTang(int a[100][100],int m,int n)
{
    int k=m*n;
    for (int i=0;i<k-1;i++)
    {
        for (int j=i+1;j<k;j++)
        {
            if (a[i/n][i%n]>a[j/n][j%n])
            {
                int tg=a[i/n][i%n];
                a[i/n][i%n]=a[j/n][j%n];
                a[j/n][j%n]=tg;
            }
        }
    }
}
void sapXepGiam(int a[100][100],int m,int n)
{
    int k=m*n;
    for (int i=0;i<k-1;i++)
    {
        for (int j=i+1;j<k;j++)
        {
            if (a[i/n][i%n]<a[j/n][j%n])
            {
                int tg=a[i/n][i%n];
                a[i/n][i%n]=a[j/n][j%n];
                a[j/n][j%n]=tg;
            }
        }
    }
}
void printMatrix(int a[100][100],int m,int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
         if (i%2==1)   printf("%*d",6,a[i][j]); else printf("%*d",6,a[i][n-j-1]);
        }
        printf("\n");
    }
}
int main() {
	getInput();
	return 0;
}
