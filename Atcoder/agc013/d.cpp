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

const int N = 3030 , P = 1e9 + 7;
int f[N][2] , g[N][2] , n , m;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,n+1) f[i][0] = 1;
  rep(i,0,m) {
    rep(i,0,n+1) rep(j,0,2) g[i][j] = 0;
    rep(i,0,n+1) rep(j,0,2) if(f[i][j]) {
      if(i) {
        pp(g[i][j||(i==1)] , f[i][j]);
        pp(g[i-1][j||(i==1)] , f[i][j]);
      }
      if(i!=n) {
        pp(g[i][j||(i==0)] , f[i][j]);
        pp(g[i+1][j||(i==0)] , f[i][j]);
      }
    }
    rep(i,0,n+1) rep(j,0,2) f[i][j] = g[i][j];
  }
  int ans=0;
  rep(i,0,n+1) pp(ans,f[i][1]);
  printf("%d\n",ans);
  return 0;
}
