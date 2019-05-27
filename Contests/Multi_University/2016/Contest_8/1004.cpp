#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = (1<<16) , P = 998244353, G = 3 , B = 2;
ll Pow(ll x, ll t){ll r=1;for(;t;t>>=1,x=x*x%P)if(t&1)r=r*x%P;return r;}

namespace NTT {
    int w[2][N] , rev[N];
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
}
int way[21][N] , a[N] , b[N] , f[N] , rf[N];
int S[21][21] , pp2[N];
int C(int A,int B){
    if(A<B) return 0;
    return 1ll*f[A]*rf[B]%P*rf[A-B]%P;
}
void pp(int &x,int d){
    x += d;if(x>=P) x-=P;
}

int main(){
    NTT::ini();
    f[0]=1;rep(i,1,N) f[i]=1ll*f[i-1]*i%P;
    rf[N-1]=Pow(f[N-1],P-2);
    for(int i=N-2;i>=0;--i) rf[i]=1ll*rf[i+1]*(i+1)%P;
    int n = 10001 , m = 21;
    rep(i,0,n) pp2[i] = Pow(2,i*(i-1)/2);
    int len=1;while((1<<len)<(n+n)) len++;
    len = 1<<len;
    a[1] = 1;rep(i,2,n) a[i] = Pow(i,i-2);
    copy_n(a,N,way[1]);
    rep(i,1,n) a[i]=1ll*a[i]*rf[i-1]%P;
    NTT::NTT(a,len,0);
    rep(i,2,m){
        copy_n(way[i-1],N,b);
        rep(i,0,n) b[i]=1ll*b[i]*rf[i]%P;
        NTT::NTT(b,len,0);
        rep(i,0,len) b[i]=1ll*b[i]*a[i]%P;
        NTT::NTT(b,len,1);
        rep(j,1,n) way[i][j] = 1ll*b[j]*f[j-1]%P;
    }
    S[0][0]=1;rep(i,1,m) rep(j,1,i+1) S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%P;
    int T;scanf("%d",&T);
    rep(i,0,T){
        scanf("%d%d",&n,&m);int ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                pp(ans , 1ll*S[m][j]*f[j]%P*way[j][i]%P*C(n,i)%P*pp2[n-i]%P);
        printf("%d\n",ans);
    }
    return 0;
}
