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

const int N = 5005;
const ll inf = 1e18;
int n , l[N] , r[N];
ll dp[2][N][2];
inline void Update(ll &x,ll d) {
  if(x > d) x = d;
}

int main(){
  cin >> n;
  rep(i,0,n) cin >> l[i] >> r[i];
  vector<pair<ll,int> > seg;
  rep(i,0,n) seg.pb(mp(l[i] + r[i] , i));
  sort(all(seg));
  reverse(all(seg));
  rep(i,0,2) rep(j,0,N) rep(k,0,2) dp[i][j][k] = inf;
  auto f = dp[0] , g = dp[1];
  f[0][0] = 0;
  int goleft = n / 2 , goright = n - 1 - goleft;
  rep(i,0,n) {
    int s = seg[i].se;
    rep(j,0,i+2) rep(k,0,2) g[j][k] = inf;
    rep(j,0,i+1) {
      if(f[j][0] != inf) {
        Update(g[j][0] , f[j][0] + ll(l[s] + r[s]) * (i - j) + l[s]);
        Update(g[j+1][0] , f[j][0] + ll(l[s] + r[s]) * j + r[s]);
        Update(g[j][1] , f[j][0] + ll(goleft) * l[s] + ll(goright) * r[s]);
      }
      if(f[j][1] != inf) {
        Update(g[j][1] , f[j][1] + ll(l[s] + r[s]) * (i - 1 - j) + l[s]);
        Update(g[j+1][1] , f[j][1] + ll(l[s] + r[s]) * j + r[s]);
      }
    }
    swap(f , g);
  }
  cout << f[goleft][1] << endl;
  return 0;
}
