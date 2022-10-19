#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
char binaryNumber[10001];
int dem=0;
char result[10001];
int demResult=0;
char checkString[10];
void convertToBase64(int p)
{
    char test[64];
    int countString=0;
    for (char i='A';i<='Z';i++)
    {
        test[countString]=i;
        countString++;
    }
    for (char i='a';i<='z';i++)
    {
        test[countString]=i;
        countString++;
    }
    for (char i='0';i<='9';i++)
    {
        test[countString]=i;
        countString++;
    }
    test[countString]='+';
    countString++;
    test[countString]='/';
    countString++;
    test[countString]='\0';
    result[demResult]=test[p];
    demResult++;
}
void searchBinary(int target)
{
        char binaryString[4001];
        memset(binaryString,'0',sizeof(binaryString));
        int cnt=0;
        while(target)
        {
            if (target%2==0) binaryString[cnt]='0';
            if (target%2==1) binaryString[cnt]='1';
            cnt++;
            target/=2;
        }
        char reverseString[10001];
        int pk=0;
        for (int i=7;i>=0;i--)
        {
            reverseString[pk]=binaryString[i];
            pk++;
        }
        int k=strlen(binaryString);
        while(k<8)
        {
            for (int i=k;i>0;i--)
            {
                reverseString[i]=reverseString[i-1];
            }
            reverseString[0]='0';
            k++;
            reverseString[k]='\0';
        }
        for (int i=0;i<8;i++)
        {
            checkString[i]=reverseString[i];
        }
        for (int i=0;i<8;i++)
        {
            binaryNumber[dem]=reverseString[i];
            dem++;
        }
}
void solveProblem()
{
    int g=strlen(binaryNumber);
    int a[10001];
    int arrayCount=0;
    if (g%3==0)
    {
        int check=0,mu=0,sum=0;
        for (int i=g-1;i>=0;i--)
        {
            if (binaryNumber[i]=='1') sum+=pow(2,mu);
            mu++;
            check++;
            if (check==6)
            {
                a[arrayCount]=sum;
                sum=0;
                arrayCount++;
                check=0;
                mu=0;
            }
        }
        for (int i=arrayCount-1;i>=0;i--)
        {
            convertToBase64(a[i]);
        }
        printf("%s",result);
    }
    else
    {
        int pre_test=g/8;
        int j=pre_test%3;
        if (j==1)
        {
            int check_dis=0;
            for (int i=g;i<g+8;i++)
            {
                binaryNumber[i]=checkString[check_dis];
                check_dis++;
            }
            for (int i=g+8;i<g+12;i++)
            {
                binaryNumber[i]='0';
            }
            binaryNumber[g+12]='\0';
            int check=0,mu=0,sum=0;
            long long int demsoLan=0;
        for (int i=g+12-1;i>=0;i--)
        {
            if (binaryNumber[i]=='1') sum+=pow(2,mu);
            mu++;
            check++;
            if (check==6&&demsoLan<2)
            {
                demsoLan++;
                check=0;
                a[arrayCount]=sum;
                sum=0;
                mu=0;
                arrayCount++;
            }
            if (demsoLan==2)
            {
                i-=8;
                demsoLan=-9999999999;
            }
        }
            for (int i=arrayCount-1;i>=0;i--)
            {
                convertToBase64(a[i]);
            }
            printf("%s==",result);
        }
        else
        {
            if (j==2)
            {
                binaryNumber[g]='0';
                binaryNumber[g+1]='0';
                binaryNumber[g+2]='\0';
                int check=0,mu=0,sum=0,demsoLan=0;
                for (int i=strlen(binaryNumber)-1;i>=0;i--)
                {
                    if (binaryNumber[i]=='1') sum+=pow(2,mu);
                    mu++;
                    check++;
                    if (check==6)
                    {
                        a[arrayCount]=sum;
                        mu=0;
                        check=0;
                        sum=0;
                        arrayCount++;
                    }
                }
                for (int i=arrayCount-1;i>=0;i--)
                {
                convertToBase64(a[i]);
                }
                printf("%s=",result);
            }
        }
    }
}
int main()
{
    char s[1001];
    gets(s);
    for (int i=0;i<strlen(s);i++)
    {
        searchBinary(s[i]);
    }
    solveProblem();
    return 0;
}
