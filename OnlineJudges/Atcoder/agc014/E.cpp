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

const int N = 1e5 + 10;
vector<pii> q;
set<int> edge[N];
set<pii> inq;
int fa[N],n;
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
void add(int u,int v){
    auto it = edge[u].find(v);
    if(it == edge[u].end()) edge[u].insert(v);
    else {
        edge[u].erase(it);
        if(u>v) swap(u,v);
        if(!inq.count(mp(u,v)))
            inq.insert(mp(u,v)),q.pb(mp(u,v));
    }
}

int main(){
    scanf("%d",&n);
    rep(i,0,2) rep(j,1,n){
        int u,v;
        scanf("%d%d",&u,&v);
        --u;--v;
        add(u,v);
        add(v,u);
    }
    rep(i,0,n) fa[i]=i;
    rep(i,0,sz(q)){
        int u=F(q[i].fi),v=F(q[i].se);
        if(sz(edge[u])<sz(edge[v])) swap(u,v);
        fa[v]=u;
        for(auto w:edge[v]) {
            edge[w].erase(v);
            add(u,w);
            add(w,u);
        }
        edge[v].clear();
    }
    puts(sz(q) + 1 == n ? "YES" : "NO");
    return 0;
}
