#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1010;
int n,m,i,j,k,a[N][N],sa[N],sb[N],flag[N],tot,rd[N],Flag,cnt,v[N];
int ans,dp[N];
bool cmp(int a,int b)
{
    return rd[a]>rd[b];
}

struct FastIO {
    static const int S = 1310720;
    int wpos; char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while (c <= 32 && ~c) c = xchar();
        if (c == -1) return -1;
        for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char *s) {
        int c = xchar();
        while (c <= 32) c = xchar();
        for(; c > 32; c = xchar()) *s++ = c;
        *s = 0;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void wint(int x) {
        if (x < 0) wchar('-'), x = -x;

        char s[24];
        int n = 0;
        while (x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while (n--) wchar(s[n]);
    }
    inline void wstring(const char *s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;

int main()
{
    while (1)
    {
        n = io.xuint();
        m = io.xuint();
        if (n+m==0) break;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                a[i][j] = io.xuint();
        for (i=1;i<=n;i++) flag[i]=rd[i]=0;
        tot=0;
        for (i=1;i<=m;i++)
        {
            sa[i] = io.xuint();
            flag[sa[i]]=1;
        }

        for (i=1;i<=n;i++)
            if (!flag[i]) sb[++tot]=i;

        for (i=1;i<=m;i++)
            for (j=i+1;j<=m;j++)
                if (a[sa[i]][sa[j]]==1) rd[sa[i]]++;
                else rd[sa[j]]++;
        for (i=1;i<=n-m;i++)
            for (j=i+1;j<=n-m;j++)
                if (a[sb[i]][sb[j]]==1) rd[sb[i]]++;
                else rd[sb[j]]++;
        sort(sa+1,sa+1+m,cmp);
        sort(sb+1,sb+1+n-m,cmp);

        Flag=0;
        for (i=1;i<m;i++)
            if (rd[sa[i]]==rd[sa[i+1]]) Flag=1;
        for (i=1;i<n-m;i++)
            if (rd[sb[i]]==rd[sb[i+1]]) Flag=1;


        if (Flag)
        {
            printf("NO\n");
            continue;
        }
        else
        {
            printf("YES");
            cnt=0;
            for (i=1;i<=n-m;i++)
            {
                Flag=0;
                for (j=1;j<=m;j++)
                    if (a[sa[j]][sb[i]]==0) break;
                for (k=j;k<=m;k++)
                    if (a[sb[i]][sa[k]]==0) Flag=1;
                if (!Flag) v[++cnt]=j;
            }
            ans=0;
            for (i=1;i<=cnt;i++)
            {
                dp[i]=0;
                for (j=1;j<i;j++)
                    if (v[i]>=v[j])
                        dp[i]=max(dp[i],dp[j]+1);
            }
            for (i=1;i<=cnt;i++) ans=max(ans,dp[i]+1);
            printf(" %d\n",ans);
        }
    }
}
