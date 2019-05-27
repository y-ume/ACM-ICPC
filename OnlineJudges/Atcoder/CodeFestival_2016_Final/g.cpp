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

const int N = 2e5 + 10 , inf = 2e9 + 10;
int n , Q , mn[N] , fa[N];
vector<pair<int,pii> > edge;
int F(int x) {return fa[x] == x ? x : fa[x] = F(fa[x]);}

int main() {
  scanf("%d%d",&n,&Q);
  rep(i,0,n) mn[i] = inf;
  rep(i,0,Q) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    edge.pb(mp(c,mp(a,b)));
    mn[a] = min(mn[a] , c + 1);
    mn[b] = min(mn[b] , c + 2);
  }
  rep(t,0,2) rep(i,0,n)
    mn[i] = min(mn[i] , mn[(i+n-1)%n] + 2);
  rep(i,0,n)
    edge.pb(mp(mn[i] , mp(i , (i+1)%n)));
  rep(i,0,n) fa[i] = i;
  sort(all(edge));
  ll ans = 0;
  for(auto e : edge) {
    int a = F(e.se.fi);
    int b = F(e.se.se);
    if(a != b) {
      fa[b] = a;
      ans += e.fi;
    }
  }
  printf("%lld\n",ans);
  return 0;
}

