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


const int N = 1010;
int T , n , x[N] , y[N];

ll cal(ll a,ll b,ll c,ll n) { // sum_{i=0...n-1}cell((a*i+b)/c)
  if(n == 0) return 0;
  return (b/c)*n+(a/c)*n*(n-1)/2+(a%c?cal(c,(a*n+b)%c,a%c,(a%c*n+b%c)/c):0);
}

int main() {
  scanf("%d",&T);
  rep(i,1,T+1) {
    scanf("%d",&n);
    rep(i,0,n) scanf("%d%d",x + i,y + i) , swap(x[i] , y[i]);
    bool ok = true;
    pair<ll,ll> lo(0,1), hi(1,0);
    auto bigger = [&](pair<ll,ll> x,pair<ll,ll> y) {
      return x.fi * y.se > x.se * y.fi;
    };
    rep(i,0,n) rep(j,i+1,n) {
      int dx = x[j] - x[i];
      int dy = y[j] - y[i];
      // dx * a + dy * b > 0
      if(dx == 0) {
        if(dy < 0) {
          ok = false;
        }
      } else if(dx > 0){
        if(dy < 0) {
          // a > -dy * b / dx
          ll g = __gcd(-dy , dx);
          dy = -dy / g;
          dx = dx / g;
          if(bigger(mp(dy , dx) , lo))
            lo = mp(dy , dx);
        }
      } else if(dx < 0){
        if(dy <= 0) {
          ok = false;
        } else {
          // a < -dy * b / dx
          ll g = __gcd(-dx , dy);
          dy = dy / g;
          dx = -dx / g;
          if(bigger(hi , mp(dy , dx)))
            hi = mp(dy , dx);
        }
      }
    }
    ok &= bigger(hi , lo);
   //de(lo.fi);de(lo.se);
    //de(hi.fi);de(hi.se);
    if(!ok) {
      printf("Case #%d: IMPOSSIBLE\n",i);
    } else {
      ll ansx = 0 , ansy = 0;
      if(hi == mp(1ll , 0ll)) {
        ansy = 1;
        ll L = 0 , R = 2e9;
        while(L + 1 < R) {
          ll M = (L + R) >> 1;
          (bigger(mp(M , 1ll) , lo) ? R : L) = M;
        }
        ansx = R;
      } else {
        ll L = 0 , R = 2e9;
        while(L + 1 < R) {
          ll M = (L + R) >> 1;
          ll pts = cal(hi.fi , 0 , hi.se , M + 1) - cal(lo.fi , 0 , lo.se , M + 1);
          pts -= M / hi.se;
          if(pts > 0) R = M;
          else L = M;
        }
        ansy = R;
        L = 0 , R = 2e9;
        while(L + 1 < R) {
          ll M = (L + R) >> 1;
          pair<ll,ll> t = mp(M , ansy);
          (bigger(t , lo) ? R : L) = M;
        }
        ansx = R;
      }
      printf("Case #%d: %lld %lld\n",i,ansy,ansx);
    }
  }
  return 0;
}
