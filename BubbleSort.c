
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
typedef long long int ll;
typedef unsigned int u;
void bubbleSort();
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
    int cnt=0;
    printf("%4d:",0);
    for (int i=0;i<n;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
    cnt++;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                printf("%4d:",cnt);
                cnt++;
                for (int z=0;z<n;z++)
                {
                    printf("%4d",a[z]);
                }
                printf("\n");
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubbleSort(a,n);
    return 0;
}
