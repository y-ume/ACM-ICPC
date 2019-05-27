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

int A , B , d[20][20] , mn[20][20];

int main(){
  cin >> A >> B;
  rep(i,1,A+1) rep(j,1,B+1)
    cin >> d[i][j];
  rep(i,1,A+1) rep(j,1,B+1)
    mn[i][j] = d[i][j] + 1;
  vi X , Y;
  int _ = 0;
  rep(i,0,101) X.pb(++_) , Y.pb(++_);
  vector<pair<pii,int> > edge;
  rep(i,1,sz(X)) edge.pb(mp(mp(X[i - 1] , X[i]) , -1));
  rep(i,1,sz(Y)) edge.pb(mp(mp(Y[i] , Y[i - 1]) , -2));
  rep(i,0,sz(X)) rep(j,0,sz(Y)) {
    int add = 0;
    rep(x,1,A+1) rep(y,1,B+1) {
      int cost = i * x + j * y;
      if(cost < d[x][y])
        add = max(add , d[x][y] - cost);
    }
    edge.pb(mp(mp(X[i] , Y[j]) , add));
    rep(x,1,A+1) rep(y,1,B+1) {
      mn[x][y] = min(mn[x][y] , i * x + j * y + add);
    }
  }
  bool ok = true;
  rep(i,1,A+1) rep(j,1,B+1) ok &= mn[i][j] == d[i][j];
  if(!ok) cout << "Impossible" << endl;
  else {
    cout << "Possible" << endl;
    cout << sz(X) + sz(Y) << " " << sz(edge) << endl;
    for(auto e : edge) {
      cout << e.fi.fi << " " << e.fi.se << " ";
      if(e.se == -1) cout << "X" << endl;
      else if(e.se == -2) cout << "Y" << endl;
      else cout << e.se << endl;
    }
    cout << X[0] << " " << Y[0] << endl;
  }
  return 0;
}
