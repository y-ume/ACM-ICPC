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

const int N = 1e5 + 10;
int n , x[N] , y[N];

void check(bool ok) {
  if(!ok) {
    puts("-1");
    exit(0);
  }
}

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%d%d",x+i,y+i);
  check(x[0] == 0 && y[1] == 0 && x[1] > 0 && x[1] == y[0]);
  rep(i,2,n) check(x[i] > 0 && y[i] > 0);
  map<pii,int> S;
  rep(i,0,n) S[mp(x[i],y[i])]++;
  rep(i,0,n) {
    if(x[i]) check(S.count(mp(x[i]-1,y[i]-1))||S.count(mp(x[i]-1,y[i]))||S.count(mp(x[i]-1,y[i]+1)));
    if(y[i]) check(S.count(mp(x[i]-1,y[i]-1))||S.count(mp(x[i],y[i]-1))||S.count(mp(x[i]+1,y[i]-1)));
  }
  int res = 2 * n - 2;
  vector<pair<pii,int> > pts;
  for(auto e : S) pts.pb(e);
  sort(all(pts),[&](pair<pii,int> a,pair<pii,int> b){
      int sa=a.fi.fi+a.fi.se;
      int sb=b.fi.fi+b.fi.se;
      if(sa!=sb) return sa < sb;
      return a.fi.fi < b.fi.fi;
      });
  int remain = 0;
  rep(i,0,sz(pts)) {
    int x , y , cnt;
    tie(x , y) = pts[i].fi;
    cnt = pts[i].se;
    int match = min(remain , cnt);
    res -= match;
    if(S.count(mp(x - 1 , y - 1))) {
      int link = cnt - match;
      res -= link;
      cnt -= link;
    }
    if(i + 1 < sz(pts) && x + 1 == pts[i+1].fi.fi && y - 1 == pts[i+1].fi.se)
      remain = cnt;
    else
      remain = 0;
  }
  printf("%d\n",res);
  return 0;
}
