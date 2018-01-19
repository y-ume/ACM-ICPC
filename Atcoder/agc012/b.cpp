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
int n , m , f[N] , g[N];
int Q , v[N] , d[N] , c[N];
vi G[N];

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,m) {
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].pb(v);
    G[v].pb(u);
  }
  scanf("%d",&Q);
  rep(i,1,Q+1) scanf("%d%d%d",v+i,d+i,c+i);
  per(step,0,11) {
    rep(i,1,n+1) g[i]=f[i];
    rep(i,1,n+1) for(auto j:G[i])
      g[j]=max(g[j],f[i]);
    rep(i,1,Q+1) if(d[i]==step)
      g[v[i]]=max(g[v[i]],i);
    rep(i,1,n+1) f[i]=g[i];
  }
  rep(i,1,n+1) printf("%d\n",c[f[i]]);
  return 0;
}
