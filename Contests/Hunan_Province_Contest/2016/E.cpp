#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 501010;
int n,i,a[N],ans[N],flag;
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);

	for (i=1;i<=n;i++)
	if (a[i])
	if (abs(a[i]-i)>1)
	break;

	int tmp=i;
	if (tmp<=n)
	{
		for (i=1;i<=min(a[tmp],tmp)-1;i++)
			ans[i]=i;
		for (i=max(a[tmp],tmp)+1;i<=n;i++)
			ans[i]=i;
		if (a[tmp]>tmp)
		{
			ans[tmp]=a[tmp];
			for (i=tmp+1;i<=a[tmp];i++)
				ans[i]=i-1;
		}
		else
		{
			ans[tmp]=a[tmp];
			for (i=a[tmp];i<tmp;i++)
				ans[i]=i+1;
		}

		flag=0;
		for (i=1;i<=n;i++)
		if ((a[i])&&(ans[i]!=a[i]))
			flag=1;
		if (flag)
			printf("0\n");
			else
			printf("1\n");
			continue;
	}

	for (i=1;i<n;i++)
		if (a[i]&&(a[i+1]))
			if ((a[i]==i+1)&&(a[i+1]==i)) break;
	tmp=i;
	if (tmp<n)
	{
		for (i=1;i<tmp;i++) ans[i]=i;
		ans[tmp]=tmp+1;ans[tmp+1]=tmp;
		for (i=tmp+2;i<=n;i++) ans[i]=i;

		flag=0;
		for (i=1;i<=n;i++)
		if ((a[i])&&(ans[i]!=a[i]))
			flag=1;

		if (flag)
			printf("0\n");
			else
				printf("1\n");
				continue;
	}

	int cnt1=0,cnt2=0;
	long long Ans=0;
	for (i=1;i<=n;i++)
		if (a[i])
		{
			cnt1++;
			if (a[i]==i)
				cnt2++;
		}
	if (cnt1==cnt2)
	{
		tmp=0;
		int len;
		for (i=1;i<=n;i++)
		if (a[i])
		{
			len=i-tmp-1;
			if (len>=2)
				Ans=Ans+len-1;
			if (len>=3)
				Ans=Ans+1LL*(1+len-2)*(len-2);
			tmp=i;
		}

		len=n+1-tmp-1;
		if (len>=2) Ans=Ans+len-1;
		if (len>=3) Ans=Ans+1LL*(1+len-2)*(len-2);
		printf("%lld\n",Ans);
		continue;
	}
	
	
	cnt1=cnt2=tmp=0;
	int t1,t2;
	for (i=1;i<=n;i++)
	if (a[i])
	{
		if (a[i]!=i) break;
		tmp=i;
	}

	t1=i;
	cnt1=i-tmp-1;
	
	tmp=n+1;
	for (i=n;i>=1;i--)
	if (a[i])
	{
		if (a[i]!=i) break;
		tmp=i;
	}
	t2=i;
	cnt2=tmp-i-1;
	for (i=t1;i<=t2;i++)
		if (a[i])
		{
			if (a[t1]-t1!=a[i]-i)
				break;
		}

	if (i<=t2)
		printf("0\n");
	else
	{
		if (a[t1]>t1)
		printf("%lld\n",1LL*(cnt1+1)*cnt2);
		else
		printf("%lld\n",1LL*cnt1*(cnt2+1));
	}
	}
}
