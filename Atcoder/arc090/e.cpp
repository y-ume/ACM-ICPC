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

const int N = 1e5 + 10 , P = 1e9 + 7;
inline void pp(int &x,int d) {if((x+=d)>=P) x-=P;}
inline int mul(int a,int b) {return ll(a)*b%P;}
int n , m , s , t;
vector<pii> g[N];

vector<pair<ll,int> > getdis(int s) {
  vector<pair<ll,int> > res(n , mp(1ll<<62 , 1));
  res[s] = mp(0 , 1);
  priority_queue<pair<ll,int> > Q;
  Q.push(mp(0 , s));
  while(sz(Q)) {
    ll d = -Q.top().fi;
    int c = Q.top().se;
    Q.pop();
    if(res[c].fi == d) {
      for(auto e : g[c]) {
        ll nd = d + e.se;
        int t = e.fi;
        if(nd < res[t].fi)
          res[t] = mp(nd , res[c].se) ,
            Q.push(mp(-res[t].fi , t));
        else if(nd == res[t].fi)
          pp(res[t].se , res[c].se);
      }
    }
  }
  return res;
}

int main(){
  scanf("%d%d",&n,&m);
  scanf("%d%d",&s,&t);
  --s;--t;
  rep(i,0,m) {
    int u , v , d;
    scanf("%d%d%d",&u,&v,&d);
    --u;--v;
    g[u].pb(mp(v,d));
    g[v].pb(mp(u,d));
  }
  vector<pair<ll,int> > fs(getdis(s)) , ft(getdis(t));
  ll mindis = fs[t].fi;
  int ans(mul(fs[t].se , fs[t].se));
  vi ok(n , 0);
  rep(i,0,n) ok[i] = fs[i].fi + ft[i].fi == mindis;
  rep(i,0,n) if(ok[i] && fs[i].fi * 2 == mindis)
    pp(ans , P - mul(mul(fs[i].se , fs[i].se) , mul(ft[i].se , ft[i].se)));
  rep(i,0,n) if(ok[i] && fs[i].fi < mindis / 2) {
    for(auto e : g[i]) {
      int j = e.fi;
      if(ok[j] && fs[i].fi + e.se == fs[j].fi && fs[j].fi > mindis / 2)
        pp(ans , P - mul(mul(fs[i].se , fs[i].se) , mul(ft[j].se , ft[j].se)));
    }
  }
  printf("%d\n",ans);
  return 0;
}
