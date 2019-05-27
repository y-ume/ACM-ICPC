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

const int N = 5050 , P = 1e9 + 7;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
int n , fac[N] , ifac[N];
vi g[N];
int sz[N] , mx[N];

int comb(int a,int b) {return ll(fac[a]) * ifac[b] % P * ifac[a-b] % P;}

void dfs(int c,int fa) {
  sz[c] = 1;
  mx[c] = 0;
  for(auto t : g[c]) if(t != fa) {
    dfs(t , c);
    mx[c] = max(mx[c] , sz[t]);
    sz[c] += sz[t];
  }
  mx[c] = max(mx[c] , n - sz[c]);
}

int main(){
  rep(i,0,N) fac[i] = i ? ll(fac[i-1]) * i % P : 1;
  rep(i,0,N) ifac[i] = i > 1 ? P - ll(P/i)*ifac[P%i]%P : 1;
  rep(i,1,N) ifac[i] = ll(ifac[i-1]) * ifac[i] % P;
  cin >> n;
  rep(i,1,n) {
    int x,y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(1 , 0);
  vi centroid;
  rep(i,1,n+1) if(mx[i] <= n / 2)
    centroid.pb(i);
  if(sz(centroid) == 2) {
    cout << ll(fac[n / 2]) * fac[n / 2] % P << endl;
  } else {
    int rt = centroid[0];
    dfs(rt , 0);
    vi v , f(n , 0);
    f[0] = 1;
    for(auto t : g[rt]) {
      int sz = ::sz[t];
      vi g(n , 0);
      rep(i,0,n) if(f[i]) {
        rep(j,0,sz+1) {
          pp(g[i + j] , ll(f[i]) * comb(sz , j) % P * comb(sz , j) % P * fac[j] % P);
        }
      }
      swap(f , g);
    }
    int ans = 0;
    rep(i,0,n) {
      int cof = ll(f[i]) * fac[n - i] % P;
      if(i & 1) pp(ans , P - cof);
      else pp(ans , cof);
    }
    cout << ans << endl;
  }
  return 0;
}
