#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
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

const int N = 101010;
int n , col[N] , sum[N];
vector<pii> g[N];vi order[N];

struct LCARMQ{
    static const int N = 101010 << 1; // N is 2 size of tree , id of nodes start from 0
    int a[20][N] , lft[N] , dep[N] , lg[N] , L;
    int rmin(int x,int y){return dep[x] < dep[y] ? x : y;}
    void add(int x){ a[0][L++] = x;}
    void dfs(int c,int fa,const vector<pii> g[]){
        lft[c]=L;add(c);
        order[col[c]].pb(c);
        rep(i,0,sz(g[c])){
            int t = g[c][i].fi;
            if(t != fa) dep[t] = dep[c] + 1 , dfs(t , c , g) , add(c);
        }
    }
    void Build(const vector<pii> g[]){
        L = 0;dfs(0,-1,g);
        rep(i,2,L) lg[i]=lg[i-1]+(i==(i&-i));
        rep(i,1,20){
            int lim = L+1-(1<<i);
            rep(j,0,lim) a[i][j] = rmin(a[i-1][j] , a[i-1][j+(1<<i>>1)]);
        }
    }
    int lca(int x,int y){
        x = lft[x] , y = lft[y];
        if(x > y) swap(x , y);
        int i = lg[y-x+1];
        return rmin(a[i][x] , a[i][y+1-(1<<i)]);
    }
}lca;

namespace Vtree{// some nodes remain
    const int N = 101010;
    int tp[N] , _;
    vi g[N];// nodes sorted in dfs order
    void solve(vi&v,LCARMQ&R){
        _ = 0;
        vi del;del.pb(tp[_++] = v[0]);
        rep(i,1,sz(v)){
            int lca = R.lca(tp[_-1] , v[i]);
            vi l;while(_ > 0 && R.dep[lca] < R.dep[tp[_-1]]) l.pb(tp[--_]);
            if(_ == 0 || lca != tp[_-1]) del.pb(tp[_++] = lca);
            l.pb(tp[_-1]);del.pb(tp[_++] = v[i]);
            rep(i,1,sz(l)) g[l[i]].pb(l[i-1]);
        }
        rep(i,0,_-1) g[tp[i]].pb(tp[i+1]);
        rep(i,0,sz(del)){
            int t = del[i];
            sum[t] -= sz(g[t]);
            rep(i,0,sz(g[t])) sum[g[t][i]]++;
            g[t].clear();
        }
    }
}
int ans[N] , tmp[N];
void dfs(int c,int fa){
    tmp[c] = sum[c];
    rep(i,0,sz(g[c])){
        int t = g[c][i].fi;
        if(t != fa){
            dfs(t , c);
            ans[g[c][i].se] = tmp[t];
            tmp[c] += tmp[t];
        }
    }
}

int main(){
    while(~scanf("%d",&n)){
        rep(i,0,n) scanf("%d",col + i);
        rep(i,0,n) g[i].clear();
        rep(i,1,n+1) order[i].clear();
        rep(i,1,n){
            int u , v;scanf("%d%d",&u,&v);
            --u;--v;
            g[u].pb(mp(v,i));g[v].pb(mp(u,i));
        }
        lca.Build(g);
        rep(i,0,n) sum[i] = 0;
        rep(i,1,n+1) if(sz(order[i])) Vtree::solve(order[i] , lca);
        dfs(0,-1);
        rep(i,1,n) printf("%d\n",ans[i]);
    }
    return 0;
}
