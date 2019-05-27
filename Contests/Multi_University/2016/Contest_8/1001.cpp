#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
const int N = 1010101;
vector<int> num;
int n,m,i,j,Flag,o,k,l,r,a[N],b[N],flag[N];
int main()
{
    int test,ii;
    scanf("%d",&test);
    for (ii=1;ii<=test;ii++)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
            flag[i]=0;
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (i=1;i<=n;i++)
            scanf("%d",&b[i]);
        Flag=0;
        for (i=1;i<=n;i++) {
            for (j=1;j<=n;j++)
                if ((a[i]==b[j])&&(flag[j]==0))
                {
                    flag[j]=1;
                    a[i]=j;
                    break;
                }
            if (j>n) Flag=1;
        }

        for (i=1;i<=n;i++)
            if ((b[i])&&(flag[i]==0)) Flag=1;

        if (Flag==1)
        {
            for (i=1;i<=m;i++)
                scanf("%d%d",&l,&r);
            printf("No\n");
        }
        else
        {
            for (i=1;i<=m;i++)
            {
                scanf("%d%d",&l,&r);
                num.clear();
                for (j=l;j<=r;j++)
                    if (a[j]) num.pb(a[j]),a[j]=0;
                sort(num.begin(),num.end());
                if (num.size())
                {
                    j=0;k=num.size()-1;
                    while ((j<=k)&&(num[j]<l)) a[l]=num[j],j++,l++;
                    while ((j<=k)&&(num[k]>r)) a[r]=num[k],k--,r--;
                    while (j<=k)
                    {
                        a[num[j]]=num[j];
                        j++;
                    }
                }
            }

            Flag=0;
            for (i=1;i<=n;i++)
                if (a[i])
                    if (a[i]!=i) Flag=1;

            if (Flag) printf("No\n");else printf("Yes\n");
        }
    }
}
