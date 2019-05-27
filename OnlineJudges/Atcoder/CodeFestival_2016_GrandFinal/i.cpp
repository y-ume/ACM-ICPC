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
int n , a[N];

vector<pii> solve(vi&degs) {
  int n = sz(degs);
  vector<pii> res(n);
  if(n == 4) {
    res[0] = mp(0 , 0);
    res[1] = mp(1 , 0);
    res[2] = mp(1 , 1);
    res[3] = mp(0 , 1);
  } else {
    int s = 0;
    rep(i,0,n) if(degs[i] == 90 && degs[(i+1)%n] == 270) {
      s = (i + n - 1) % n;
      break;
    }
    vi ndegs(n - 2);
    int tot = 0;
    ndegs[tot++] = degs[s];
    rep(i,3,n) ndegs[tot++] = degs[(s+i)%n];
    vector<pii> pts = solve(ndegs);
    while(!(pts[0].fi < pts[1].fi && pts[0].se == pts[1].se))
      for(auto&p : pts) p = mp(p.se , -p.fi);
    for(auto&p : pts) p = mp(p.fi * 2 , p.se * 2);
    pts[1].se++;
    pts.insert(pts.begin() + 1 , mp(pts[0].fi + 1 , pts[0].se + 1));
    pts.insert(pts.begin() + 1 , mp(pts[0].fi + 1 , pts[0].se));
    vi X , Y;
    for(auto&p : pts) X.pb(p.fi) , Y.pb(p.se);
    sort(all(X));X.erase(unique(all(X)),X.end());
    sort(all(Y));Y.erase(unique(all(Y)),Y.end());
    for(auto&p : pts) p = mp(lower_bound(all(X),p.fi)-X.begin() ,
        lower_bound(all(Y),p.se)-Y.begin());
    rep(i,0,n) res[(i+s)%n] = pts[i];
  }
  return res;
}

int main(){
  cin >> n;
  int deg = 0;
  rep(i,0,n) {
    cin >> a[i];
    deg += 180 - a[i];
  }
  if(deg != 360) {
    cout << -1 << endl;
    return 0;
  }
  vi degs;
  rep(i,0,n) degs.pb(a[i]);
  vector<pii> pts = solve(degs);
  for(auto p : pts)
    cout << p.fi << " " << p.se << endl;
  return 0;
}
