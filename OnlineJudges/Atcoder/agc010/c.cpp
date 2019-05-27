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
int n , a[N] , ok;
vi g[N];

int dfs(int c,int fa) {
  int sum = sz(g[c]) == 1 ? a[c] : a[c] * 2;
  int mx = 0;
  for(auto t : g[c]) if(t != fa) {
    int gt = dfs(t , c);
    sum -= gt;
    mx = max(mx , gt);
  }
  if(sz(g[c]) != 1) {
    ok &= mx <= a[c] && sum <= a[c] && sum >= 0;
  }
  return sum;
}

int main(){
  cin >> n;
  rep(i,1,n+1) cin >> a[i];
  rep(i,1,n) {
    int u,v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  ok = 1;
  int t = dfs(1 , -1);
  ok &= t == 0;
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
