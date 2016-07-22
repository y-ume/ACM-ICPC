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
const int N = 202020;
namespace BCC{
    const int N = 202020;
    vi key , bcc[N];
    int dfn[N] , low[N] , st[N] , _st , _;
    void dfs(int c,int dep,const vi g[]){
        int cc=0,out=1<dep;st[_st++]=c;
        dfn[c]=low[c]=dep;
        for(auto t:g[c])
            if(!dfn[t]){
                dfs(t,dep+1,g);
                low[c]=min(low[c],low[t]);
                if(low[t]>=dfn[c]){
                    if(++out==2) key.pb(c);
                    while(st[--_st]!=t) bcc[st[_st]].pb(_);
                    bcc[c].pb(_);bcc[t].pb(_++);
                }
            } else if(dfn[t] != dfn[c] - 1 || cc++)
                low[c] = min(low[c] , dfn[t]);
    }
    int solve(int n,const vi g[]){
        fill_n(dfn,n,_=0);
        fill_n(low,n,_st=0);
        fill_n(bcc,n,key=vi());
        rep(i,0,n) if(!dfn[i]) dfs(i,1,g);
        return _;
    }
}
const int P = 1e9 + 7;
void pp(int &x,int d){x += d;if(x >= P) x -= P;}
int Pow(int x,int t){int r=1;for(;t;t>>=1,x=1ll*x*x%P)if(t&1)r=1ll*r*x%P;return r;}
int n , m;
int w[N] , vis[N] , ans[N] , f[N] , sum[N] , par[N];
vi g[N];

void main2(){
    scanf("%d%d",&n,&m);
    rep(i,0,n) scanf("%d",w + i);
    rep(i,0,n) g[i].clear();
    rep(i,0,m){
        int u,v;scanf("%d%d",&u,&v);--u;--v;
        g[u].pb(v);g[v].pb(u);
    }
    BCC::solve(n,g);
    rep(i,0,BCC::_+n){
        if(i >= n) w[i] = 1;
        g[i].clear();
        vis[i] = 0;
    }
    rep(i,0,n) for(auto t : BCC::bcc[i])
        g[i].pb(t+n) , g[t+n].pb(i);
    int all = 0;
    rep(i,0,n) if(!vis[i]){
        vi v;v.pb(i);par[i] = -1;
        rep(i,0,sz(v)){
            int c = v[i];f[c] = w[c] , sum[c] = 0 , vis[c] = 1;
            for(auto t : g[c]) if(t != par[c]) v.pb(t) , par[t] = c;
        }
        for(int i=sz(v)-1;i>=0;--i){
            int c = v[i];
            if(i) pp(sum[par[c]],f[c]) , f[par[c]]=1ll*f[par[c]]*f[c]%P;
        }
        pp(all,f[v[0]]);
        rep(i,0,sz(v)){
            int c = v[i];
            ans[c] = (P-f[v[0]]+sum[c]+(i?(ll)Pow(f[c],P-2)*f[v[0]]%P:0))%P;
        }
    }
    int a=0;
    rep(i,0,n) pp(ans[i],all) , pp(a,1ll*ans[i]*(i+1)%P);
    printf("%d\n",a);
}

int main(){
    int T;scanf("%d",&T);
    rep(i,0,T) main2();
    return 0;
}

