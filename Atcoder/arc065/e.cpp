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

#define right Right
typedef pair<ll,ll> pll;
const int N = 1e5 + 10 , M = 4;
int n , a , b;
ll x[N] , y[N];
int from[M][N] , to[M][N] , id[M][N] , rid[M][N] , fa[M][N] , vis[N];

void getGraph(int *from,int *to,int *id,int *rid,int *fa,ll D) {
  vector<pair<pll,int> > v(n);
  rep(i,0,n) v[i]=mp(mp(x[i],y[i]),i);
  sort(all(v));
  rep(i,0,n+1) fa[i] = i;
  rep(i,0,n) {
    ll x=v[i].fi.fi,y=v[i].fi.se;
    id[v[i].se]=i;
    rid[i]=v[i].se;
    int left=lower_bound(all(v),mp(mp(x+D,y-D),0))-v.begin();
    int right=lower_bound(all(v),mp(mp(x+D,y+D),0))-v.begin();
    from[i] = left , to[i] = right;
  }
  rid[n]=n;
}

int F(int x,int *fa,int *rid) {
  if(fa[x] == x) {
    if(!vis[rid[x]]) return x;
    return fa[x] = F(x + 1 , fa , rid);
  }
  return fa[x] = F(fa[x] , fa , rid);
}

int main(){
  scanf("%d%d%d",&n,&a,&b);
  --a;--b;
  rep(i,0,n) {
    scanf("%lld%lld",x+i,y+i);
    tie(x[i],y[i])=mp(x[i]-y[i],x[i]+y[i]);
  }
  ll D = max(abs(x[a]-x[b]),abs(y[a]-y[b]));
  rep(i,0,4) {
    getGraph(from[i] , to[i] , id[i] , rid[i] , fa[i] , D);
    rep(i,0,n) tie(x[i],y[i])=mp(y[i],-x[i]);
  }
  vi v;v.pb(a);vis[a]=true;
  ll ans = 0;
  rep(i,0,sz(v)) {
    int c = v[i];
    rep(d,0,4) {
      int *from=::from[d],*to=::to[d],*id=::id[d],*rid=::rid[d],*fa=::fa[d];
      int x = id[c];
      int l = from[x] , r = to[x];
      ans += r - l;
      while(l < r) {
        l = F(l , fa , rid);
        if(l < r) {
          vis[rid[l]] = true;
          v.pb(rid[l]);
        }
      }
    }
  }
  printf("%lld\n",ans / 2);
  return 0;
}

