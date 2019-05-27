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
int n , m , col[N];
vi g[N];

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,m) {
    int u,v;scanf("%d%d",&u,&v);
    --u;--v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int isolate = 0 , bipart = 0 , nonbipart = 0;
  rep(i,0,n) col[i]=-1;
  rep(i,0,n) if(col[i]==-1) {
    vi v;v.pb(i);col[i]=0;
    bool oddloop = false;
    rep(ii,0,sz(v)) {
      int c=v[ii];
      for(auto t : g[c]) {
        if(col[t]==-1) col[t]=col[c]^1,v.pb(t);
        else if(col[c]==col[t]) oddloop = true;
      }
    }
    if(sz(v)==1) isolate++;
    else (oddloop?nonbipart:bipart)++;
  }
  printf("%lld\n",ll(isolate)*isolate+2ll*isolate*(n-isolate)
      +ll(bipart+nonbipart)*(bipart+nonbipart)+ll(bipart)*bipart);
  return 0;
}
