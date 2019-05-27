#include<bits/stdc++.h>
using namespace std;
const int N = 2010100;
int test,i,j,m,a;
int sg[N],flag[N],n,tot,v[N],ans,tmp;
void check(int x)
{
    int i,j;
    for (i=0;i<20;i++)
    if ((x|(1<<i))==x)
    for (j=i-1;j>=0;j--)
    if ((x|(1<<j))!=x)
    {
        tot++;
        v[tot]=sg[x-(1<<i)+(1<<j)];
        break;
    }
}
int main()
{
    int test,ii;
    scanf("%d",&test);
    for (i=1;i<=(1<<20)-1;i++)
    {
        tot=0;
        check(i);
    
        for (j=1;j<=tot;j++)
            flag[v[j]]=1;
        for (j=0;;j++)
        if (flag[j]==0) 
        {
        
            sg[i]=j;
            
            break;
        }
        for (j=1;j<=tot;j++)
            flag[v[j]]=0;
    }
    
    for (ii=1;ii<=test;ii++)
    {
        scanf("%d",&n);
        ans=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&m);
            tmp=0;
            for (j=1;j<=m;j++)
            {
                scanf("%d",&a);
                tmp=(tmp|(1<<(20-a)));
            }
            //printf("%d %d\n",tmp,sg[tmp]);
            ans^=sg[tmp];
        }
        if (ans==0)
        printf("NO\n");
        else
        printf("YES\n");
    }
    
}
