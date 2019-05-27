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
#define pb emplace_back
#define fi first
#define se second
const int N = 505;
int n , m , T;
char s[N];

template<class T>
struct KM {
    static const int N = 505;
    static const T inf = ~0U>>2;
    int n, m, left[N], pre[N], used[N];
    T g[N][N], Lx[N], Ly[N], slack[N];
    void ini(int _n, int _m) {
        n = _n , m = _m;
        rep(i,0,n) rep(j,0,m) g[i][j] = -inf;
    }
    void go(int now) {
        rep(i,0,m+1) used[i]=0,slack[i]=inf;
        left[m] = now;int u,v;
        for(u=m;~left[u];u=v){
            used[u] = 1;
            T d = inf;
            rep(i,0,m) if(!used[i]){
                T tmp = Lx[left[u]] + Ly[i] - g[left[u]][i];
                if(tmp < slack[i]) slack[i] = tmp, pre[i] = u;
                if(slack[i] < d) d = slack[v=i];
            }
            rep(i,0,m+1) if(used[i]) Lx[left[i]] -= d , Ly[i] += d;
                else slack[i] -= d;
        }
        for(;u!=m;left[u]=left[pre[u]],u=pre[u]);
    }
    T run() {
        fill_n(Lx,n,0);fill_n(Ly,m,0);
        fill_n(left,m,-1);
        rep(i,0,n) go(i);
        T ans = 0;
        rep(i,0,n) ans += Lx[i];
        rep(i,0,m) ans += Ly[i];
        return -ans;
    }
};
int TT;
KM<int> km;
vi g[N];int used[N] , col[N] , dis[N][N] , pre[N][N] , d[N] , p[N];
vector<pii> ans;
pair<bool,vector<pii> > solve(vi&W,vi&B,int cntW,int cntB){
    if(sz(W) != cntW || sz(B) != cntB) return mp(false,vector<pii>());
    vi L,R;
    for(int c:W) if(s[c]!='0') L.pb(c);
    for(int c:B) if(s[c]!='1') R.pb(c);
    km.ini(sz(L),sz(L));
    rep(i,0,sz(L)) rep(j,0,sz(R)) km.g[i][j]=-dis[L[i]][R[j]];
    km.run();
    vector<pii> tmp;
    rep(j,0,sz(R)){
        int u = R[j] , v = L[km.left[j]];
        for(int c=v,t;c!=u;c=pre[u][c]){
            vi l;t=c;while(s[pre[u][c]]==s[c]) l.pb(c),c=pre[u][c];
            l.pb(c);l.pb(pre[u][c]);
            for(int i=sz(l)-1;i>=1;--i) tmp.pb(l[i-1]+1,l[i]+1);
            swap(s[pre[u][c]],s[t]);
        }
    }
    rep(j,0,sz(R)) swap(s[R[j]],s[L[km.left[j]]]);
    return mp(true,tmp);
}
bool ok(int c){
    vi v;v.pb(c);col[c] = 0;used[c] = true;
    vi a[2];int cnt[2] = {0};
    rep(i,0,sz(v)){
        int c = v[i];a[col[c]].pb(c);cnt[s[c]-'0']++;
        for(int t : g[c]) if(!used[t]) used[t] = true , col[t] = col[c]^1 , v.pb(t);
            else if(col[t]==col[c]) return false;
    }
    bool ok = false;vector<pii> tmp;
    rep(i,0,2){
        auto e = solve(a[i],a[i^1],cnt[0],cnt[1]);
        if(e.fi){
            if(!ok) ok = true , tmp = e.se;
            else if(sz(tmp) > sz(e.se)) tmp = e.se;
        }
    }
    if(ok) ans.insert(ans.end(),all(tmp));
    return ok;
}
void getdis(int c){
    vi v;fill_n(d,n,~0U>>1);fill_n(p,n,-1);
    v.pb(c);d[c]=0;p[c]=-1;
    rep(i,0,sz(v)){
        int c = v[i];
        for(int t : g[c]) if(d[t] == ~0U>>1) d[t]=d[c]+1, p[t]=c, v.pb(t);
    }
    copy(d,d+n,dis[c]);
    copy(p,p+n,pre[c]);
}
int main2(){
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    fill_n(g,n,vi());
    rep(i,0,m){
        int u,v;scanf("%d%d",&u,&v);--u;--v;
        g[u].pb(v);g[v].pb(u);
    }
    fill_n(used,n,0);
    rep(i,0,n) getdis(i);
    ans.clear();
    rep(i,0,n) if(!used[i] && !ok(i)) return puts("-1") , 0;
    printf("%d\n",sz(ans));
    rep(i,0,sz(ans)) printf("%d %d\n",ans[i].fi,ans[i].se);
    return 1;
}

int main(){
    scanf("%d",&T);rep(i,0,T) main2();
    return 0;
}
