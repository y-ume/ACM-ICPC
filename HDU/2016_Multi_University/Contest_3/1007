#include<cstdio>
#include<algorithm>
#include<vector>
#define pb push_back
using namespace std;
const int N = 101010;
vector<int> e[N];
int n,i,cnt,rt,a,b;
long long f[N][3][2],g[3][2],inf;
void dfs(int x,int fa)
{
    int i,j,k,u,v;
    for (i=0;i<=2;i++)
    for (j=0;j<=1;j++)
    f[x][i][j]=inf;
    
    if (e[x].size()==1)
    {
        f[x][1][0]=0;
        f[x][0][0]=0;
        f[x][2][1]=0;
        f[x][0][1]=0;
    }
    else
    {
        f[x][0][0]=0;
        f[x][1][1]=0;
    }
    for (i=0;i<e[x].size();i++)
    if (e[x][i]!=fa)
    {
        dfs(e[x][i],x);
        for (j=0;j<=2;j++)
        for (k=0;k<=1;k++)
        {
            g[j][k]=f[x][j][k];
            f[x][j][k]=inf;
        }
        
        for (j=0;j<=2;j++)
        for (k=1;k<=2;k++)
        for (u=0;u<=1;u++)
        for (v=0;v<=1;v++)
        if (u+v!=2)
        {
            if ((j+k==2)||(j+k==4))
            {
                f[x][0][u|v]=min(f[x][0][u|v],f[e[x][i]][k][u]+k+g[j][v]);
                f[x][2][u|v]=min(f[x][2][u|v],f[e[x][i]][k][u]+k+g[j][v]);
            }
            else
                f[x][(j+k)%2][u|v]=min(f[x][(j+k)%2][u|v],f[e[x][i]][k][u]+k+g[j][v]);
        }
    }
}
int main()
{
    inf = 0x37373737;
    inf = inf*1000;
    int test;
    scanf("%d",&test);
    while (test--)
    {
    scanf("%d",&n);
    for (i=1;i<=n;i++) e[i].clear();cnt=0;rt=0;
    for (i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        e[a].pb(b);
        e[b].pb(a);
    }
    
    if (n==1)
    {
        printf("0\n");
        continue;
    }
    if (n==2) 
    {
        printf("1\n");
        continue;
    }

    
    for (i=1;i<=n;i++)
    if (e[i].size()==1) cnt++;
    else rt=i;
    dfs(rt,0);
    

    if (cnt%2==0)
    printf("%I64d\n",f[rt][0][0]);
    else
    printf("%I64d\n",f[rt][0][1]);
    }
}
