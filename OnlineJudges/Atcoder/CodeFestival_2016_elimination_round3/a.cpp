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
const ll inf = 1e18;
int m , n , K , a[N];
ll f[N] , g[N];
pair<ll,int> dp[N];

int main(){
  scanf("%d%d%d",&n,&m,&K);
  rep(i,1,n+1) scanf("%d",a+i);
  rep(i,1,n+1) f[i] = a[i];
  rep(t,2,K+1) {
    int l = 0 , r = 0;
    rep(i,1,n+1) {
      while(l < r && i - dp[l].se > m)
        ++l;
      g[i] = l != r ? dp[l].fi + ll(t) * a[i] : -inf;
      if(f[i] != -inf) {
        while(l < r && f[i] >= dp[r - 1].fi)
          --r;
        dp[r++] = mp(f[i] , i);
      }
    }
    rep(i,1,n+1) f[i] = g[i];
  }
  printf("%lld\n",*max_element(f+1,f+1+n));
  return 0;
}
