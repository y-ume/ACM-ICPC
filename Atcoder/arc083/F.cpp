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

const int N = 2e5 + 10 , P = 1e9 + 7;
int n , vis[N] , fac[N] = {1} , ifac[N] , du[N] , root[N];
vi g[N] , G[N];
void output(vi v){
    rep(i,0,sz(v)) printf("%d%c",v[i]," \n"[i+1==sz(v)]);
}

int inverse(int x){return x == 1 ? 1 : P - ll(P/x)*inverse(P%x)%P;}

void dfs(int c,int fa){
    for(auto e : g[c]) if(e < fa) G[c].pb(e) , root[e] = false;
    for(auto e : g[c]) if(du[e] == 1 && e != fa) dfs(e , c);
}

pii solve(int c,int fa){
    pii res=mp(1,0);
    for(auto e : G[c]) if(e != fa){
        pii get=solve(e,c);
        res.se+=get.se;
        res.fi=1ll*res.fi*get.fi%P*ifac[get.se]%P;
    }
    res.fi=1ll*res.fi*fac[res.se]%P;
    res.se+=1;
    return res;
}

int solve(vi cir,vi all){
    for(auto e : all) G[e].clear() , root[e] = true;
    int rt = N - 1;G[rt].clear();
    cir.pb(cir[0]);
    rep(i,1,sz(cir)) dfs(cir[i] , cir[i-1]);
    for(auto e : all) if(root[e]) G[rt].pb(e);
    return solve(rt , -1).fi;
}

int main(){
    scanf("%d",&n);
    rep(i,1,(n<<1)+1) fac[i] = 1ll * fac[i - 1] * i % P;
    ifac[n<<1] = inverse(fac[n<<1]);
    per(i,0,(n<<1)) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    rep(i,0,n<<1){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        g[x << 1].pb(y << 1 | 1);
        g[y << 1 | 1].pb(x << 1);
    }
    int ans = fac[n<<1];
    rep(i,0,n<<1) if(!vis[i]){
        vi q;q.pb(i);vis[i]=1;
        rep(i,0,sz(q)) for(auto e : g[q[i]]) if(!vis[e])
            q.pb(e) , vis[e]=1;
        vi noncir,cir;int edgecnt(0);
        rep(i,0,sz(q)) {
            int c=q[i];
            edgecnt+=sz(g[c]);
            du[c] = sz(g[c]);
            if(sz(g[c]) == 1) noncir.pb(c);
        }
        if(edgecnt / 2 != sz(q)) {
            ans = 0;
            break;
        }
        rep(i,0,sz(noncir)){
            int c=noncir[i];
            for(auto e : g[c]) if(du[e] != 1 && (--du[e]) == 1)
                noncir.pb(e);
        }
        rep(i,0,sz(q)) if(du[q[i]] == 2){
            for(int c=q[i],t=-1;c!=-1;c=t){
                cir.pb(c);du[c]=0;t=-1;
                for(auto e : g[c]) if(du[e] == 2) t=e;
            }
        }
        int way = solve(cir , q);
        reverse(all(cir));
        (way += solve(cir , q)) %= P;
        ans = 1ll * ans * way % P * ifac[sz(q)] % P;
    }
    printf("%d\n",ans);
    return 0;
}
