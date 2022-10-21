#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
typedef long long int ll;
typedef unsigned int u;
void swapString(char *ptr1,char *ptr2)
{
    char temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
char reverseString(char *x,int start,int end)
{
    if (start<end)
    {
    swapString(x+start,x+end);
    reverseString(x,++start,--end);
    }
}
int main(){
    char s[1001];
    gets(s);
    reverseString(s,0,strlen(s)-1);
    printf("%s",s);
    return 0;
}
