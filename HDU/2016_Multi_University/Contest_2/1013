#include<cstdio>
#include<algorithm>
#include<vector>
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 2010;
int n,m,k,i,j,a[N],b[N],p[N];
int sum[N][N],ans;
pair<int,int> P[10];
vector<int> vec[N];
vector<int>::iterator it;
int pd(int x,int y,int z)
{
	int maxx=max(a[x],a[y]);
	int minx=min(a[x],a[y]);
	int maxy=max(b[x],b[y]);
	int miny=min(b[x],b[y]);
	if (sum[maxx][maxy]-sum[minx-1][maxy]-sum[maxx][miny-1]+sum[minx-1][miny-1]-2==z)
	if (sum[maxx-1][maxy-1]-sum[minx][maxy-1]-sum[maxx-1][miny]+sum[minx][miny]==z)
	return 0;
	return 1;
}
pair<int,int> gao(int l,int r,int x,int d)
{
	int left,right,mid;
	if (d==1)
	{
		left=x;right=m;
		while (left<=right)
		{
			mid=(left+right)>>1;
			if (sum[r][mid]-sum[l-1][mid]-sum[r][x-1]+sum[l-1][x-1])
			right=mid-1;else left=mid+1;
		}
		if (left>m) return mp(0,0);
		if (sum[r][left]-sum[l-1][left]-sum[r][x-1]+sum[l-1][x-1]!=1) return mp(0,0);
		x=left;
	}
	else
	{
		left=1;right=x;
		while (left<=right)
		{
			mid=(left+right)>>1;
			if (sum[r][x]-sum[l-1][x]-sum[r][mid-1]+sum[l-1][mid-1])
			left=mid+1;else right=mid-1;
		}
		if (right==0) return mp(0,0);
		if (sum[r][x]-sum[l-1][x]-sum[r][right-1]+sum[l-1][right-1]!=1) return mp(0,0);
		x=right;
	}
	it=lower_bound(vec[x].begin(),vec[x].end(),l);
	return mp(*it,x);
}
int solve(int x,int y)
{
	P[1].fi=a[x];P[1].sc=b[x];P[2].fi=a[y];P[2].sc=b[y];
	if (abs(b[x]-b[y])<abs(p[1]-p[4])) return 0;
	if ((b[x]<b[y])&&(p[1]>p[4])) return 0;
	if ((b[x]>b[y])&&(p[1]<p[4])) return 0;
	
	if (abs(p[4]-p[1])==3) 
	{
		if (pd(x,y,2)) return 0;
		P[3]=gao(a[x],a[y],min(b[x],b[y])+1,1);if (P[3].fi==0) return 0;
		P[4]=gao(a[x],a[y],max(b[x],b[y])-1,0);if (P[4].fi==0) return 0;
	}
	else
	if (abs(p[4]-p[1])==2)
	{
		if (pd(x,y,1)) return 0;
		P[3]=gao(a[x],a[y],min(b[x],b[y])+1,1);if (P[3].fi==0) return 0;
		if (max(p[1],p[4])==3) P[4]=gao(a[x],a[y],max(b[x],b[y])+1,1);
		else P[4]=gao(a[x],a[y],min(b[x],b[y])-1,0);if (P[4].fi==0) return 0;	
	}
	else
	{
		if (pd(x,y,0)) return 0;
		if (max(p[1],p[4])==2)
		{
			P[3]=gao(a[x],a[y],max(b[x],b[y])+1,1);if (P[3].fi==0) return 0;
			P[4]=gao(a[x],a[y],P[3].sc+1,1);if (P[4].fi==0) return 0;
		}
		else
		if (max(p[1],p[4])==4)
		{
			P[3]=gao(a[x],a[y],min(b[x],b[y])-1,0);if (P[3].fi==0) return 0;
			P[4]=gao(a[x],a[y],P[3].sc-1,0);if (P[4].fi==0) return 0;
		}
		else
		{
			P[3]=gao(a[x],a[y],min(b[x],b[y])-1,0);if (P[3].fi==0) return 0;
			P[4]=gao(a[x],a[y],max(b[x],b[y])+1,1);if (P[4].fi==0) return 0;
		}
	}
	//printf("%d %d\n",x,y);
	sort(P+1,P+5);
	int i,j;
	for (i=1;i<=4;i++)
	for (j=1;j<=4;j++)
	if (i!=j) 
	{	
		if (P[i].fi==P[j].fi) return 0;
		if (P[i].sc==P[j].sc) return 0;
	}
	for (i=1;i<=4;i++)
	for (j=1;j<=4;j++)
	if (i!=j)
	if ((P[i].sc-P[j].sc)*(p[i]-p[j])>0) continue;else return 0;
	return 1;
}
int main()
{
	int test;
	scanf("%d",&test);
	while (test--)
	{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d%d",&p[1],&p[2],&p[3],&p[4]);
	for (i=1;i<=m;i++) vec[i].clear();
	for (i=0;i<=n+1;i++)for (j=0;j<=m+1;j++) sum[i][j]=0;
	for (i=1;i<=k;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sum[a[i]][b[i]]=1;
		vec[b[i]].pb(a[i]);
	}
	for (i=1;i<=m;i++)
	sort(vec[i].begin(),vec[i].end());
	
	for (i=1;i<=n;i++)
	{
	for (j=1;j<=m;j++)
		sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	
	ans=0;
	for (i=1;i<=k;i++)
	for (j=1;j<=k;j++)
	if ((a[i]+3<=a[j])&&(b[i]!=b[j]))
	ans+=solve(i,j);
	printf("%d\n",ans);
	}
}
