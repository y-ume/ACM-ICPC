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

const int N = 1e4 + 10;
int n , x[N] , y[N];
vector<pii> order;
vi pos[N];

struct TwoSat {
  static const int N = 1e5 + 10;
  int dfn[N],low[N],id[N],st[N],_st,_,cc,n,mark[N];
  vi g[N];
  void ini(int tot) {
    n = tot * 2;
    rep(i,0,tot) g[i<<1].clear(),g[i<<1|1].clear();
  }
  void addedge(int u,int v,int pu,int pv) {
    u=u<<1|pu,v=v<<1|pv;
    g[u].pb(v);g[v^1].pb(u^1);
  }
  void dfs(int c,vi g[]){
    dfn[c]=low[c]=++cc;
    st[_st++]=c;
    for(auto t:g[c])
      if(!dfn[t])
        dfs(t,g),low[c]=min(low[c],low[t]);
      else if(!id[t])
        low[c]=min(low[c],dfn[t]);
    if(low[c]==dfn[c]){
      ++_;
      do{id[st[--_st]]=_;}while(st[_st]!=c);
    }
  }
  bool solve(){
    fill_n(dfn,n,cc=0);
    fill_n(low,n,_st=0);
    fill_n(id,n,_=0);
    rep(i,0,n) if(!dfn[i]) dfs(i,g);
    for(int i=0;i<n;i+=2)
      if(id[i]==id[i+1]) return false;
      //else mark[i>>1]=id[i]>id[i+1];
    return true;
  }
}sat;

void addedge(int u,int v,int pu,int pv) {
  sat.addedge(u,v,pu,pv);
}
int id(int l,int r) {return (l+r)|(l!=r);}
void build(int l,int r,int fa) {
  int c = id(l , r);
  if(fa) addedge(c , fa , 1 , 1);
  if(l != r) {
    int mid = (l + r) >> 1;
    build(l , mid , c);
    build(mid + 1 , r , c);
  }
}
void build(int l,int r,int L,int R,int p) {
  int c = id(l , r);
  if(L <= l && r <= R) {
    addedge(p , c , 1 , 0);
  } else {
    int mid = (l + r) >> 1;
    if(L <= mid) build(l , mid , L , R , p);
    if(R > mid) build(mid + 1 , r , L , R , p);
  }
}
bool check(int lim) {
  sat.ini(2 * sz(order));
  build(0 , sz(order) , -1);
  rep(i,0,n) {
    addedge(pos[i][0] << 1 , pos[i][1] << 1 , 1 , 0);
    addedge(pos[i][0] << 1 , pos[i][1] << 1 , 0 , 1);
  }
  for(int i=0,l=0,r=0;i<sz(order);++i) {
    while(r<sz(order)&&order[r].fi-order[i].fi<lim)
      r++;
    while(l<r&&order[i].fi-order[l].fi>=lim)
      l++;
    if(l < i) build(0 , sz(order) , l , i - 1 , i + i);
    if(i < r - 1) build(0 , sz(order) , i + 1 , r - 1 , i + i);
  }
  return sat.solve();
}

int main(){
  cin >> n;
  rep(i,0,n) {
    cin >> x[i] >> y[i];
    order.pb(mp(x[i] , i));
    order.pb(mp(y[i] , i));
  }
  sort(all(order));
  rep(i,0,sz(order)) pos[order[i].se].pb(i);
  int l = 0 , r = 1e9;
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    (check(mid) ? l : r) = mid;
  }
  cout << l << endl;
  return 0;
}
