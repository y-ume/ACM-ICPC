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

const int N = 1010 , P = 1e9 + 7;
int n;
vi g[N];

void dfs(int c,int fa,int dep,int &maxdep) {
  maxdep = max(maxdep , dep);
  for(auto t : g[c]) if(t != fa) {
    dfs(t , c , dep + 1 , maxdep);
  }
}

int f[N][N<<1];

void dp(int c,int fa,int dep,int maxdep,int p) {
  int r=maxdep-dep,l=-r;
  l+=p,r+=p;
  rep(i,l,r+1) f[c][i+N]=1;
  for(auto t : g[c]) if(t != fa) {
    dp(t , c , dep + 1 , maxdep , p);
    rep(i,l,r+1) f[c][i+N]=ll(f[c][i+N])*(f[t][i-1+N]+f[t][i+1+N])%P;
  }
}

vi solve(int rt,int fa,int maxdep,int p) {
  memset(f,0,sizeof(f));
  dp(rt , fa , 0 , maxdep , p);
  return vi(f[rt],f[rt]+N+N);
}

void solve(int u,int v,int maxu,int maxv,int pu,int pv,int sig,int &ans) {
  vi F = solve(u , v , maxu , pu);
  vi G = solve(v , u , maxv , pv);
  int l=-maxu+pu,r=maxu+pu;
  rep(i,l,r+1){
    ans=((ans+ll(F[i+N])*(G[i+1+N]+G[i-1+N])*sig%P)%P+P)%P;
  }
}


int main(){
  cin >> n;
  rep(i,1,n) {
    int u , v;
    cin >> u >> v;
    --u,--v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi dis(n , 0);
  rep(i,0,n) dfs(i , -1 , 0 , dis[i] = 0);
  int mindeep = *min_element(all(dis));
  vi center;
  rep(i,0,n) if(dis[i] == mindeep)
    center.pb(i);
  if(sz(center) == 1) {
    int rt = center[0];
    vi F = solve(rt , -1 , dis[rt] , 0);
    int ans=0;
    rep(i,-dis[rt],dis[rt]+1)
      (ans+=F[i+N])%=P;
    printf("%d\n",ans);
  } else {
    int u = center[0] , v = center[1];
    int ans = 0 , d = dis[u];
    solve(u , v , d - 1 , d , 0 , 0 , 1 , ans);
    solve(u , v , d , d - 1 , 0 , 0 , 1 , ans);
    solve(u , v , d - 1 , d - 1 , 0 , -1 , -1 , ans);
    solve(u , v , d - 1 , d - 1 , 0 , 1 , -1 , ans);
    printf("%d\n",ans);
  }
  return 0;
}
