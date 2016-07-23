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
#include <bitset>
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
const int N = 42 , P = 1e9 + 7;
int cnt[N][2] , x[N] , y[N] , fa[N] , col[N] , sz[N] , rk[N] , lim[N] , _;
int F(int x){if(x == fa[x]) return x;int pa=fa[x];fa[x]=F(fa[x]);col[x]^=col[pa];return fa[x];}
void pp(int &x,int d){x += d;if(x>=P)x-=P;}
int f[N][2] , g[N][2];

void main2(){
    int n , m;
    scanf("%d%d",&n,&m);
    rep(i,1,n+1){
        scanf("%d%d",x + i , y + i);
        cnt[i][0] = y[i]/2 - x[i]/2 + (x[i] % 2 == 0);
        cnt[i][1] = y[i] - x[i] + 1 - cnt[i][0];
    }
    rep(i,0,n+1) fa[i] = i , col[i] = sz[i] = 0;
    bool flag = true;
    rep(i,0,m){
        int l,r,x;scanf("%d%d%d",&l,&r,&x);--l;
        int a = F(l) , b = F(r);
        if(a > b) swap(a,b);
        if(a != b) fa[b] = a,col[b] = col[l]^col[r]^x;
        else flag &= x==(col[l]^col[r]);
    }
    if(!flag){
        puts("0\n-1");
        return ;
    }
    _ = 0;
    rep(i,0,n+1) sz[F(i)]++;
    rep(i,0,n+1) if(sz[i]>=2) rk[i]=_++;
    int ans = 0;vi ansv;
    rep(mask,0,1<<_){
        rep(i,0,n+1)
            if(sz[i] == 0) lim[i] = lim[fa[i]]^col[i];
            else if(sz[i] == 1) lim[i] = -1;
            else lim[i] = mask>>rk[i]&1;
        if(lim[0]==1) continue;
        rep(i,0,n) rep(j,0,2) f[i][j] = 0 , g[i][j] = -1;
        f[n][0]=f[n][1]=1;g[n][0]=g[n][1]=0;
        for(int i=n;i>=1;--i){
            if(~lim[i]) f[i][lim[i]^1]=0,g[i][lim[i]^1]=-1;
            rep(j,0,2) if(g[i][j] != -1){
                for(int k=x[i];k<=min(x[i]+1,y[i]);++k){
                    pp(f[i-1][j^(k&1)] , 1ll*f[i][j]*cnt[i][k&1]%P);
                    int &tp=g[i-1][j^(k&1)];
                    if(tp == -1 || tp > k) tp = k;
                }
            }
        }
        if(g[0][0] == -1) continue;
        pp(ans , f[0][0]);
        vi v;int c=0;
        rep(i,0,n) v.pb(g[i][c]) , c ^= g[i][c]&1;
        if(sz(ansv) == 0 || v < ansv) ansv = v;
    }
    if(sz(ansv) == 0){
        puts("0\n-1");
    } else {
        printf("%d\n",ans);
        rep(i,0,sz(ansv)) printf("%d%c",ansv[i]," \n"[i+1==sz(ansv)]);
    }
}

int main(){
    int T;scanf("%d",&T);
    rep(i,0,T) main2();
    return 0;
}

