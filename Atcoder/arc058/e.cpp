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

const int N = 5 + 7 + 5 , P = 1e9 + 7 , M = 100;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
int n , x , y , z , m;
int f[1 << N] , g[1 << N] , nxt[11][1 << N] , pw10[M];

int main(){
  rep(i,0,M) pw10[i]=i?10ll*pw10[i-1]%P:1;
  cin >> n >> x >> y >> z;
  m = x + y + z;
  rep(i,1,11) {
    rep(j,0,x) nxt[i][1<<j]=j+i<=x?(1<<(j+i)):0;
    rep(j,x,x+y) nxt[i][1<<j]=j+i<=x+y?(1<<(j+i)):0;
    rep(j,x+y,x+y+z) nxt[i][1<<j]=j+i<=x+y+z?(1<<(j+i)):0;
    rep(j,0,m) rep(k,0,1<<j) nxt[i][k|(1<<j)]|=nxt[i][k]|nxt[i][1<<j];
  }
  f[1] = 1;
  int ans = 0;
  rep(i,0,n) {
    rep(j,0,1<<m) g[j]=0;
    rep(j,0,1<<m) if(f[j]) rep(k,1,11){
      int t=nxt[k][j] | 1;
      if(t>>m&1) pp(ans,ll(f[j])*pw10[n-1-i]%P);
      else pp(g[t],f[j]);
    }
    rep(j,0,1<<m) f[j]=g[j];
  }
  cout << ans << endl;
  return 0;
}
