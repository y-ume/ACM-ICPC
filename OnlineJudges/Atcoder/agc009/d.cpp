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
int n;
vi g[N];

int dfs(int c,int fa) {
  vi f;
  for(auto t : g[c]) if(t != fa)
    f.pb(dfs(t , c));
  f.pb(1);
  int res = 0;
  for(int i=0,d=0,j=0;i<20;++i) {
    int s = d;
    for(auto e : f)
      s += e >> i & 1;
    if(s == 1) {
      res |= 1 << i;
      if(d == 1) {
        rep(k,j,i) if(res >> k & 1)
          res ^= 1 << k;
        j = i;
      }
    }
    if(s >= 2)
      d = 1;
    else
      d = 0;
  }
  return res;
}

int main(){
  scanf("%d",&n);
  rep(i,1,n) {
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].pb(v);
    g[v].pb(u);
  }
  printf("%d\n",31-__builtin_clz(dfs(1,0)));
  return 0;
}
