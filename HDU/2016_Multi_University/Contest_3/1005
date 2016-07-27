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
const int N = 50005;
int n , Q;
vi g[N];
int lft[N] , rgt[N] , dep[N] , _;
int rt[N] , go[N];
void dfs(int c,int fa){
    lft[c] = _++;
    go[_-1] = c;
    for(auto t : g[c]) if(t != fa) dep[t] = dep[c] + 1 , dfs(t , c);
    rgt[c] = _-1;
}
const int M = 5000000, inf = ~0U>>1;
struct Node{
    int Max , Min , Add , Sum , ls,rs;
}pl[M];
void Update(Node&t,Node a,Node&b,int len){
    t.Min = min(a.Min , b.Min) + t.Add;
    t.Max = max(a.Max , b.Max) + t.Add;
    t.Sum = a.Sum + b.Sum + 1ll * t.Add * len;
}
void Build(int&c,int l,int r){
    pl[++_] = pl[c];
    Node&t=pl[c = _];
    if(l == r){
        t.Min = t.Max = t.Sum = dep[go[l]];
    } else{
        int m=(l+r)>>1;
        Build(t.ls,l,m);Build(t.rs,m+1,r);
        Update(t,pl[t.ls],pl[t.rs],r-l+1);
    }
}
void Add(int &c,int l,int r,int L,int R,int d){
    pl[++_] = pl[c];
    Node&t=pl[c = _];
    if(L <= l && r <= R){
        t.Add += d;t.Max += d;
        t.Min += d;t.Sum += d*(r-l+1);
    } else {
        int m=(l+r)>>1;
        if(L <= m) Add(t.ls,l,m,L,R,d);
        if(R > m) Add(t.rs,m+1,r,L,R,d);
        Update(t,pl[t.ls],pl[t.rs],r-l+1);
    }
}
void Buildtrees(int c,int fa){
    for(auto t : g[c]) if(t != fa){
        rt[t] = rt[c];
        Add(rt[t],0,n-1,lft[t],rgt[t],-2);
        Add(rt[t],0,n-1,0,n-1,1);
        Buildtrees(t , c);
    }
}
Node tmp;
void Query(int c,int l,int r,int L,int R,int add){
    Node t=pl[c];
    if(L<=l && r<=R){
        t.Max += add , t.Min += add , t.Sum += add * (r-l+1);
        Update(tmp , tmp , t , 0);
    } else {
        int m=(l+r)>>1;
        if(L<=m) Query(t.ls,l,m,L,R,add+t.Add);
        if(R>m) Query(t.rs,m+1,r,L,R,add+t.Add);
    }
}
int K , P , type , ans;
int main(){
    pl[0].Max = -inf , pl[0].Min = inf;
    while(~scanf("%d%d",&n,&Q)){
        rep(i,0,n) g[i].clear();
        rep(i,1,n){
            int u , v;scanf("%d%d",&u,&v);--u;--v;
            g[u].pb(v);
            g[v].pb(u);
        }
        _ = 0;dfs(0,-1);
        _ = 0;Build(rt[0]=0,0,n-1);
        Buildtrees(0,-1);
        ans = 0;
        rep(i,0,Q){
            scanf("%d%d%d",&K,&P,&type);
            P = (P+ans)%n;
            vector<pii> v , v2;
            rep(i,0,K){
                int x;scanf("%d",&x);--x;
                v.pb(mp(lft[x] , rgt[x]));
            }
            sort(all(v));
            v2.pb(mp(-1,-1));
            for(int i=0,j,R;i<sz(v);i=j){
                for(R=v[i].se,j=i;j<sz(v)&&v[j].fi<=R;R=max(R,v[j].se),++j);
                v2.pb(mp(v[i].fi,R));
            }
            v2.pb(mp(n,n));
            tmp = pl[0];
            rep(i,1,sz(v2)){
                int L = v2[i-1].se+1 , R = v2[i].fi-1;
                if(L<=R) Query(rt[P],0,n-1,L,R,0);
            }
            if(type == 1) ans = tmp.Min == inf ? -1 : tmp.Sum;
            if(type == 2) ans = tmp.Min == inf ? -1 : tmp.Min;
            if(type == 3) ans = tmp.Max == -inf ? -1 : tmp.Max;
            printf("%d\n",ans);
            if(ans == -1) ans = 0;
        }
    }
    return 0;
}
