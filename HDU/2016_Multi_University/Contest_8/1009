#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <complex>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define per(i,a,b) for(int i=b-1;i>=a;--i)
#define set(a,b) memset(a,b,sizeof(a))
#define de(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef complex<double> vir;
const double pi = acos(-1.0), eps = 1e-15;
const int inf = ~0U >> 2;
const int mod = 998244353;
const ll linf = 1ll * inf * inf;
ll Pow(ll x, ll t){ll r=1;for(;t;t>>=1,x=x*x%mod)if(t&1)r=r*x%mod;return r;}
const int N = (1<<19) , P = 998244353, G = 3 , B = 2;
int T,n;
int w[2][N] , rev[N];

int quick_mod(int x, int k, int MOD) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
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

void ini(){
    ll t = Pow(G,(P-1)/N);
    w[0][0] = w[1][0] = 1;
    rep(i,1,N) w[0][i] = t*w[0][i-1]%P;
    rep(i,1,N) w[1][i] = w[0][N-i];
    rep(i,0,N) for(int j=1;j<N;j*=B) (rev[i]<<=1)|=(i/j)%B;
}
void NTT(int *a,int n,int o){
    int tt = N/n;
    rep(i,0,n){
        int j = rev[i]/tt;
        if(i<j) swap(a[i],a[j]);
    }
    for(int i=1;i<n;i<<=1)
    for(int j=0,t=N/(i+i);j<n;j+=i+i)
    for(int k=j,l=0;k<j+i;++k,l+=t){
        int b = (ll)a[k+i]*w[o][l]%P;
        a[k+i] = a[k]-b; if(a[k+i]<0) a[k+i]+=P;
        a[k] = a[k]+b; if(a[k]>=P) a[k]-=P;
    }
    if(o == 1){
        ll inv = Pow(n,P-2);
        rep(i,0,n) a[i] = a[i]*inv%P;
    }
}

void mult(int *a,int *b,int len){
    NTT(a,len,0);NTT(b,len,0);
    rep(i,0,len) a[i] = (ll)a[i]*b[i]%P;
    NTT(a,len,1);
}

int a[N];
int mi[N], f[N], rf[N];
int x1[N], x2[N];

int main() {
    ini();
    mi[0] = f[0] = 1;
    for (int i = 1; i < N; i++) {
        mi[i] = mi[i - 1] * 2 % P;
        f[i] = 1LL * f[i - 1] * i % P;
    }
    rf[N - 1] = quick_mod(f[N - 1], P - 2, P);
    for (int i = N - 2; i >= 0; i--) rf[i] = 1LL * rf[i + 1] * (i + 1) % P;
    T = io.xuint();
    while (T--) {
        n = io.xuint();
        for (int i = 1; i <= n; i++) a[i] = io.xuint();
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) a[i] %= P;
        int len = 1;
        while (len < (n + 1) * 2) len <<= 1;
        memset(x1, 0, sizeof(int) * len);
        memset(x2, 0, sizeof(int) * len);
        for (int i = 1; i <= n; i++) {
            x1[i] = 1LL * mi[i - 1] * a[i] % P * f[n - i] % P;
            x2[i] = rf[i];
        }
        x2[0] = rf[0];
        mult(x1, x2, len);
        int sum = 0;
        for (int i = n; i >= 1; i--) {
            sum += 1LL * x1[i] * rf[n - i] % P;
            if (sum >= P) sum -= P;
            io.wint(sum);
            io.wchar(i == 1 ? ' ' : ' ');
        }
        io.wchar('\n');
    }
    return 0;
}
