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
int n , m , vis[N] , dis[N];
vector<pii> g[N];

void dfs(int c) {
  vis[c] = true;
  for(auto e : g[c]) {
    int t = e.fi;
    if(vis[t]) {
      if(dis[t] != dis[c] + e.se) {
        puts("No");
        exit(0);
      }
    } else {
      dis[t] = dis[c] + e.se;
      dfs(t);
    }
  }
}

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,m) {
    int l , r , d;
    scanf("%d%d%d",&l,&r,&d);
    g[l].pb(mp(r,d));
    g[r].pb(mp(l,-d));
  }
  rep(i,1,n+1) if(!vis[i])
    dfs(i);
  puts("Yes");
  return 0;
}
