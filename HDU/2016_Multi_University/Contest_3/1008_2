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
#include <cassert>
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
const int N = 300005 , inf = 1<<30;
typedef unsigned int ui;

struct SegmentTree{
#define id(l,r) (l+r)|(l!=r)
#define pr int c=id(l,r),m=(l+r)>>1
    ui add[N<<1] , k[N];
    void ini(int n,ui *K){
        fill_n(add,n+n,0);
        copy_n(K,n,k);
    }
    void Add(int l,int r,int L,int R,ui d){ pr;
        if(L<=l&&r<=R) add[c]+=d;
        else{
            if(L<=m) Add(l,m,L,R,d);
            if(R>m) Add(m+1,r,L,R,d);
        }
    }
    ui Query(int l,int r,int x,ui Add){ pr;
        if(l == r) return (Add+add[c])*k[l];
        return x <= m ? Query(l,m,x,Add+add[c]) : Query(m+1,r,x,Add+add[c]);
    }
}tree[2];
template<class T>
struct Fenwick{ // [1,n] , init!!
#define lb(x) ((x)&-(x))
    static const int N = 300001;
    int n;T a[N];
    void ini(int _n){ n=_n;fill(a+1,a+1+n,0);}
    void Pre(){ for(int i=1,j=i+lb(i);i<=n;++i,j=i+lb(i)) if(j<=n) a[j]+=a[i];}
    void add(int x,T d){ for(;x<=n;x+=lb(x)) a[x]+=d;}
    T sum(int x){ T r=0;for(;x>=1;x^=lb(x)) r+=a[x];return r;}
};Fenwick<ui> F;
pii seg[N][3];
ui w[N] , sumw[N] , f[N] , a[N] , K[N][4] ,sz[N][4];
vi g[N];
int n , Q , q[N] , par[N] , bfs[N] , dfs[N] , wson[N] , top[N];
void Update(pii&a,pii b){
    a.fi = min(a.fi , b.fi);
    a.se = max(a.se , b.se);
}
void Pre(){
    int _ = 0;q[_++] = 0;
    rep(i,0,_){
        int c = q[i];
        bfs[c] = i;
        wson[c] = top[c] = -1;
        f[c] = sumw[c] = w[c];
        fill_n(sz[c],4,1);
        fill_n(K[c],4,0);
        fill_n(seg[c],3,mp(inf,-inf));
        seg[c][0] = mp(i,i);
        for(auto t : g[c]) q[_++] = t;
    }
    for(int i=_-1;i>=0;--i){
        int c = q[i];
        if(i){
            int t = par[c];
            sumw[t] += sumw[c];
            rep(j,0,2) sz[t][j+1] += sz[c][j];
            sz[t][3] += sz[c][3];
            rep(j,0,2) Update(seg[t][j+1] , seg[c][j]);
            f[t] -= sz[c][3] * sumw[c];
            rep(j,1,3) K[t][j] -= sz[c][j-1] * sz[c][3];
            if(wson[t] == -1 || sz[c][3] > sz[wson[t]][3]) wson[t] = c;
        }
        f[c] += sz[c][3] * sumw[c];
        rep(i,0,3) K[c][i] += 1 + sz[c][i] * sz[c][3];
    }
    _ = 0;q[_++] = 0;dfs[0] = 0;
    rep(i,0,_){
        int c = q[i] , cur = dfs[c];
        if(top[c] == -1) top[c] = c;
        seg[c][0] = mp(dfs[c] , dfs[c] + sz[c][3] - 1);
        int t = wson[c];if(~t) q[_++] = t , dfs[t] = cur + 1 ,
            cur += sz[t][3] , top[t] = top[c] , K[t][3] = sz[c][3] - sz[t][3];
        for(auto t : g[c]) if(t != wson[c])
            q[_++] = t , dfs[t] = cur + 1 , cur += sz[t][3];
    }
    rep(j,0,2){
        rep(i,0,n) a[bfs[i]] = K[i][1-j];
        tree[j].ini(n,a);
    }
    F.ini(n);
}

void Modify(int x,ui d){
    rep(i,0,2) if(seg[x][i+1].fi <= seg[x][i+1].se) tree[i].Add(0,n-1,seg[x][i+1].fi,seg[x][i+1].se,d);
    f[x] += d * K[x][2];
    ui dd = d * sz[x][2];
    F.add(seg[x][0].fi,dd);
    while(x){
        int y = top[x];
        x = par[y];if(y) f[x] += dd * (sz[x][3] - sz[y][3]);
    }
}
ui Query(int x){
    return f[x] + tree[0].Query(0,n-1,bfs[x] , 0) + tree[1].Query(0,n-1,bfs[x] , 0) +
        (~wson[x] ? (F.sum(seg[wson[x]][0].se) - F.sum(seg[wson[x]][0].fi-1)) * K[wson[x]][3]: 0);
}

int main(){
    while(~scanf("%d%d",&n,&Q)){
        rep(i,0,n) g[i].clear();
        int x;rep(i,1,n) scanf("%d",&x) , g[x-1].pb(i) , par[i] = x-1;
        rep(i,0,n) scanf("%u",w + i);
        Pre();
        rep(i,0,Q){
            int op,u;ui x;scanf("%d%d",&op,&u);--u;
            if(op == 1) scanf("%u",&x), Modify(u,x);
            else printf("%u\n",Query(u));
        }
    }
    return 0;
}
