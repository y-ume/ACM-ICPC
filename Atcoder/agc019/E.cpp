// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = (1<<15) , P = 998244353 , G = 3 , B = 2;
int w[2][N],rev[N],fac[N]={1},ifac[N];
ll Pow(ll x,ll t){ll r=1;for(;t;t>>=1,x=x*x%P)if(t&1)r=r*x%P;return r;}
void ini(){
    ll t = Pow(G,(P-1)/N);
    w[0][0] = w[1][0] = 1;
    rep(i,1,N) w[0][i] = t*w[0][i-1]%P;
    rep(i,1,N) w[1][i] = w[0][N-i];
    rep(i,0,N) for(int j=1;j<N;j*=B) (rev[i]<<=1)|=(i/j)%B;
    rep(i,1,N) fac[i]=ll(fac[i-1])*i%P;
    ifac[N-1]=Pow(fac[N-1],P-2);
    per(i,1,N) ifac[i-1]=ll(ifac[i])*i%P;
}
void ntt(int *a,int n,int o){
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
int a[N] , b[N] , c[N];
void mul(int *a,int *b,int len,int lim){
    memcpy(c,b,sizeof(*b)*len);
    ntt(a,len,0);
    ntt(c,len,0);
    rep(i,0,len) a[i]=ll(a[i])*c[i]%P;
    ntt(a,len,1);
    rep(i,lim+1,len) a[i]=0;
}

int main(){
    ini();
    string s , t;
    cin >> s >> t;
    int e = 0 , m = 0;
    rep(i,0,sz(s)) {
        e += s[i] == '1' && t[i] == '0';
        m += s[i] == '1' && t[i] == '1';
    }
    int len = 1;
    while(len <= m + m) len <<= 1;
    a[0] = 1;
    rep(i,0,m+1) b[i]=ifac[i+1];
    for(int t=e;t;t>>=1,mul(b,b,len,m)) if(t&1) mul(a,b,len,m);
    int ans=0;
    rep(i,0,m+1) (ans+=a[i])%=P;
    ans=ll(ans)*fac[e]%P*fac[m]%P*fac[e+m]%P;
    cout << ans << endl;
    return 0;
}
