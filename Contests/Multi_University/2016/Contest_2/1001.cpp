#include<cstdio>
typedef long long ll;
const int N = 201010;
int i;
ll n,a[N],sum,ans,g;
ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
    sum=0;
    ans=0;
    scanf("%I64d",&n);
    for (i=1;i<=n;i++)
    {    
        scanf("%I64d",&a[i]);
        if (a[i]<0) a[i]=-a[i];
        sum+=a[i];
    }
    
    g=n;
    
    
    
    for (i=1;i<=n;i++)
        ans=ans+a[i]*a[i]*g-2*a[i]*sum;
    ans+=sum*sum;
    n=gcd(ans,g);
    ans=ans/n;
    g=g/n;
    printf("%I64d/%I64d\n",ans,g);
    }
}
