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
#define de(x) cout << #x << "=" << (x) << endl
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
const ll inf = 1e18;
struct Segment {
  int n;
  pair<ll,int> mn[N << 2];
  ll add[N << 2];
  void Add(int c,int l,int r,int L,int R,ll x) {
    if(L <= l && r <= R) {
      add[c] += x;
      mn[c].fi += x;
    } else {
      int m = (l + r) >> 1;
      if(L <= m) Add(c << 1 , l , m , L , R , x);
      if(R > m) Add(c << 1 | 1 , m + 1 , r , L , R , x);
      mn[c] = min(mn[c << 1] , mn[c << 1 | 1]);
      mn[c].fi += add[c];
    }
  }
  pair<ll,int> Query(int c,int l,int r,int L,int R) {
    if(L <= l && r <= R) {
      return mn[c];
    } else {
      int m = (l + r) >> 1;
      pair<ll,int> res(inf,-1);
      if(L <= m) res = min(res , Query(c << 1 , l , m , L , R));
      if(R > m) res = min(res , Query(c << 1 | 1 , m + 1 , r , L , R));
      res.fi += add[c];
      return res;
    }
  }
  void Build(int c,int l,int r) {
    add[c] = 0;
    if(l == r) {
      mn[c] = mp(0 , l);
    } else {
      int m = (l + r) >> 1;
      Build(c << 1 , l , m);
      Build(c << 1 | 1 , m + 1 , r);
      mn[c] = min(mn[c << 1] , mn[c << 1 | 1]);
    }
  }
  void Add(int L,int R,ll x) {
    Add(1 , 0 , n - 1 , L , R , x);
  }
  pair<ll,int> Query(int L,int R) {
    return Query(1 , 0 , n - 1 , L , R);
  }
  void init(int _n) {
    n = _n;
    Build(1 , 0 , n - 1);
  }
};
Segment A , B;
int n;
ll a[N] , b[N];

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%lld",a+i);
  rep(i,0,n) scanf("%lld",b+i);
  A.init(n);
  B.init(n);
  ll del = 0;
  ll ans = 0;
  rep(i,0,n) {
    del += a[i] - b[i];
    ans += abs(del);
    A.Add(0 , i , del > 0 ? -1 : 1);
    B.Add(i , i , del > 0 ? del : inf);
  }
  while(del) {
    pair<ll,int> x = A.Query(0 , n - 1);
    pair<ll,int> y = B.Query(x.se , n - 1);
    ll way = min(del , y.fi);
    ans += x.fi * way;
    del -= way;
    B.Add(x.se , n - 1 , -way);
    for(int i = x.se;i < n;) {
      pair<ll,int> z = B.Query(i , n - 1);
      if(z.fi) break;
      A.Add(0 , z.se , 2);
      B.Add(z.se , z.se , inf);
      i = z.se + 1;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
