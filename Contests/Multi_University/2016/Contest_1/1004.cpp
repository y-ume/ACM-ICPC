#include<bits/stdc++.h>
using namespace std;
const int N = 201010;
int s[N][20],i,j,n,t,l,r,m,a,b;
int Log[N];
map<int,long long> ans;
int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int query(int a,int b)
{
    int k=Log[b-a+1];
    return gcd(s[a][k],s[b-(1<<k)+1][k]);
}
int main()
{
    for (i=2;i<=100000;i++)
    Log[i]=Log[i/2]+1;
    
    int test,ii=0;
    scanf("%d",&test);
    while (test--)
    {
    scanf("%d",&n);
    ans.clear();
    for (i=1;i<=n;i++)
    scanf("%d",&s[i][0]);
    for (j=1;j<20;j++)
    for (i=1;i<=n;i++)
    if (i+(1<<j)-1<=n)
    s[i][j]=gcd(s[i][j-1],s[i+(1<<(j-1))][j-1]);
    
    for (i=1;i<=n;i++)
    {
        t=i;
        while (t<=n)
        {
            l=t;r=n;
            while (l<=r)
            {
                m=(l+r)>>1;
                if (query(i,m)==query(i,t)) l=m+1;else r=m-1;
            }
            ans[query(i,t)]+=r-t+1;
            t=r+1;
        }
    }
    scanf("%d",&m);
    printf("Case #%d:\n",++ii);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d %I64d\n",query(a,b),ans[query(a,b)]);
    }
    }
}
