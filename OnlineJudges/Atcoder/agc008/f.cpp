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

const int N = 2e5 + 10;
char s[N];
int n , dep[2][N] , maxdep[N];
vi g[N];

void dfs(int c,int fa,int &id,int*dep) {
  dep[c] = fa ? dep[fa] + 1 : 0;
  if(dep[c] > dep[id]) id = c;
  for(auto t : g[c]) if(t != fa)
    dfs(t , c , id , dep);
}

int low[N] , high[N] , dis[N];
ll ans;

void dfs(int c,int fa){
  dis[c] = 0;
  for(auto t : g[c]) if(t != fa) {
    dfs(t , c);
    dis[c] = max(dis[c] , dis[t] + 1);
  }
  if(s[c] == '1') low[c] = 0;
  if(fa == 0) ans += max(0 , maxdep[c] - low[c] + 1);
  else {
    high[c] = dis[c] + 1;
    if(maxdep[c] == maxdep[fa]) {
      high[c] = dis[c];
      low[fa] = min(low[fa] , max(low[c] , high[c] + 1));
      ans += max(0 , high[c] - low[c] + 1);
    } else {
      low[fa] = min(low[fa] , max(low[c] - 1 , high[c]));
      ans += max(0 , high[c] - low[c] + 1);
    }
  }
}

int main(){
  scanf("%d",&n);
  rep(i,1,n) {
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].pb(v);
    g[v].pb(u);
  }
  scanf("%s",s+1);
  int u=0,v=0,w=0;
  dfs(1,0,u,dep[0]);
  dfs(u,0,v,dep[0]);
  dfs(v,0,w,dep[1]);
  rep(i,1,n+1) maxdep[i]=max(dep[0][i],dep[1][i]);
  rep(i,1,n+1) low[i]=1<<30;
  int rt = min_element(maxdep+1,maxdep+1+n)-maxdep;
  dfs(rt,0);
  printf("%lld\n",ans);
  return 0;
}
