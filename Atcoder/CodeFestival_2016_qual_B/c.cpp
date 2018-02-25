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

int W , H;

int main(){
  cin >> W >> H;
  vector<pii> lines;
  int p , q;
  rep(i,0,W) {
    cin >> p;
    lines.pb(mp(p , 0));
  }
  rep(i,0,H) {
    cin >> q;
    lines.pb(mp(q , 1));
  }
  sort(all(lines));
  int w = W + 1 , h = H + 1;
  ll ans = 0;
  for(auto l : lines) {
    if(l.se == 0) ans += ll(l.fi) * h , --w;
    else ans += ll(l.fi) * w , --h;
  }
  cout << ans << endl;
  return 0;
}
