#include <stdio.h>
int a[100][100];
int main() {
	int m,n,p;
	scanf("%d%d%d",&m,&n,&p);
	int a[m][n];
	int b[n][p];
	int c[m][p];
	for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<p;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<p;j++)
        {
            c[i][j]=0;
            for (int z=0;z<n;z++)
            {
                c[i][j]+=a[i][z]*b[z][j];
            }
            printf("%*d",6,c[i][j]);
        }
        printf("\n");
    }
	return 0;
}
