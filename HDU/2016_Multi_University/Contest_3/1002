#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
double ans,p[1010];
int n,i,j;
long long a[1010];
int c(int x)
{
    return x*(x-1);
}
int main()
{


    while (scanf("%d",&n)!=EOF)
    {
    ans=0;
    for (i=1;i<=n;i++)
    scanf("%I64d",&a[i]);
    if (n==1)
    ans=a[1];
    else
    for (i=1;i<=n;i++)
    {
        if ((i==1)||(i==n))
        for (j=1;j<=n;j++)
        ans=ans+a[i]*(j-1)*1.0/((n-1)*n);
        else
        for (j=1;j<=n;j++)
        ans=ans+a[i]*c(j-1)*1.0/((ll)(n-2)*(n-1)*n);
    }
    printf("%.8f\n",ans);
    }
}
