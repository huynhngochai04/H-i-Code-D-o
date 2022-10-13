#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char k[1000];
    gets(k);
    int count[127]={0};
    for (int i=0;i<strlen(k);i++) k[i]=tolower(k[i]);
    for (int i=0;i<strlen(k);i++)
    {
        if (count[k[i]]==0)
        {
            count[k[i]]=1;
            for (int j=i+1;j<strlen(k);j++)
            {
                if (k[j]==k[i]) count[k[i]]++;
            }
        }
    }
    for (int i=33;i<=126;i++)
    {
        if (count[i]!=0)
        {
            printf("%c: %d",i,count[i]);
            printf("\n");
        }
    }
    return 0;
}
