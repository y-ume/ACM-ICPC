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

const int N = 2e5 + 10 , P = 1e9 + 7;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
int n , par[N];
vi g[N];
struct Dp{
  int a[3];
  Dp() {memset(a,0,sizeof(a));}
};
vector<Dp> dp[N];

int main(){
  scanf("%d",&n);
  rep(i,1,n+1) scanf("%d",par+i),g[par[i]].pb(i);
  int inv2 = P - P / 2;
  Dp uni;uni.a[0]=uni.a[1]=inv2;
  per(i,0,n+1) {
    if(sz(g[i])) {
      int longest = 0;
      per(j,1,sz(g[i])) {
        auto&x=dp[g[i][j-1]],&y=dp[g[i][j]];
        longest = max(longest , sz(y));
        if(sz(x) < sz(y))
          swap(x , y);
        auto merge = [&](Dp&x,Dp y) {
          Dp r;
          rep(i,0,3) rep(j,0,3)
            pp(r.a[min(i+j,2)],ll(x.a[i])*y.a[j]%P);
          x=r;
        };
        rep(i,0,sz(y)) merge(x[sz(x)-(sz(y)-i)],y[i]);
        y.clear();
      }
      swap(dp[i],dp[g[i][0]]);
      rep(j,0,longest) {
        Dp&f=dp[i][sz(dp[i])-1-j];
        pp(f.a[0],f.a[2]);
        f.a[2]=0;
      }
    }
    dp[i].pb(uni);
  }
  int ans = 0;
  for(auto e : dp[0]) pp(ans,e.a[1]);
  rep(i,0,n+1) pp(ans,ans);
  printf("%d\n",ans);
  return 0;
}
