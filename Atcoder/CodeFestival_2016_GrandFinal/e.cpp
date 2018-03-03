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

const int N = 15;
int n , x[N] , y[N] , a[N] , fa[N];
db f[1 << N] , dis[N][N];
inline int F(int x) {return fa[x] == x ? x : fa[x] = F(fa[x]);}

int main(){
  cin >> n;
  rep(i,0,n) cin >> x[i] >> y[i] >> a[i];
  rep(i,0,n) rep(j,0,n) {
    db dx = x[i] - x[j];
    db dy = y[i] - y[j];
    dis[i][j] = sqrt(dx*dx+dy*dy);
  }
  rep(i,0,1<<n) {
    if(i == 0) continue;
    vi pts;
    rep(j,0,n) if(i >> j & 1) pts.pb(j);
    vector<pair<db,pii> > edges;
    rep(i,0,sz(pts)) rep(j,0,i) {
      edges.pb(mp(dis[pts[i]][pts[j]] , mp(pts[i] , pts[j])));
    }
    sort(all(edges));
    for(int p : pts) fa[p] = p;
    db cost = 0.;
    for(auto e : edges) {
      int u = F(e.se.fi);
      int v = F(e.se.se);
      if(u != v) {
        fa[v] = u;
        cost += e.fi;
      }
    }
    db sum = 0;
    for(int p : pts) sum += a[p];
    f[i] = (sum - cost) / sz(pts);
  }
  rep(i,1,1<<n) {
    for(int j=i;j;j=(j-1)&i) {
      f[i] = max(f[i] , min(f[j] , f[i ^ j]));
    }
  }
  printf("%.12f\n",f[(1<<n)-1]);
  return 0;
}
