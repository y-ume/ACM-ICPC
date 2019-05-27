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
int n , du[N] , ans;
vi g[N];

int dfs(int c,int fa=0) {
  int a = 0 , b = 0;
  for(auto t : g[c]) if(t != fa) {
    int gt = dfs(t , c);
    if(gt > a) swap(a , b) , a = gt;
    else if(gt > b) b = gt;
  }
  if(du[c] == 2) ans = max(ans , ++a);
  else ans = max(ans , a + b);
  return a;
}

int main(){
  scanf("%d",&n);
  rep(i,1,n) {
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].pb(v);
    g[v].pb(u);
    du[u]++;
    du[v]++;
  }
  int t = max_element(du + 1 , du + 1 + n) - du;
  if(du[t] <= 2) return printf("%d\n",n) , 0;
  dfs(t);
  rep(i,1,n+1) ans += du[i] == 1;
  printf("%d\n",ans);
  return 0;
}
