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

const int N = 3030;
int n , a[N];
vi g[N];

bool dfs(int c,int fa){
  bool win = false;
  for(auto t : g[c]) if(t != fa) {
    win |= a[t] < a[c] && !dfs(t , c);
  }
  return win;
}

int main(){
  cin >> n;
  rep(i,1,n+1) cin >> a[i];
  rep(i,1,n) {
    int u , v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi ans;
  rep(i,1,n+1) if(dfs(i , 0))
    ans.pb(i);
  rep(i,0,sz(ans)) cout << ans[i] << " \n"[i+1==sz(ans)];
  return 0;
}
