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

const int N = 2020;
int n , K , u[N] , v[N];
vi g[N];

void dfs(int c,int fa,int K,int &cnt) {
  cnt++;
  if(K == 0) return;
  for(auto t : g[c]) if(t != fa) {
    dfs(t , c , K - 1 , cnt);
  }
}

int main(){
  cin >> n >> K;
  rep(i,1,n) {
    int u,v;
    cin >> u >> v;
    ::u[i] = u;
    ::v[i] = v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int ans = n;
  if(K & 1) {
    rep(i,1,n) {
      int cnt = 0;
      dfs(u[i] , v[i] , K >> 1 , cnt);
      dfs(v[i] , u[i] , K >> 1 , cnt);
      ans = min(ans , n - cnt);
    }
  } else {
    rep(i,1,n+1) {
      int cnt = 0;
      dfs(i , 0 , K >> 1 , cnt);
      ans = min(ans , n - cnt);
    }
  }
  cout << ans << endl;
  return 0;
}
