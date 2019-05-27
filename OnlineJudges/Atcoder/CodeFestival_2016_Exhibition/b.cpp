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

const int N = 20002;
int n;
ll a[N];

int main(){
  cin >> n;
  rep(i,0,n) cin >> a[i];
  ll s = 0;
  rep(i,0,n) s += a[i];
  int ans = 0;
  for(ll base=1;s/base>=1;base*=10) {
    per(i,1,10) {
      vector<pair<ll,ll> > segs;
      segs.pb(mp(base*i,base*(i+1)-1));
      ll range = base * 10;
      bool zero = false;
      rep(i,0,n) {
        auto nsegs = segs;
        ll t = a[i] % range;
        for(auto e : segs) {
          ll l = e.fi , r = e.se;
          l -= t;
          r -= t;
          if(l < 0) l += range;
          if(r < 0) r += range;
          if(l <= r) nsegs.pb(mp(l , r));
          else {
            nsegs.pb(mp(0 , r));
            nsegs.pb(mp(l , range - 1));
          }
        }
        sort(all(nsegs));
        segs.clear();
        pair<ll,ll> pre = nsegs[0];
        rep(i,1,sz(nsegs)) {
          if(nsegs[i].fi <= pre.se)
            pre.se = max(pre.se , nsegs[i].se);
          else
            segs.pb(pre) , pre = nsegs[i];
        }
        segs.pb(pre);
        for(auto e : segs) zero |= e.fi == 0;
        if(zero) break;
      }
      if(zero) {
        ans += i;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
