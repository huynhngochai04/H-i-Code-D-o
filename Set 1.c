#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
int main()
{
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
    int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
    int a[9][9]={0};
    if (x1<=7) x1++;
    if (y1<=7) y1++;
    if (x2<=7) x2++;
    if (y2<=7) y2++;
    for (int i=1;i<=8;i++)
    {
        for (int j=1;j<=8;j++)
        {
            if (i%2==0&&j%2==1) a[i][j]=1; else if (i%2==1&&j%2==0) a[i][j]=1;
        }
    }
    int check=0;
        if (a[x1][y1]==a[x2][y2])
        {
            for (int i=1;i<=7;i++)
            {
                if ((x1+i==x2&&y2+i==y1)||(x1-i==x2&&y2==y1+i)||(x1-i==x2&&y1-i==y2)||(x2==x1+i&&y2==y1+i)||x1==x2||y1==y2)
                {
                    printf("Hau an duoc ma");
                    check++;
                    break;
                }
            }
            if (check==0) printf("Hau khong an duoc ma");
        } else {
            if (x1!=x2&&y1!=y2) printf("Hau khong an duoc ma");
            else if (x1==x2||y1==y2) printf("Hau an duoc ma");
        }
        printf("\n");
        if (a[x2][y2]==a[x1][y1])
        {
            printf("Ma khong an duoc hau");
            return 0;
        }
        else
        {
            for (int i=1;i<=8;i++)
            { // 3 2 an duoc | 5 1 | 5 3 | 1 1 | 1 3
                int x=x2+X[i],y=y2+Y[i];
                if ((x==x1&&y==y1))
                {
                    printf("Ma an duoc hau");
                    return 0;
                }
            }
            printf("Ma khong an duoc hau");
        }
    return 0;
}
