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
typedef long double db;
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
typedef complex<db> vir;
const db pi = acos(-1.0);
void fft(vir *F,int len,int o){
    int j = 0 , k , h;
    rep(i,0,len-1){
        if(i < j) swap(F[i] , F[j]);
        for(k=len;j>=(k>>=1);j&=~k); j|=k;
    }
    for(h=1;h<len;h<<=1){
        vir wn(cos(pi*o/h),sin(pi*o/h));
        for(j=0;j<len;j+=h<<1){
            vir w(1.);
            for(k=j;k<j+h;++k,w=w*wn){
                vir b = w*F[k+h];
                F[k+h] = F[k]-b , F[k] = F[k]+b;
            }
        }
    }
    if(o == -1) rep(i,0,len) F[i] = F[i]/(db)len;
}
void mul(vir *a,vir *b,int len){
    fft(a,len,1);fft(b,len,1);
    rep(i,0,len) a[i] = a[i] * b[i];
    fft(a,len,-1);
}
const int N = 101010 , P = 313;
int n;
int a[N];
int getlen(int n){
    int r=1;
    while(r<=n) r*=2;
    return r;
}
vir f[N<<2] , g[N<<2];
int dp[N];
void pp(int &x,int d){
    x += d;if(x >= P) x -= P;
}
void solve(int l,int r){
    if(l == r) return ;
    int mid = (l+r)>>1;
    solve(l,mid);
    int len = getlen(r-l+1);
    rep(i,0,len){
        f[i] = l + i <= mid ? dp[l+i] : 0;
        g[i] = l + i <= r ? a[i] : 0;
    }
    //cout << l << " " << r << endl;
    //rep(i,0,len) cout << f[i] << " \n"[i + 1== len];
    //rep(i,0,len) cout << g[i] << " \n"[i + 1== len];
    mul(f , g , len);
    //rep(i,0,len) cout << f[i] << " \n"[i + 1== len];
    for(int i=mid+1;i<=r;++i) pp(dp[i] , (ll)(f[i-l].real() + 0.5) % P);
    solve(mid+1,r);
}


int main(){
    while(~scanf("%d",&n)){
        if(n == 0) break;
        dp[0] = 1;
        rep(i,1,n+1) scanf("%d",a + i) , a[i]%=P , dp[i] = 0;
        solve(0,n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
