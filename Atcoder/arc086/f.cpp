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

const int P = 1e9 + 7;
inline void pp(int &x,int d) {
  if((x+=d)>=P) x-=P;
}

int main(){
  ll n , K;
  cin >> n >> K;
  vector<ll> a(n);
  rep(i,0,n) cin >> a[i];
  sort(all(a));
  map<vector<ll>,vector<pair<ll,ll> > > Mp;
  rep(d,0,61) {
    vector<ll> r;
    r.pb(0);r.pb(1ll<<d);
    rep(i,0,n) r.pb(a[i]%(1ll<<d)+1);
    sort(all(r));
    r.erase(unique(all(r)),r.end());
    rep(i,0,sz(r)-1) {
      ll from = r[i] , to = min(a[0] , r[i + 1] - 1);
      if(from > a[0])
        break;
      ll cost = d;
      per(d,0,61) {
        if((from >> d & 1) == (to >> d & 1))
          cost += from >> d & 1;
        else {
          if(from & ((1ll<<d)-1))
            cost++;
          break;
        }
      }
      ll remain = K - cost;
      if(remain >= 0) {
        vector<ll> na = a;
        for(auto&e:na) e = (e - from) >> d;
        vector<ll> dif(n - 1);
        ll del = min(na[0] , remain);
        rep(i,0,n-1) dif[i] = na[i + 1] - na[i];
        Mp[dif].pb(mp(na[0] - del , na[0]));
      }
    }
  }
  int ans = 0;
  for(auto e : Mp) {
    auto&v = e.se;
    sort(all(v));
    pair<ll,ll> last = v[0];
    rep(i,0,sz(v)) {
      if(v[i].fi <= last.se)
        last.se = max(last.se , v[i].se);
      else pp(ans , (last.se - last.fi + 1) % P) , last = v[i];
    }
    pp(ans , (last.se - last.fi + 1) % P);
  }
  cout << ans << endl;
  return 0;
}
