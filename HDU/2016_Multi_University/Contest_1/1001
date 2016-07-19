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
int T , n , m;
vector<pair<int,pii> > V;
int fa[N] , _;
vector<pii> g[N];
ll ans1;db ans2;
int F(int x){return fa[x] == x ? x : fa[x] = F(fa[x]);}
bool M(int a,int b){a = F(a) , b = F(b);if(a != b){fa[b] = a;return true;}return false;}
void link(int a,int b,int w){
    g[a].pb(mp(b,w));
    g[b].pb(mp(a,w));
}
int sz[N];
void dfs(int c,int pa){
    sz[c] = 1;
    for(auto t : g[c]) if(t.fi != pa){
        dfs(t.fi , c);
        ans2 += (db)t.se * sz[t.fi] * (n - sz[t.fi]);
        sz[c] += sz[t.fi];
    }
}

int main(){
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d%d",&n,&m);
        int u , v , w;
        ans1 = ans2 = 0;
        rep(i,0,m) scanf("%d%d%d",&u,&v,&w) , --u,--v,V.pb(mp(w,mp(u,v)));
        sort(all(V));
        rep(i,0,n) fa[i] = i; _ = n;
        rep(i,0,sz(V)){
            if(M(V[i].se.fi , V[i].se.se)){
                _--;
                link(V[i].se.fi , V[i].se.se , V[i].fi);
                ans1 += V[i].fi;
            }
            if(_ == 1) break;
        }
        dfs(0,0);
        printf("%I64d %.2lf\n",ans1,db(ans2) / ((ll)n*(n-1)/2) + 1e-6);
        rep(i,0,n) g[i].clear();
        V.clear();
    }
    return 0;
}
