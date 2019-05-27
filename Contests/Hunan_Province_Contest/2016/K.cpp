#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1010;
const int P = 1000000007;
char s[N][N];
long long DP[N][N],dp[N][N];
int h[N],n,m,i,j,sum,top,stack[N];
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
	for (i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (i=0;i<=n+1;i++)
		for (j=0;j<=m+1;j++)
		{
			dp[i][j]=0;
			DP[i][j]=0;
		}
	for (i=0;i<=m+1;i++) 
		h[i]=0;
	for (i=1;i<=n;i++)
	{
		top=0;
		sum=0;
		for (j=1;j<=m;j++)
		{
			if (s[i][j]=='0')
		    h[j]++;
		    else
		    h[j]=0;

		    while ((top)&&(h[j]<=h[stack[top]])) 
			{
				sum=sum-h[stack[top]]*(stack[top]-stack[top-1]);
				top--;
			}
		    stack[++top]=j;
		    sum=sum+h[stack[top]]*(stack[top]-stack[top-1]);
		    dp[i][j]=sum;
		}
	}

	for (i=0;i<=m+1;i++)
		h[i]=0;
	for (i=n;i>=1;i--)
	{
		top=0;stack[top]=m+1;
		sum=0;
		for (j=m;j>=1;j--)
		{
			if (s[i][j]=='0')
				h[j]++;
			else
				h[j]=0;

			while ((top)&&(h[j]<=h[stack[top]]))
			{
				sum=sum-h[stack[top]]*(stack[top-1]-stack[top]);
				top--;
			}
			stack[++top]=j;
			sum=sum+h[stack[top]]*(stack[top-1]-stack[top]);
			DP[i][j]=sum;
		}
	}

	for (i=n;i>=1;i--)
		for (j=m;j>=1;j--)
			DP[i][j]=((DP[i][j]+DP[i+1][j]+DP[i][j+1]-DP[i+1][j+1])%P+P)%P;

	long long ans=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		ans=((ans+(DP[i+1][1]+DP[1][j+1]-DP[i+1][j+1])*dp[i][j]%P)%P+P)%P;


	for (i=0;i<=m+1;i++)
		h[i]=0;
	for (i=0;i<=n+1;i++)
		for (j=0;j<=m+1;j++)
			dp[i][j]=DP[i][j]=0;
	for (i=1;i<=n;i++)
	{
		top=0;stack[top]=m+1;
		sum=0;
		for (j=m;j>=1;j--)
		{
			if (s[i][j]=='0') 
				h[j]++;
			else
				h[j]=0;

			while ((top)&&(h[j]<=h[stack[top]]))
			{
				sum=sum-h[stack[top]]*(stack[top-1]-stack[top]);
				top--;
			}
			stack[++top]=j;
			sum=sum+h[stack[top]]*(stack[top-1]-stack[top]);
			dp[i][j]=sum;
		}
	}

	for (i=0;i<=m+1;i++)
		h[i]=0;
	for (i=n;i>=1;i--)
	{
		top=0;stack[top]=0;
		sum=0;
		for (j=1;j<=m;j++)
		{
			if (s[i][j]=='0')
				h[j]++;
			else
				h[j]=0;

			while ((top)&&(h[j]<=h[stack[top]]))
			{
				sum=sum-h[stack[top]]*(stack[top]-stack[top-1]);
				top--;
			}
			stack[++top]=j;
			sum=sum+h[stack[top]]*(stack[top]-stack[top-1]);
			DP[i][j]=sum;
		}
	}

	for (i=n;i>=1;i--)
		for (j=1;j<=m;j++)
			DP[i][j]=((DP[i][j]+DP[i+1][j]+DP[i][j-1]-DP[i+1][j-1])%P+P)%P;
    
    for (i=1;i<=n;i++)
    	for (j=1;j<=m;j++)
    		ans=((ans-dp[i][j]*DP[i+1][j-1]%P)+P)%P;
    ans=(ans%P+P)%P;
    printf("%lld\n",ans);
	}
	return 0;
}
